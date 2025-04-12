#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

double f(double x){
    return 2*x*x-12*x;
}

void func(double a,double b,string filename){
    ofstream out(filename);
    double h=0.01;
    while(a+h<b){
        out << a << " " << f(a) << endl;
        a+=h;
    }
}

double R(int N){
    return 1/pow(2,N/2);
}

double dichotomy_method(double a, double b, double l, double epsilon,int& steps, double& yf, double& zf, string filename) 
{
    ofstream out(filename);
    int k = 0;
    double y,z;
    while (b - a >= l) {
        steps++;

        y = (a + b - epsilon) / 2.0;
        z = (a + b + epsilon) / 2.0;
        
        double fy = f(y);
        double fz = f(z);
        out << y << " " << fy << " " << "y" <<steps-1<<endl;
        out << z << " " << fz << " " << "z" <<steps-1<<endl;

        if (fy < fz) {
            b = z;
            zf = b;
        } else {
            a = y;
            yf = a;
        }
    }
    double min = (a+b)/2.0;
    out << min << " " << f(min) << " " << "min" << endl;
    return (a + b) / 2.0;
}

int main() {
    int steps = 0;
    double yf=0,zf=0;
    double xmin = dichotomy_method(0.0, 10.0, 1, 0.2, steps, yf, zf, "out.txt");
    func(0.0, 10.0, "func.txt");

    cout << "X*: " << xmin << endl;
    cout << "f(x): " << f(xmin) <<endl;
    cout << "[ " << yf << " ; " << zf << " ]"<<endl;
    cout << "steps: " << steps << endl;
    cout << "N: " << 2*steps <<endl;
    cout << "R: " << R(2*steps) <<endl;
}