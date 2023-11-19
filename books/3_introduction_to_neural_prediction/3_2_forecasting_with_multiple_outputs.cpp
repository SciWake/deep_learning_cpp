#include <iostream>
#include <vector>
#include <cassert>
// using namespace std::string_literals;

std::vector<double> ElementMul(double number, const std::vector<double>& data) {
    std::vector<double> output = {0.0, 0.0, 0.0};
    assert(output.size() == data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        output[i] += number * data[i];
    }
    return output;
}

std::vector<double> NeuralNetwork(double input, const std::vector<double>& weight) {
    return ElementMul(input, weight);
}

void Print(const std::vector<double>& vector_data) {
    for (const double& number : vector_data) {
        std::cout << number << ", ";
    }
}
 
int main() {
    int pass;
    const std::vector<double> weight = {0.3, 0.2, 0.9};
    const std::vector<double> wlrec = {0.65, 0.8, 0.8, 0.9};  // текущая доля игр, окончившихся победой(процент)
    std::vector<double> pred = NeuralNetwork(wlrec[0], weight);
    Print(pred);
    std::cin >> pass;
}