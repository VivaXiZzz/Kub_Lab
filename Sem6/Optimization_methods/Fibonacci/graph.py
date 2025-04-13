import matplotlib.pyplot as plt

def read_data(filename):
    data = []
    try:
        with open(filename, 'r') as f:
            for line in f:
                if line.strip():
                    data.append(line.strip())
    except FileNotFoundError:
        print(f"Ошибка: Файл {filename} не найден!")
    return data

points_data = read_data('out.txt')
func_data = read_data('func.txt')

points_list = []
points_dict = {}
for line in points_data:
    try:
        x, y, label = line.split()
        x_f, y_f = float(x), float(y)
        points_list.append((x_f, y_f, label))
        points_dict[label] = (x_f, y_f)
    except ValueError:
        print(f"Ошибка формата: {line}")

last_point = points_list[-1] if points_list else None

func_x, func_y = [], []
for line in func_data:
    try:
        x, y = map(float, line.split())
        func_x.append(x)
        func_y.append(y)
    except ValueError:
        print(f"Ошибка в данных функции: {line}")

plt.figure(figsize=(16, 8))

if func_x and func_y:
    plt.plot(func_x, func_y, 'limegreen', linewidth=2.5, label='Функция f(x)', zorder=1)

for x, y, label in points_list:
    is_last = (x, y, label) == last_point
    
    proj_color = 'darkorange' if is_last else 'gray'
    lw = 1.2 if is_last else 0.8
    alpha = 0.8 if is_last else 0.5
    
    plt.plot([x, x], [0, y], '--', 
             color=proj_color, 
             linewidth=lw, 
             alpha=alpha,
             zorder=2)
    
    plt.plot([0, x], [y, y], '--', 
             color=proj_color, 
             linewidth=lw, 
             alpha=alpha,
             zorder=2)
    
    plt.scatter(x, 0, color=proj_color, marker='^' if not is_last else 'D', 
                s=50 if is_last else 40, zorder=3)
    plt.text(x, 0 - (1.2 if is_last else 0.8), 
             f'X:{x:.2f}\n{label}', 
             ha='center', va='top', 
             color='darkorange' if is_last else 'darkred',
             fontsize=9 if is_last else 8,
             fontweight='bold' if is_last else 'normal')
    
    plt.scatter(0, y, color=proj_color, marker='>' if not is_last else 'D', 
                s=50 if is_last else 40, zorder=3)
    plt.text(0 - (0.4 if is_last else 0.3), y, 
             f'Y:{y:.2f}\n{label}', 
             ha='right', va='center', 
             color='darkorange' if is_last else 'darkblue',
             fontsize=9 if is_last else 8,
             fontweight='bold' if is_last else 'normal')

legend_handles = []
for i, (x, y, label) in enumerate(points_list):
    is_last = (i == len(points_list)-1)
    
    style = {
        'color': 'gold' if is_last else ('red' if label.startswith('y') else 'blue'),
        'marker': '*' if is_last else ('o' if label.startswith('y') else 's'),
        's': 180 if is_last else 100,
        'edgecolor': 'black',
        'linewidths': 1.5 if is_last else 1,
        'zorder': 5 if is_last else 4
    }
    
    if is_last:
        legend_text = f"★ {label} (минимум)\nX: {x:.2f}\nY: {y:.2f}"
    else:
        legend_text = f"{label}\nX: {x:.2f}\nY: {y:.2f}"
    
    scatter = plt.scatter(x, y, **style, label=legend_text)
    legend_handles.append(scatter)

plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.xlabel('X', fontsize=12)
plt.ylabel('Y', fontsize=12)
plt.title('Метод Фибоначчи', fontsize=14)

for x, y, label in points_list:
    plt.text(x, 0 + 0.7, f'• {label}', 
            ha='center', va='bottom', 
            rotation=45, fontsize=9 if label == last_point[2] else 8,
            color='darkorange' if label == last_point[2] else 'purple',
            alpha=0.9)

if func_x and func_y:
    legend_handles.append(plt.Line2D([], [], color='limegreen', label='Функция f(x)'))

plt.legend(handles=legend_handles,
           bbox_to_anchor=(1.28, 1),
           loc='upper left',
           fontsize=9,
           title="Легенда:",
           title_fontsize=10,
           borderaxespad=0.5)

plt.grid(True, linestyle=':', alpha=0.6)
plt.tight_layout()
plt.show()