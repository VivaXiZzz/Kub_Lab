#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const double eps=1e-9;
const double dxyz=1e-7;
//const int A=-100;
//const int B=100;

double f1(double x,double y,double z){
    return 4*x-y-z-sin(x);
};

double f2(double x,double y,double z){
    return -x+4*y-z-cos(y);
};

double f3(double x,double y,double z){
    return -x-y+4*z-log(1+z*z);
};

double Derivative(double (*func)(double,double,double),double x,double y,double z,char variable,double dxyz){
    if (variable == 'x') {
        return (func(x + dxyz, y, z) - func(x, y, z)) / dxyz;
    } else if (variable == 'y') {
        return (func(x, y + dxyz, z) - func(x, y, z)) / dxyz;
    } else if (variable == 'z') {
        return (func(x, y, z + dxyz) - func(x, y, z)) / dxyz;
    }
}

double newton_method(double (*f)(double, double, double), double x, double y, double z,char variant, double dxyz) {
    double x0;
    double x1;
    if(variant == 'x'){
        x0=x;
        x1=x0-f(x,y,z)/Derivative(f,x,y,z,variant,dxyz);
        while ((fabs(f(x0, y, z))>eps)&&(fabs(x1-x0)>eps)) {
            if(fabs(Derivative(f,x0,y,z,variant,dxyz))<eps)
                return x0;
            x1 = x0 - f(x0, y, z) / Derivative(f,x0,y,z,variant,dxyz);
            x0=x1;
        }
    return x0;
    }
        if(variant == 'y'){
        x0=x;
        x1=x0-f(x,y,z)/Derivative(f,x,y,z,variant,dxyz);
        while ((fabs(f(x, x0, z))>eps)&&(fabs(x1-x0)>eps)) {
            if(fabs(Derivative(f,x,x0,z,variant,dxyz))<eps)
                return x0;
            x1 = x0 - f(x, x0, z) / Derivative(f,x,x0,z,variant,dxyz);
            x0=x1;
        }
    return x0;
    }
        if(variant == 'z'){
        x0=x;
        x1=x0-f(x,y,z)/Derivative(f,x,y,z,variant,dxyz);
        while ((fabs(f(x, y, x0))>eps)&&(fabs(x1-x0)>eps)) {
            if(fabs(Derivative(f,x,y,x0,variant,dxyz))<eps)
                return x0;
            x1 = x0 - f(x, y, x0) / Derivative(f,x,y,x0,variant,dxyz);
            x0=x1;
        }
    return x0;
    }
}

int main() {
    setlocale(LC_ALL,"");
    //нач приближение
    double x = 0.5, y = 0.5, z = 0.5;

    // метод якоби
    for (int iter = 0; iter < 1000000; ++iter) {
        double x_new = newton_method(f1, x, y, z, 'x',dxyz);
        double y_new = newton_method(f2, x, y, z, 'y',dxyz);
        double z_new = newton_method(f3, x, y, z, 'z',dxyz);

        // проверка сходимости
        if (abs(x_new - x) < eps &&
            abs(y_new - y) < eps &&
            abs(z_new - z) < eps) {
            break;
        }

        x = x_new;
        y = y_new;
        z = z_new;
        }
        ofstream fout("4bout.txt");{
            fout<<"x="<<x<<" y="<<y<<" z="<<z<<" ";
        }
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}
