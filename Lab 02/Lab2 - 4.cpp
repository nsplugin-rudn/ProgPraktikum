#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1e-6;
    const double x = 1.0;
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = pow(-1, k) / (sin(k * x) + 1 + k * k);
        sum += term;
        k++;
    } while (std::fabs(term) > epsilon);

    std::cout << "Sum of the functional series with accuracy " << epsilon << " is: " << sum << std::endl;
    return 0;
}
