#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления определителя матрицы 3x3
double determinant3x3(const vector<vector<double>>& mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Метод Крамера
void solveCramer(const vector<vector<double>>& A, const vector<double>& B) {
    double detA = determinant3x3(A);
    if (fabs(detA) < 1e-6) {
        cout << "Matrix is singular, no unique solution exists." << endl;
        return;
    }

    vector<vector<double>> A1 = A, A2 = A, A3 = A;

    for (int i = 0; i < 3; i++) {
        A1[i][0] = B[i];
        A2[i][1] = B[i];
        A3[i][2] = B[i];
    }

    double detA1 = determinant3x3(A1);
    double detA2 = determinant3x3(A2);
    double detA3 = determinant3x3(A3);

    double x1 = detA1 / detA;
    double x2 = detA2 / detA;
    double x3 = detA3 / detA;

    cout << "Solution using Cramer's method: " << endl;
    cout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
}

int main() {
    vector<vector<double>> A = {{5, -2, -1}, {2, -1, -1}, {2, -4, -8}};
    vector<double> B = {0, -1, 1};

    solveCramer(A, B);

    return 0;
}
