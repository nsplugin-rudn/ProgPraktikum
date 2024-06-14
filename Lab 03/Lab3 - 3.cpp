#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1e-6;
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = (1.0 / pow(2, k-1)) + (pow(-1, k-1) / (2 * pow(3, k-1)));
        sum += term;
        k++;
    } while (std::fabs(term) > epsilon);

    std::cout << "Sum of the series with accuracy " << epsilon << " is: " << sum << std::endl;
    return 0;
}
