import matplotlib.pyplot as plt
import numpy as np

# Загрузка данных
data_h1 = np.loadtxt("h01.txt")
data_h2 = np.loadtxt("h005.txt")

# Создание отдельных графиков
plt.figure(figsize=(12, 8))

# График для x(t)
plt.subplot(2, 1, 1)
plt.plot(data_h1[:,0], data_h1[:,1], 'b-', label='Численное (h=1)')
plt.plot(data_h2[:,0], data_h2[:,1], 'g--', label='Численное (h=0.5)')
plt.plot(data_h1[:,0], data_h1[:,2], 'r:', label='Точное')
plt.xlabel('t')
plt.ylabel('x(t)')
plt.title("Сравнение решений для x(t)")
plt.legend()
plt.grid(True)

# График для y(t)
plt.subplot(2, 1, 2)
plt.plot(data_h1[:,0], data_h1[:,3], 'b-', label='Численное (h=1)')
plt.plot(data_h2[:,0], data_h2[:,3], 'g--', label='Численное (h=0.5)')
plt.plot(data_h1[:,0], data_h1[:,4], 'r:', label='Точное')
plt.xlabel('t')
plt.ylabel('y(t)')
plt.title("Сравнение решений для y(t)")
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()