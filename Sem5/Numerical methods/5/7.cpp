#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int A = 0;
int B = 2;
double EPS = 1e-7;
double hmin=1e-4;
double h_initial = 0.1;

double f(double x) {
    return pow(sin(x), 3);
}

double trap(double a, double b, double h) {
    int n = int((b - a) / h);
    double integral = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i)
        integral += f(a + i * h);
    return integral * h;
}

double adaptiveTrap(double a, double b, double h_initial, double eps,double hmin) {
    double h = h_initial;
    double sum = 0, h1, h2, err;
    double x = a;
    while (x < b) {
        if (x + h > b) h = b - x;
        h1 = trap(x, x + h, h);
        h2 = trap(x, x + h, h / 2);

        err = abs(h2 - h1) / 3;
        if (err < eps||(h<=hmin)) {
            sum += h1;
            x += h;
        } else {
            h *= 0.5;
            //cout<<h;
        }
    }
    return sum;
}

int main() {
    ofstream fout("7bout.txt");
    double x0;
    x0= adaptiveTrap(A, B, h_initial, EPS, hmin);
    fout<<x0;
    fout.close();
    cout <<"ans = "<< x0 << endl;
}
