#include <iostream>
#include <vector>
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
    return pow(1-(3-sqrt(5))/2,N-1);
}

double gold_section(double a,double b,double l,int&steps, double&yf, double&zf, string filename){
    ofstream out(filename);
    double y,z,fy,fz;

    y = a + (3 -sqrt(5))/2*(b-a);
    z = a + b - y;

    while ((b - a)>l){
        steps++;
        fy = f(y);
        fz = f(z);

        out << y << " " << fy << " " << "y" <<steps-1<<endl;
        out << z << " " << fz << " " << "z" <<steps-1<<endl;

        if(fy<=fz){
            b = z; z=y; y = a + b - y;
            zf = b;
        }if(fy>fz){
            a = y; y = z; z = a + b - z;
            yf = a;
        }
    }
    
    double min = (a+b)/2.0;
    out << min << " " << f(min) << " " << "min" << endl;
    return (a+b)/2.0;
}

int main(){
    double a0 = 0.0, b0 = 10.0, l = 0.5, yf = 0, zf = 0;
    int steps=0;
    double xmin = gold_section(a0,b0,l,steps,yf,zf,"out.txt");
    steps--;
    func(0.0, 10.0, "func.txt");

    cout<< "X*: " <<xmin<<endl;
    cout<< "f(x): " <<f(xmin)<<endl;
    cout << "[ " << yf << " ; " << zf << " ]"<<endl;
    cout<< "steps: " <<steps<<endl;
    cout << "N: " << steps + 2 <<endl;
    cout << "R: " << R(steps+1) <<endl;
}