#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;
};

Complex add(const Complex& a, const Complex& b) {
    return {a.real + b.real, a.imag + b.imag};
}

Complex subtract(const Complex& a, const Complex& b) {
    return {a.real - b.real, a.imag - b.imag};
}

Complex multiply(const Complex& a, const Complex& b) {
    return {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

Complex divide(const Complex& a, const Complex& b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    return {
        (a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator
    };
}

Complex power(const Complex& a, int n) {
    double r = std::sqrt(a.real * a.real + a.imag * a.imag);
    double theta = std::atan2(a.imag, a.real);
    double r_pow = std::pow(r, n);
    double angle = n * theta;
    return {r_pow * std::cos(angle), r_pow * std::sin(angle)};
}

void roots(const Complex& a, int n) {
    double r = std::sqrt(a.real * a.real + a.imag * a.imag);
    double theta = std::atan2(a.imag, a.real);
    double r_root = std::pow(r, 1.0 / n);
    for (int k = 0; k < n; ++k) {
        double angle = (theta + 2 * M_PI * k) / n;
        Complex root = {r_root * std::cos(angle), r_root * std::sin(angle)};
        std::cout << "Root " << k + 1 << ": " << root.real << " + " << root.imag << "i" << std::endl;
    }
}

int main() {
    Complex z1 = {-1, 1};
    Complex z2 = {-3, -1};

    Complex sum = add(z1, z2);
    Complex difference = subtract(z1, z2);
    Complex product = multiply(z1, z2);
    Complex quotient = divide(z1, z2);

    std::cout << "Sum: " << sum.real << " + " << sum.imag << "i" << std::endl;
    std::cout << "Difference: " << difference.real << " + " << difference.imag << "i" << std::endl;
    std::cout << "Product: " << product.real << " + " << product.imag << "i" << std::endl;
    std::cout << "Quotient: " << quotient.real << " + " << quotient.imag << "i" << std::endl;

    Complex z3 = {1, 2};
    int power_degree = 4;
    Complex z3_power = power(z3, power_degree);
    std::cout << z3.real << " + " << z3.imag << "i ^ " << power_degree << " = "
              << z3_power.real << " + " << z3_power.imag << "i" << std::endl;

    int root_degree = 3;
    std::cout << "Roots of " << z3.real << " + " << z3.imag << "i ^ (1/" << root_degree << "):" << std::endl;
    roots(z3, root_degree);

    return 0;
}
