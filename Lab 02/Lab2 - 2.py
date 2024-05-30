import numpy as np
import scipy.integrate as spi

# Определение функций
def f1(x):
    return x**4 / (1 + x**2)

def f2(x):
    return np.exp(-2 * x) * np.sin(x)

# Методы численного интегрирования
def rectangle_method(f, a, b, n):
    h = (b - a) / n
    result = sum(f(a + i * h) for i in range(n)) * h
    return result

def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    result = 0.5 * (f(a) + f(b)) + sum(f(a + i * h) for i in range(1, n))
    return result * h

def simpsons_method(f, a, b, n):
    if n % 2 != 0:
        n += 1
    h = (b - a) / n
    result = f(a) + f(b) + 4 * sum(f(a + i * h) for i in range(1, n, 2)) + 2 * sum(f(a + i * h) for i in range(2, n-1, 2))
    return result * h / 3

# Интервалы интегрирования
a1, b1 = 1, 2
a2, b2 = 0, 100 

# Количество интервалов для методов прямоугольников, трапеций и Симпсона
n = 1000

# Вычисление интегралов для первого интеграла
integral_f1_rectangle = rectangle_method(f1, a1, b1, n)
integral_f1_trapezoidal = trapezoidal_method(f1, a1, b1, n)
integral_f1_simpsons = simpsons_method(f1, a1, b1, n)

# Вычисление интегралов для второго интеграла
integral_f2_rectangle = rectangle_method(f2, a2, b2, n)
integral_f2_trapezoidal = trapezoidal_method(f2, a2, b2, n)
integral_f2_simpsons = simpsons_method(f2, a2, b2, n)

# Вывод результатов
print(f"Интеграл x^4 / (1 + x^2) от 1 до 2 методом прямоугольников: {integral_f1_rectangle}")
print(f"Интеграл x^4 / (1 + x^2) от 1 до 2 методом трапеций: {integral_f1_trapezoidal}")
print(f"Интеграл x^4 / (1 + x^2) от 1 до 2 методом Симпсона: {integral_f1_simpsons}")

print(f"Интеграл e^(-2*x) * sin(x) от 0 до 100 методом прямоугольников: {integral_f2_rectangle}")
print(f"Интеграл e^(-2*x) * sin(x) от 0 до 100 методом трапеций: {integral_f2_trapezoidal}")
print(f"Интеграл e^(-2*x) * sin(x) от 0 до 100 методом Симпсона: {integral_f2_simpsons}")
