#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

double f(double t, double y) {
    return y;
}

double df_dy(double t, double y, double h = 1e-6) {
    return (f(t, y + h) - f(t, y - h)) / (2 * h);
}

double implicitEquation(double y_prev, double y_next, double t, double tau) {
    return y_next - y_prev - tau * f(t + tau, y_next);
}


double derivative(double y_prev, double y_next, double t, double tau) {
    double dfdy = df_dy(t + tau, y_next);
    return 1 - tau * dfdy;
}

double newton(double y_prev, double t, double tau, double EPS = 1e-6, int MAXITER = 100) {
    double y_next = y_prev;
    for (int i = 0; i < MAXITER; ++i) {
        double F = implicitEquation(y_prev, y_next, t, tau);
        double dF = derivative(y_prev, y_next, t, tau);
        double delta = -F / dF;
        y_next += delta;
        if (abs(delta) < EPS) break;
    }
    return y_next;
}

vector<double> Adam(double t0, double y0, double tau) {
    vector<double> solution;
    solution.push_back(y0);
    double t = t0;
    double y = y0;

    for (int i = 0; i < int(abs(y0-t0)/tau); ++i) {
        y = newton(y, t, tau);
        t += tau;
        solution.push_back(y);
    }

    return solution;
}

int main() {
double t0 = 0.0;
    double y0 = 1.0;
    double tau = 0.1;

    vector<double> result = Adam(t0, y0, tau);

    ofstream file("out.txt");
    cout << "t\tNumerical\tExact\n";
    file << "t\tNumerical\tExact\n";
    for (int i = 0; i <= int(abs(y0-t0)/tau); ++i) {
        double t = t0 + i * tau;
        double exact = 1 * exp(t);
        cout << t << "\t" << result[i] << "\t\t" << exact << endl;
        file << t << "\t" << result[i] << "\t\t" << exact << endl;
    }

    return 0;
}