#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

double P(double x)        { return 4; }
double dP(double x)       { return 0; }
double ddP(double x)      { return 0; }
double dddP(double x)     { return 0; }
double d4P(double x)      { return 0; }

double f(double x)        { return 0; }
double d4f(double x)      { return 0; }

double exact_solution(double x) {
    return sin(2-2*x)/sin(2);
}

vector<double> solve_bvp(double a, double b, double alpha, double beta, int N, const string& filename) {
    double h = (b - a) / N;
    vector<double> A(N-1), B(N-1), C(N-1), D(N-1);
    vector<double> y(N+1);

    y[0] = alpha;
    y[N] = beta;

    for (int i = 1; i < N; ++i) {
        double x = a + i * h;
        double Pi    = P(x);
        double dPi   = dP(x);
        double ddPi  = ddP(x);
        double dddPi = dddP(x);
        double d4Pi  = d4P(x);
        
        double Pm = P(x - h);
        double Pp = P(x + h);
        
        double fi   = f(x);
        double fm   = f(x - h);
        double fp   = f(x + h);
        double d4fi = d4f(x);

        A[i-1] = 1.0 - ( -h*h/12.0 + (h*h*h*h)/240.0 * Pi - (h*h*h*h*h)/120.0 * dPi ) * Pm 
                 - (h*h*h*h*h)/120.0 * dddPi;

        B[i-1] = -2.0 - ( -5*h*h/6.0 - (h*h*h*h)/120.0 * Pi 
                  + (h*h*h*h*h*h)/40.0 * ddPi ) * Pi + (h*h*h*h*h*h)/240.0 * d4Pi;

        C[i-1] = 1.0 - ( -h*h/12.0 + (h*h*h*h)/240.0 * Pi + (h*h*h*h*h)/120.0 * dPi ) * Pp 
                 + (h*h*h*h*h)/120.0 * dddPi;

        D[i-1] = (h*h*h*h)/240.0 * (-Pi + 2.0*h*dPi) * fm
                 + h*h * (1.0 + h*h/120.0 * Pi - (h*h*h*h)/40.0 * ddPi) * fi
                 - (h*h*h*h)/240.0 * (Pi + 2.0*h*dPi) * fp
                 - (h*h*h*h*h*h)/240.0 * d4fi;
    }

    //прогонка
    vector<double> alpha_vec(N-1), beta_vec(N-1);
    alpha_vec[0] = - C[0] / B[0];
    beta_vec[0]  = (D[0] - A[0] * y[0]) / B[0];

    for (int i = 1; i < N-1; ++i) {
        double denom = B[i] + A[i] * alpha_vec[i-1];
        alpha_vec[i] = - C[i] / denom;
        beta_vec[i]  = (D[i] - A[i] * beta_vec[i-1]) / denom;
    }

    // обратный ход
    y[N-1] = (D[N-2] - A[N-2] * beta_vec[N-2] - C[N-2] * y[N]) / (B[N-2] + A[N-2] * alpha_vec[N-2]);
    for (int i = N - 2; i >= 1; --i) {
        y[i] = alpha_vec[i-1] * y[i+1] + beta_vec[i-1];
    }

    ofstream out(filename);
    out << "x,numerical,exact,error\n";
    for (int i = 0; i <= N; ++i) {
        double x = a + i * h;
        double y_exact = exact_solution(x);
        double err = fabs(y[i] - y_exact);
        out << x << "," << y[i] << "," << y_exact << "," << err << "\n";
    }
    out.close();
    return y;
}

int main() {
    double a = 0, b = 1;
    double alpha = 1, beta = 0;
    int N = 100;

    solve_bvp(a, b, alpha, beta, N, "solution.csv");
    solve_bvp(a, b, alpha, beta, 2 * N, "solution_h2.csv");

    cout << "solve save in solution.csv и solution_h2.csv\n";
    return 0;
}
