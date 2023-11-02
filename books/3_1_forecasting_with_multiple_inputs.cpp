#include <iostream>
#include <vector>
#include <cassert>

double WeightSum(const std::vector<double>& a, const std::vector<double>& b) {
    assert(a.size() == b.size());
    double output = 0.0;
    for (int i = 0; i <= a.size(); ++i) {
        output += a[i] * b[i];
    }
    return output;
}

double NeuralNetwork(const std::vector<double>& input, const std::vector<double>& weight) {
    return WeightSum(input, weight);
}

int main() {
    int pass;
    std::vector<double> weight = {0.1, 0.2, 0.0};
    std::vector<double> toes = {8.5, 9.5, 10.0, 0.9};  // текущее среднее число игр, сыгранных игроками
    std::vector<double> wlrec = {0.65, 0.8, 0.8, 0.9};  // текущая доля игр, окончившихся победой(процент)
    std::vector<double> nfans = {1.2, 1.3, 0.5, 1.0};  // число болельщиков (в миллионах)
    std::vector<double> input = {toes[0], wlrec[0], nfans[0]};  
    double pred = NeuralNetwork(input, weight);
    std::cout << pred;
    std::cin >> pass;
}
