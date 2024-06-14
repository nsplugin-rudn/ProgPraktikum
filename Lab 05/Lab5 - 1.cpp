#include <iostream>
#include <vector>

class CubicSpline {
private:
    std::vector<double> x_values; // Узлы интерполяции x
    std::vector<double> y_values; // Значения функции y в узлах интерполяции
    std::vector<double> a, b, c, d; // Коэффициенты сплайна

public:
    CubicSpline(const std::vector<double>& x, const std::vector<double>& y) {
        x_values = x;
        y_values = y;
        int n = x.size();
        a.resize(n);
        b.resize(n);
        c.resize(n);
        d.resize(n);

        // Вычисление коэффициентов сплайна
        std::vector<double> h(n);
        for (int i = 0; i < n - 1; ++i) {
            h[i] = x[i + 1] - x[i];
        }

        std::vector<double> alpha(n - 1);
        for (int i = 1; i < n - 1; ++i) {
            alpha[i] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]);
        }

        std::vector<double> l(n);
        std::vector<double> mu(n);
        std::vector<double> z(n);
        l[0] = 1;
        mu[0] = 0;
        z[0] = 0;

        for (int i = 1; i < n - 1; ++i) {
            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        l[n - 1] = 1;
        z[n - 1] = 0;
        c[n - 1] = 0;

        for (int j = n - 2; j >= 0; --j) {
            c[j] = z[j] - mu[j] * c[j + 1];
            b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
            d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
            a[j] = y[j];
        }
    }

    // Вычисление значения сплайна в точке x
    double interpolate(double x) {
        int i = findInterval(x);
        double dx = x - x_values[i];
        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
    }

    // Поиск интервала, в который попадает точка x
    int findInterval(double x) {
        int n = x_values.size();
        int i = 0;
        while (i < n - 1 && x > x_values[i + 1]) {
            i++;
        }
        return i;
    }
};

int main() {
    // Данные из таблицы
    std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {0.0, 0.5, 0.86603, 1.0, 0.86603};

    // Создание объекта кубического сплайна
    CubicSpline spline(x, y);

    // Вычисление значения сплайна в точке x = 1.5
    double result = spline.interpolate(1.5);
    std::cout << "Значение сплайна в точке x = 1.5: " << result << std::endl;

    return 0;
}
