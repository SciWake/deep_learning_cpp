#include <iostream>
#include <vector>
#include <cassert>

double WeightSum(const std::vector<double>& a, const std::vector<double>& b) {
    assert(a.size() == b.size());
    double output = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        output += a[i] * b[i];
    }
    return output;
}

std::vector<double> VectorMatMul(const std::vector<double>& numbers, const std::vector<std::vector<double>>& matrix) {
    std::vector<double> output = {0.0, 0.0, 0.0};
    assert(numbers.size() == matrix.size());
    for (size_t i = 0; i < matrix.size(); ++i) {
        output[i] += WeightSum(numbers, matrix[i]);
    }
    return output;
}

std::vector<double> NeuralNetwork(const std::vector<double>& input, const std::vector<std::vector<double>>& weight) {
    return VectorMatMul(input, weight);
}

void Print(const std::vector<double>& vector_data) {
    for (const double& number : vector_data) {
        std::cout << number << ", ";
    }
}
 
int main() {
    int pass;                                        // игр, % игр, число болельщиков
    const std::vector<std::vector<double>> weights = {{0.1, 0.1, -0.3}, //-> травмы?
                                                      {0.1, 0.2, 0.0}, //-> победа?
                                                      {0.0, 1.3, 0.1}}; //-> эмоциональное состояние?
    const std::vector<double> toes = {8.5, 9.5, 10.0, 0.9};  // текущее среднее число игр, сыгранных игроками
    const std::vector<double> wlrec = {0.65, 0.8, 0.8, 0.9};  // текущая доля игр, окончившихся победой(процент)
    const std::vector<double> nfans = {1.2, 1.3, 0.5, 1.0};  // число болельщиков (в миллионах)

    const std::vector<double> input = {toes[0], wlrec[0], nfans[0]};  
    std::vector<double> pred = NeuralNetwork(input, weights);
    Print(pred);
    std::cin >> pass;
}