import numpy as np

# Функция для вычисления коэффициентов интерполяционного многочлена Ньютона
def newton_interpolation_coefficients(x_values, y_values):
    n = len(x_values)
    coefficients = np.zeros(n)
    for i in range(n):
        coefficients[i] = y_values[i]
    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            coefficients[i] = (coefficients[i] - coefficients[i - 1]) / (x_values[i] - x_values[i - j])
    return coefficients

# Функция для вычисления значения интерполяционного многочлена Ньютона в точке x
def newton_interpolation_value(x, x_values, coefficients):
    n = len(x_values)
    result = coefficients[-1]
    for i in range(n - 2, -1, -1):
        result = result * (x - x_values[i]) + coefficients[i]
    return result

# Функция для вычисления погрешности интерполяции в точке x
def interpolation_error(x, x_values, y_values, coefficients):
    n = len(x_values)
    result = 0.0
    term = 1.0
    for i in range(n):
        term *= (x - x_values[i])
        result += term * coefficients[i]
    return abs(np.cos(x) - result)

# Значения x_i и y_i
x_values = np.array([0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi])
y_values = np.cos(x_values)

# Вычисление коэффициентов интерполяционного многочлена Ньютона
coefficients = newton_interpolation_coefficients(x_values, y_values)

# Вычисление значения интерполяционного многочлена Ньютона в точке x = 0.25*pi
x = 0.25 * np.pi
interpolated_value = newton_interpolation_value(x, x_values, coefficients)
print("Значение интерполяционного многочлена Ньютона в точке x =", x, ":", interpolated_value)

# Вычисление погрешности интерполяции в точке x = 0.25*pi
error = interpolation_error(x, x_values, y_values, coefficients)
print("Погрешность интерполяции в точке x =", x, ":", error)
