import matplotlib.pyplot as plt
import pandas as pd

# Чтение данных
data_h = pd.read_csv("solution.csv")
data_h2 = pd.read_csv("solution_h2.csv")

# Создание графиков
plt.figure(figsize=(12, 8))

# График решений
plt.subplot(2, 1, 1)
plt.plot(data_h["x"], data_h["numerical"], label="Численное (h)", lw=2)
plt.plot(data_h["x"], data_h["exact"], '--', label="Аналитическое (h)", lw=2)
plt.plot(data_h2["x"], data_h2["numerical"], label="Численное (h/2)", lw=2)
plt.plot(data_h2["x"], data_h2["exact"], '--', label="Аналитическое (h/2)", lw=2)
plt.title("Сравнение решений")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)

# График ошибок
plt.subplot(2, 1, 2)
plt.plot(data_h["x"], data_h["error"], label="Ошибка (h)", lw=2)
plt.plot(data_h2["x"], data_h2["error"], label="Ошибка (h/2)", lw=2)
plt.title("Ошибки")
plt.xlabel("x")
plt.ylabel("Ошибка")
plt.legend()
plt.grid(True)

# Сохранение и вывод
plt.tight_layout()
plt.savefig("comparison_plots.png")  # Сохраняет в текущую папку
plt.show()
