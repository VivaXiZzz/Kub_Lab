#define M_PI 3.14159265358979323846
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

const double EPS = 1e-9;

double evenTrigPolynomial(const std::vector<double>& y, double x, int n) {
    double T_x = 0.0;

    // проверка на x = 0 чтобы избежать NaN
    if (fabs(x) < EPS) {
        return y[0]; // в точке x = 0 возвращаем значение y[0] или другое подходящее значение
    }

    // первый множитель sin(x) * sin(n * x) / n
    double factor = sin(x) * sin(n * x) / n;

    // построение полинома по формуле (28)
    double sum = 0.0;

    // первый член - y[0]
    if (fabs(cos(x) - 1) > EPS) { // проверка чтобы избежать деления на ноль
        sum -= 0.5 * y[0] / (cos(x) - 1);
    }

    // промежуточные члены суммы
    for (int m = 1; m < n; ++m) {
        double denominator = cos(x) - cos(m * M_PI / n);
        if (fabs(denominator) > EPS) { // проверка деления на ноль
            double term = y[m] * pow(-1, m + 1) / denominator;
            sum += term;
        }
    }

    // последний член - y[n]
    if (fabs(cos(x) + 1) > EPS) { // проверка деления на ноль
        sum += pow(-1, n + 1) * y[n] / (2 * (cos(x) + 1));
    }

    // итоговый результат
    T_x = factor * sum;

    return T_x;
}

int main() {
    setlocale(LC_ALL, "");
    // чтение значений y из файла
    std::vector<double> y;
    std::ifstream infile("8bin.txt");
    if (!infile) {
        std::cerr << "ошибка при открытии файла 8bin.txt" << std::endl;
        return 1;
    }

    double value;
    while (infile >> value) {
        y.push_back(value);
    }
    infile.close();

    // проверка что данные прочитаны корректно
    if (y.empty()) {
        std::cerr << "файл 8bin.txt пуст или не содержит корректных данных" << std::endl;
        return 1;
    }

    int n = y.size() - 1; // степень полинома

    // открываем файл для записи
    std::ofstream outfile("8bout.txt");
    if (!outfile) {
        std::cerr << "ошибка при открытии файла для записи" << std::endl;
        return 1;
    }

    // генерируем значения T(x) для диапазона x от 0 до pi с шагом 0.01
    for (double x = 0; x <= M_PI; x += 0.01) {
        double T_x = evenTrigPolynomial(y, x, n);
        outfile << x << " " << T_x << std::endl;
    }

    outfile.close();

    return 0;
}
