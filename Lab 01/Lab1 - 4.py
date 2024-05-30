import random
import sympy as sp

# Генерация случайных параметров эллиптического цилиндра (x/a)^2 + (y/b)^2 = 1
a = random.uniform(1, 10)
b = random.uniform(1, 10)

# Генерация случайных параметров плоскости Ax + By + Cz + D = 0
A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)

# Генерация случайных параметров прямой в параметрической форме r(t) = r0 + t * d
x0, y0, z0 = random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)
dx, dy, dz = random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1)

# Генерация случайной точки (px, py, pz)
px, py, pz = random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)

# Уравнение эллиптического цилиндра
def is_point_on_elliptical_cylinder(px, py, a, b):
    return (px / a)**2 + (py / b)**2 <= 1

# Проверка пересечения плоскости с цилиндром
def does_plane_intersect_cylinder(A, B, C, D, a, b):
    x, y, z = sp.symbols('x y z')
    cylinder_eq = (x/a)**2 + (y/b)**2 - 1
    plane_eq = A * x + B * y + C * z + D
    intersection = sp.solve([cylinder_eq, plane_eq], (x, y, z))
    return len(intersection) > 0

# Проверка пересечения прямой с цилиндром
def does_line_intersect_cylinder(x0, y0, z0, dx, dy, dz, a, b):
    t = sp.symbols('t')
    xt = x0 + t * dx
    yt = y0 + t * dy
    zt = z0 + t * dz
    cylinder_eq = (xt/a)**2 + (yt/b)**2 - 1
    solutions = sp.solve(cylinder_eq, t)
    return len(solutions) > 0

# Проверка принадлежности точки цилиндру
point_on_cylinder = is_point_on_elliptical_cylinder(px, py, a, b)
print(f"Point ({px}, {py}, {pz}) {'belongs' if point_on_cylinder else 'does not belong'} to the elliptical cylinder (x/{a})^2 + (y/{b})^2 = 1")

# Проверка пересечения плоскости с цилиндром
plane_intersects = does_plane_intersect_cylinder(A, B, C, D, a, b)
print(f"Plane {A}x + {B}y + {C}z + {D} = 0 {'intersects' if plane_intersects else 'does not intersect'} the elliptical cylinder (x/{a})^2 + (y/{b})^2 = 1")

# Проверка пересечения прямой с цилиндром
line_intersects = does_line_intersect_cylinder(x0, y0, z0, dx, dy, dz, a, b)
print(f"Line passing through ({x0}, {y0}, {z0}) with direction ({dx}, {dy}, {dz}) {'intersects' if line_intersects else 'does not intersect'} the elliptical cylinder (x/{a})^2 + (y/{b})^2 = 1")
