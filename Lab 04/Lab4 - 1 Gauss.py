import numpy as np

# Коэффициенты СЛАУ
A = np.array([[2, 7, -8, 6],
              [4, 4, 0, -7],
              [-1, -3, 6, 3],
              [9, -7, -2, -8]], dtype=np.float64)

# Столбец свободных членов
b = np.array([-39, 41, 4, 113], dtype=np.float64)

# Приводим матрицу к верхнетреугольному виду методом Гаусса
n = len(A)
for i in range(n):
    if A[i, i] == 0:
        print("Система не имеет единственного решения!")
        break
    for j in range(i+1, n):
        ratio = A[j, i] / A[i, i]
        A[j] -= ratio * A[i]
        b[j] -= ratio * b[i]

# Находим решение системы обратным ходом
x = np.zeros(n)
for i in range(n-1, -1, -1):
    x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]

print("Решение СЛАУ методом Гаусса:")
for i in range(len(x)):
    print(f"x{i + 1} = {x[i]}")
