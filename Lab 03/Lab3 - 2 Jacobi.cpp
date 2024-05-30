#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Метод Якоби
void solveJacobi(const vector<vector<double>>& A, const vector<double>& B, int maxIterations = 1000, double tolerance = 1e-6) {
    int n = A.size();
    vector<double> x(n, 0.0);
    vector<double> x_new(n, 0.0);

    for (int iter = 0; iter < maxIterations; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = B[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        double norm = 0.0;
        for (int i = 0; i < n; i++) {
            norm += fabs(x_new[i] - x[i]);
        }

        if (norm < tolerance) {
            cout << "Solution using Jacobi's method: " << endl;
            for (int i = 0; i < n; i++) {
                cout << "x" << i + 1 << " = " << x_new[i] << endl;
            }
            return;
        }

        x = x_new;
    }

    cout << "Jacobi method did not converge within the given iterations." << endl;
}

int main() {
    vector<vector<double>> A = {{5, -2, -1}, {2, -1, -1}, {2, -4, -8}};
    vector<double> B = {0, -1, 1};

    solveJacobi(A, B);

    return 0;
}
