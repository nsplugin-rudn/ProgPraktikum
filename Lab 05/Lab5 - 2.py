import numpy as np

# Определение функции и её градиента
def f(x):
    x1, x2 = x
    return x1**2 + np.exp(x1**2 + x2**2) + 4*x1 + 3*x2

def grad_f(x):
    x1, x2 = x
    df_dx1 = 2*x1 + 2*x1*np.exp(x1**2 + x2**2) + 4
    df_dx2 = 2*x2*np.exp(x1**2 + x2**2) + 3
    return np.array([df_dx1, df_dx2])

# Метод наискорейшего спуска
def steepest_descent(f, grad_f, x0, alpha, max_iter, tol):
    x = x0
    for _ in range(max_iter):
        grad = grad_f(x)
        if np.linalg.norm(grad) < tol:
            break
        x = x - alpha * grad
    return x, f(x)

# Начальное приближение, размер шага, максимальное количество итераций и точность
x0 = np.array([0.0, 0.0])
alpha = 0.01
max_iter = 1000
tol = 1e-6

# Применение метода наискорейшего спуска
optimum_point, optimum_value = steepest_descent(f, grad_f, x0, alpha, max_iter, tol)
print("Оптимум функции достигается в точке:", optimum_point)
print("Значение функции в этой точке:", optimum_value)
