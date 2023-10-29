#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// double weight = 0.1;

// double WeightSum(vector<double> a, vector<double> b) {
//     assert(a.size() == b.size());
//     double output = 0.0;
//     for (int i = 0; i <= a.size(); ++i) {
//         output += a[i] * b[i];
//     }
//     return output;
// }

vector<double> ElementMul(double number, const vector<double>& data) {
    vector<double> output = {0.0, 0.0, 0.0};
    assert(output.size() == data.size());
    for (int i = 0; i <= data.size(); ++i) {
        output[i] += number * data[i];
    }
    return output;
}


vector<double> NeuralNetwork(double input, const vector<double>& weight) {
    return ElementMul(input, weight);
}


void Print(const vector<double>& vector) {
    for (const double& number : vector) {
        cout << number << ", "s;
    }
}
 
int main() {
    int pass;
    const vector<double> weight = {0.3, 0.2, 0.9};
    // vector<double> toes = {8.5, 9.5, 10.0, 0.9};  // текущее среднее число игр, сыгранных игроками
    const vector<double> wlrec = {0.65, 0.8, 0.8, 0.9};  // текущая доля игр, окончившихся победой(процент)
    // vector<double> nfans = {1.2, 1.3, 0.5, 1.0};  // число болельщиков (в миллионах)
    // vector<double> input = {toes[0], wlrec[0], nfans[0]};  
    vector<double> pred = NeuralNetwork(wlrec[0], weight);
    Print(pred);
    cin >> pass;
}