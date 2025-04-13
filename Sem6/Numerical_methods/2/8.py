import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('out.txt', skiprows=1)
t_values = data[:, 0]
numerical_values = data[:, 1]
exact_values = data[:, 2]

plt.figure(figsize=(8, 5))
plt.plot(t_values, numerical_values, 'bo-', label='Численное')
plt.plot(t_values, exact_values, 'r*-', label='Аналитическое')

plt.xlabel('t')
plt.ylabel('y')
plt.title('Сравнение решений')
plt.legend()
plt.grid()

plt.show()
