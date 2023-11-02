#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// double weight = 0.1;

double WeightSum(const vector<double>& a, const vector<double>& b) {
    assert(a.size() == b.size());
    double output = 0.0;
    for (int i = 0; i <= a.size(); ++i) {
        output += a[i] * b[i];
    }
    return output;
}

vector<double> VectorMatMul(const vector<double>& numbers, const vector<vector<double>>& matrix) {
    vector<double> output = {0.0, 0.0, 0.0};
    assert(numbers.size() == matrix.size());
    for (int i = 0; i <= matrix.size(); ++i) {
        output[i] += WeightSum(numbers, matrix[i]);
    }
    return output;
}


vector<double> NeuralNetwork(double input, const vector<double>& weight) {
    return VectorMatMul(input, weight);
}


void Print(const vector<double>& vector) {
    for (const double& number : vector) {
        cout << number << ", "s;
    }
}
 
int main() {
    int pass;
    const vector<vector<double>> weights = {{0.1, 0.1, -0.3}, 
                                            {0.1, 0.2, 0.0}, 
                                            {0.0, 1.3, 0.1}};
    const vector<double> toes = {8.5, 9.5, 10.0, 0.9};  // текущее среднее число игр, сыгранных игроками
    const vector<double> wlrec = {0.65, 0.8, 0.8, 0.9};  // текущая доля игр, окончившихся победой(процент)
    const vector<double> nfans = {1.2, 1.3, 0.5, 1.0};  // число болельщиков (в миллионах)

    const vector<double> input = {toes[0], wlrec[0], nfans[0]};  
    vector<double> pred = NeuralNetwork(input, weights);
    Print(pred);
    cin >> pass;
}