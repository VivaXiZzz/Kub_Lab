import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def f(x, y):
    return x**2 + 5*y**2 - x*y + x

points = []
with open('points.txt', 'r') as file:
    for line in file:
        x_str, y_str = line.strip().split()
        x, y = float(x_str), float(y_str)
        z = f(x, y)
        if z is not None:
            points.append((x, y, z))

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
x, y = np.meshgrid(x, y)
z = f(x, y)

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z, cmap='viridis', alpha=0.8)

if points:
    if len(points) == 1:
        px, py, pz = points[0]
        ax.scatter(px, py, pz, color='green', s=70, label='Единственная точка')
    else:
        first, last = points[0], points[-1]
        middle = points[1:-1] if len(points) > 2 else []
        
        ax.scatter(first[0], first[1], first[2], color='green', s=70, label='Первая точка')
        ax.scatter(last[0], last[1], last[2], color='blue', s=70, label='Последняя точка')
        if middle:
            mx, my, mz = zip(*middle)
            ax.scatter(mx, my, mz, color='red', s=50, label='Промежуточные точки')

ax.set_title('График функции', fontsize=12)
ax.set_xlabel('x', fontsize=10)
ax.set_ylabel('y', fontsize=10)
ax.set_zlabel('z', fontsize=10)
ax.legend()

plt.savefig('3d_plot.png', dpi=300, bbox_inches='tight')

plt.show()