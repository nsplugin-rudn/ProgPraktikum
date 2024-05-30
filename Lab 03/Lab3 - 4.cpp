#include <iostream>
#include <vector>

using namespace std;

void thomasAlgorithm(const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x) {
    int n = a.size();
    vector<double> P(n), Q(n);

    P[0] = -b[0] / a[0];
    Q[0] = d[0] / a[0];

    for (int i = 1; i < n; ++i) {
        double denominator = a[i] + c[i] * P[i - 1];
        P[i] = -b[i] / denominator;
        Q[i] = (d[i] - c[i] * Q[i - 1]) / denominator;
    }

    x[n - 1] = Q[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = P[i] * x[i + 1] + Q[i];
    }
}

int main() {
    int n = 5;

    // Главная диагональ
    vector<double> a = {10, 10, -9, 16, 16};

    // Верхняя диагональ
    vector<double> b = {5, -2, -5, -4, 0};

    // Нижняя диагональ
    vector<double> c = {0, 3, 2, 5, -8};

    // Правая часть
    vector<double> d = {120, -91, 5, -74, -56};

    vector<double> x(n);

    thomasAlgorithm(a, b, c, d, x);

    cout << "Solution using Thomas Algorithm:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
