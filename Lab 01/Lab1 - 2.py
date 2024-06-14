import math

# Функция f(x)
def f(x):
    return math.exp(-x) - math.sqrt(x - 1)

# Производная функции f(x) для метода Ньютона
def df(x):
    return -math.exp(-x) - 1/(2*math.sqrt(x - 1))

# Метод дихотомии (бисекции)
def bisection(a, b, tol=1e-6):
    if f(a) * f(b) >= 0:
        raise ValueError("Function values at the endpoints must have different signs")
    
    while (b - a) / 2.0 > tol:
        midpoint = (a + b) / 2.0
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return (a + b) / 2.0

# Метод простых итераций
def fixed_point_iteration(g, x0, tol=1e-6, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        x_next = g(x)
        if abs(x_next - x) < tol:
            return x_next
        x = x_next
    raise ValueError("Fixed point iteration did not converge")

# Метод хорд (секущих)
def secant(x0, x1, tol=1e-6, max_iter=1000):
    for _ in range(max_iter):
        if abs(f(x1) - f(x0)) < tol:
            raise ValueError("Denominator in secant method is too small")
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(x2 - x1) < tol:
            return x2
        x0, x1 = x1, x2
    raise ValueError("Secant method did not converge")

# Метод Ньютона
def newton(x0, tol=1e-6, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        f_x = f(x)
        df_x = df(x)
        if abs(df_x) < tol:
            raise ValueError("Derivative is too small")
        x_next = x - f_x / df_x
        if abs(x_next - x) < tol:
            return x_next
        x = x_next
    raise ValueError("Newton's method did not converge")

# Основная программа
if __name__ == "__main__":
    # Установить начальные значения и отрезок для методов
    a, b = 1, 2.5  # Отрезок для метода дихотомии
    x0 = 1.1         # Начальное приближение для методов итераций и Ньютона
    x1 = 1.3         # Второе начальное приближение для метода хорд
    
    try:
        root_bisection = bisection(a, b)
        print(f"Bisection method root: {root_bisection:.6f}")
    except ValueError as e:
        print(e)
    
    try:

        g = lambda x: 1 + math.exp(-x)
        root_fixed_point = fixed_point_iteration(g, x0)
        print(f"Fixed point iteration root: {root_fixed_point:.6f}")
    except ValueError as e:
        print(e)
    
    try:
        root_secant = secant(x0, x1)
        print(f"Secant method root: {root_secant:.6f}")
    except ValueError as e:
        print(e)
    
    try:
        root_newton = newton(x0)
        print(f"Newton's method root: {root_newton:.6f}")
    except ValueError as e:
        print(e)
