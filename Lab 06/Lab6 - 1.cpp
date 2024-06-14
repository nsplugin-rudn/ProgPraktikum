#include <iostream>
#include <cmath>

// Определение функции
double f(double x1, double x2, double x3) {
    return exp(x1 * x1 + x2 * x2) + log(4 + x2 * x2 + 2 * x3 * x3);
}

// Определение градиента функции по каждой координате
void gradient(double x1, double x2, double x3, double& grad_x1, double& grad_x2, double& grad_x3) {
    grad_x1 = 2 * x1 * exp(x1 * x1 + x2 * x2);
    grad_x2 = 2 * x2 * exp(x1 * x1 + x2 * x2) + 2 * x2 / (4 + x2 * x2 + 2 * x3 * x3);
    grad_x3 = 4 * x3 / (4 + x2 * x2 + 2 * x3 * x3);
}

// Метод покоординатного спуска для нахождения оптимума функции
void coordinate_descent(double& x1, double& x2, double& x3, double alpha, int max_iter, double tol) {
    int iter = 0;
    double grad_x1, grad_x2, grad_x3;
    double prev_x1, prev_x2, prev_x3;
    do {
        prev_x1 = x1;
        prev_x2 = x2;
        prev_x3 = x3;
        gradient(x1, x2, x3, grad_x1, grad_x2, grad_x3);
        x1 -= alpha * grad_x1;
        x2 -= alpha * grad_x2;
        x3 -= alpha * grad_x3;
        iter++;
    } while (iter < max_iter && (fabs(x1 - prev_x1) > tol || fabs(x2 - prev_x2) > tol || fabs(x3 - prev_x3) > tol));
}

int main() {
    double x1 = 0.1, x2 = 0.2, x3 = 0.3; // Начальное приближение
    double alpha = 0.01; // Размер шага
    int max_iter = 1000; // Максимальное количество итераций
    double tol = 1e-6; // Точность
    coordinate_descent(x1, x2, x3, alpha, max_iter, tol);
    std::cout << "Оптимум функции достигается в точке: (" << x1 << ", " << x2 << ", " << x3 << ")" << std::endl;
    std::cout << "Значение функции в этой точке: " << f(x1, x2, x3) << std::endl;
    return 0;
}
