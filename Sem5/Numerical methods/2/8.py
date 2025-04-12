import matplotlib.pyplot as plt
import math
# чтение данных из файла
x = []
y0 = []
x0 = []
T_x = []
with open("8bout.txt", "r") as f:
    for line in f:
        values = line.split()
        x.append(float(values[0]))
        T_x.append(float(values[1]))
with open("8bin.txt", "r") as f1:
    for line in f1:
        values = line.split()
        y0.append(float(values[0]))
for i in range(0,len(y0)):
    x0.append(i*math.pi/(len(y0)-1))
print(len(y0))

# построение графика
plt.plot(x, T_x, label='T(x)')
plt.scatter(x0,y0,color='red',marker='X')
plt.xlabel('x')
plt.ylabel('T(x)')
plt.title('четный тригонометрический полином T(x)')
plt.legend()
plt.grid(True)
plt.show()
