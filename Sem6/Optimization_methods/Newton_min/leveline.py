import numpy as np
import matplotlib.pyplot as plt

def f(x, y):
    return x**2 + 5*y**2 - x*y + x

points = []
with open('points.txt', 'r') as file:
    for line in file:
        x_str, y_str = line.strip().split()
        x, y = float(x_str), float(y_str)
        z = f(x, y)
        points.append((x, y))  # Сохраняем только x и y для траектории

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
x_grid, y_grid = np.meshgrid(x, y)
z_grid = f(x_grid, y_grid)

plt.figure(figsize=(8, 8))
contour = plt.contour(x_grid, y_grid, z_grid, levels=20, cmap='Spectral')
plt.clabel(contour, inline=True, fontsize=8)

path = np.array(points)
plt.plot(path[:, 0], path[:, 1], 'g.-', label='Траектория сходимости')

plt.scatter(path[0, 0], path[0, 1], c='blue', s=100, label='Начальное приближение')
plt.scatter(path[-1, 0], path[-1, 1], c='red', s=100, label='Конечная точка')

plt.title('Визуализация сходимости')
plt.xlabel('x1')
plt.ylabel('x2')
plt.legend()
plt.colorbar(contour)
plt.grid(True)
plt.show()
