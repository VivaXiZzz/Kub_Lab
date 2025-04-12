#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const double eps = 1e-7;

int main() {
    ifstream fin("0.txt");
    int n;
    double sel, s;
    
    fin >> n;

    vector<vector<double>> m(n, vector<double>(n + 1));
    vector<double> v(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            fin >> m[i][j];
        }
    }

    // прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {
        sel = i;  // выбор главного элемента в столбце

        if (abs(m[i][i]) < eps) {
            sel = -1;
            for (int j = i + 1; j < n; j++) {
                if (abs(m[j][i]) > eps) {
                    sel = j;
                    break;
                }
            }
            if (sel == -1) {
                cout << "У СЛАУ много решений" << endl;
                return 0;
            }
            // обмен строк, если найден новый главный элемент
            swap(m[i], m[sel]);
        }

        // приведение матрицы к треугольному виду
        for (int j = i + 1; j < n; j++) {
            if (abs(m[j][i]) > eps) {
                double k = m[j][i] / m[i][i];
                for (int p = i; p <= n; p++) {
                    m[j][p] -= m[i][p] * k;
                }
            }
        }
    }

    // обратный ход и нахождение решений
    for (int i = n - 1; i >= 0; --i) {
        s = 0;
        for (int j = i + 1; j < n; ++j) {
            s += m[i][j] * v[j];
        }
        v[i] = (m[i][n] - s) / m[i][i];
    }

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << v[i] << endl;
    }

    return 0;
}
