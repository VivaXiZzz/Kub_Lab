#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <stdexcept>
#include <utility>

using namespace std;

const double EPS = 1e-8;
const int MAX_ITER = 10000;

vector<double> multiplyMatrixVector(const vector<vector<double>>& A, const vector<double>& v) {
    int n = A.size();
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * v[j];
        }
    }
    return result;
}

double dotProduct(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

double norm(const vector<double>& v) {
    return sqrt(dotProduct(v, v));
}

void normalize(vector<double>& v) {
    double n = norm(v);
    if (n < EPS) {
        fill(v.begin(), v.end(), 0.0);
        return;
    }
    for (double& val : v) {
        val /= n;
    }
}

pair<double, vector<double>> powerMethod(const vector<vector<double>>& A, int max_attempts = 5) {
    int n = A.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-1.0, 1.0);

    for (int attempt = 0; attempt < max_attempts; ++attempt) {
        vector<double> y(n);
        for (double& val : y) val = dist(gen);
        normalize(y);

        double lambda_old = 0.0;
        bool converged = false;

        for (int iter = 0; iter < MAX_ITER; ++iter) {
            vector<double> Ay = multiplyMatrixVector(A, y);
            double lambda_new = norm(Ay);

            if (lambda_new < EPS) {
                y = Ay;
                normalize(y);
                return make_pair(0.0, y);
            }

            vector<double> y_new = Ay;
            normalize(y_new);

            double cos_angle = dotProduct(y, y_new);
            if (abs(1.0 - abs(cos_angle)) < EPS && abs(lambda_new - lambda_old) < EPS) {
                return make_pair(lambda_new * (cos_angle < 0 ? -1.0 : 1.0), y_new);
            }

            lambda_old = lambda_new;
            y = y_new;
        }
    }
    throw runtime_error("Метод не сошелся за указанное число попыток");
}

void deflateMatrix(vector<vector<double>>& A, const vector<double>& v, double lambda) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] -= lambda * v[i] * v[j];
        }
    }
}

bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(A[i][j] - A[j][i]) > 1e-6) return false;
        }
    }
    return true;
}

pair<vector<double>, vector<vector<double>>> findEigenPairs(vector<vector<double>> A) {
    int n = A.size();
    if (!isSymmetric(A)) throw invalid_argument("Матрица должна быть симметричной");

    vector<double> eigenvalues;
    vector<vector<double>> eigenvectors(n, vector<double>(n));

    for (int i = 0; i < n; ++i) {
        pair<double, vector<double>> result = powerMethod(A);
        double lambda = result.first;
        vector<double> v = result.second;

        eigenvalues.push_back(lambda);
        for (int j = 0; j < n; ++j) {
            eigenvectors[j][i] = v[j];
        }
        deflateMatrix(A, v, lambda);
    }

    return make_pair(eigenvalues, eigenvectors);
}

vector<vector<double>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("Не удалось открыть файл " + filename);

    int n;
    file >> n;
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> A[i][j];
        }
    }
    return A;
}

void writeResults(const string& filename, const vector<double>& vals, const vector<vector<double>>& vecs) {
    ofstream file(filename);
    if (!file) throw runtime_error("Не удалось создать файл " + filename);

    file << "Собственные значения:\n";
    for (double val : vals) file << val << '\n';

    file << "\nСобственные векторы (по столбцам):\n";
    for (int i = 0; i < vecs.size(); ++i) {
        for (int j = 0; j < vecs[i].size(); ++j) {
            file << vecs[i][j] << (j < vecs[i].size() - 1 ? " " : "\n");
        }
    }
}

int main() {
    try {
        vector<vector<double>> A = readMatrixFromFile("in.txt");
        pair<vector<double>, vector<vector<double>>> result = findEigenPairs(A);
        writeResults("out.txt", result.first, result.second);
        cout << "Результаты успешно записаны в out.txt\n";
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}