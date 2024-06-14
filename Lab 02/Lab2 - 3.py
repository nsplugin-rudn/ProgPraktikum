import random
import math

# Генерация случайных параметров параболы y = ax^2 + bx + c
a = random.uniform(-10, 10)
b = random.uniform(-10, 10)
c = random.uniform(-10, 10)

# Генерация случайной точки (x0, y0)
x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)

# Уравнение параболы
def parabola(x, a, b, c):
    return a * x**2 + b * x + c

# Проверка принадлежности точки (x0, y0) параболе y = ax^2 + bx + c
def is_point_on_parabola(x0, y0, a, b, c):
    return math.isclose(y0, parabola(x0, a, b, c), rel_tol=1e-9)

# Нахождение координат фокуса параболы y = ax^2 + bx + c
def focus_of_parabola(a, b, c):
    h = -b / (2 * a)
    k = c - (b**2 / (4 * a))
    focus_y = k + 1 / (4 * a)
    return (h, focus_y)

# Нахождение расстояния от директрисы до фокуса параболы
def distance_focus_directrix(a):
    return 1 / (4 * a)

# Проверка принадлежности точки
point_belongs = is_point_on_parabola(x0, y0, a, b, c)
print(f"Point ({x0}, {y0}) {'belongs' if point_belongs else 'does not belong'} to the parabola y = {a}x^2 + {b}x + {c}")

# Нахождение фокуса параболы
focus = focus_of_parabola(a, b, c)
print(f"Focus of the parabola: {focus}")

# Нахождение расстояния от директрисы до фокуса
distance = distance_focus_directrix(a)
print(f"Distance from directrix to focus: {distance}")
