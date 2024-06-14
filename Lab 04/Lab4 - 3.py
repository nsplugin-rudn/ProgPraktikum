import numpy as np

# Коэффициенты системы уравнений
A = np.array([[24, 2, 4, -9],
              [-6, -27, -8, -6],
              [-4, 8, 19, 6],
              [4, 5, -3, -13]], dtype=float)

# Свободные члены
b = np.array([-9, -76, -79, -70], dtype=float)

# Начальное приближение
x0 = np.zeros_like(b)

# Максимальное количество итераций
max_iter = 1000

# Погрешность
epsilon = 1e-6

# Метод Зейделя
def gauss_seidel(A, b, x0, max_iter, epsilon):
    n = len(b)
    x = x0.copy()
    for k in range(max_iter):
        x_new = np.zeros_like(x)
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i+1:], x[i+1:])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]
        if np.allclose(x, x_new, atol=epsilon):
            break
        x = x_new
    return x

# Решение системы методом Зейделя
solution = gauss_seidel(A, b, x0, max_iter, epsilon)

# Вывод результата
print("Решение системы методом Зейделя:")
for i, xi in enumerate(solution):
    print(f"x_{i+1} = {xi}")
