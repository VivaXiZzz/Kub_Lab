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

double fibb(int N){
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    return fibb(N-1) + fibb(N-2);
}

double R(int N){
    return 1/fibb(N);
}

vector<int> fibonacci(double a) {
    vector<int> fib = {1, 1};
    while (fib.back() < a) {
        int next = fib.back() + fib[fib.size() - 2];
        fib.push_back(next);
    }
    return fib;
}

double fibonacci_method(double a,double b,double l,double EPS,int&steps, double&yf, double&zf, string filename){
    ofstream out(filename);
    vector<int> fib = fibonacci((b-a)/l);
    int N = fib.size()-1;
    double y,z,fy,fz,y_last,z_last;

    y = a + (float)fib[N-2]/fib[N]*(b-a);
    z = a + (float)fib[N-1]/fib[N]*(b-a);

    for(int k=0;k<N-2;k++){
        steps++;

        fy=f(y);
        fz=f(z);

        out << y << " " << fy << " " << "y" <<steps-1<<endl;
        out << z << " " << fz << " " << "z" <<steps-1<<endl;

        if (fy<=fz){
            b = z; z = y; y = a + (float)fib[N-3-k]/fib[N-1-k]*(b-a);
            zf = b;
        } else{
            a = y; y = z; z = a + (float)fib[N-2-k]/fib[N-1-k]*(b-a);
            yf = a;
        }
        cout<<z<<" "<<y<<endl;
    }
    z = y;
    z_last=y+EPS;

    if(f(y)<=f(z_last)){
        b=z_last;
    }
    else{
        a=y;
    }
    double min = (a+b)/2.0;
    out << min << " " << f(min) << " " << "min" << endl;
    return (a+b)/2.0;
}

int main(){
    double a0 = 0.0, b0 = 10.0, l = 1.0, epsilon = 0.001;
    int steps=0;
    double yf=0 ,zf=0;
    double xmin = fibonacci_method(a0,b0,l,epsilon,steps,yf,zf,"out.txt");
    steps--;
    func(0.0, 10.0, "func.txt");

    cout<< "X*: " <<xmin<<endl;
    cout<< "f(x): " <<f(xmin)<<endl;
    cout << "[ " << yf << " ; " << zf << " ]"<<endl;
    cout<< "steps: " <<steps<<endl;
    cout << "N: " << 2*steps <<endl;
    cout << "R: " << R(2*steps+1) <<endl;
}