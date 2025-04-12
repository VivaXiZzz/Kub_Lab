#include <iostream>
#include <cstdlib>
using namespace std;

const double eps=1e-9;
const double dx=1e-7;
const int a=-100;
const int b=100;

double f(double x){
    return (x-2)*(x+2);
}

double Derivative(double dx,double x){
    return (f(x+dx)-f(x))/dx;   
}

double NewtonWithParam(double dx,double x,double m,int N){
    double x0=x;
    int i=0;
    double x1 = x0-m*f(x0)/Derivative(dx,f(x0));
    while((fabs(x1-x0)>eps)){//(f(x)>eps)&&(i<N)&&(fabs(x1-x0)>eps)
        if(fabs(Derivative(dx,f(x0)))<eps)
            throw runtime_error("производная близка к нулю - метод не применим");
        x1 = x0-m*f(x0)/Derivative(dx,x0);
        x0 = x1;
        //i++;
        }
    return x1;
}

double* LocalRoots(int a,int b,int&size){
    double*arr=nullptr;
    size=0;
    double i = a;
    while(i<b){
        //cout<<f(i)*f(i+1)<<endl;
        if(f(i)*f(i+0.1)<eps){
            size++;
            arr=(double*)realloc(arr,size*sizeof(double));
            arr[size-1]=(double)i;
        }
            //cout<<i<<" ";
        i+=0.1+dx;
    }
    return arr;
};

double* AllRoots(int a,int b,double m,int N,int&size){
    double* X0=LocalRoots(a,b,size);
    double* ans=new double[size];
    for(int i=0;i<size;i++){
        ans[i]=NewtonWithParam(dx,X0[i],m,N);
    }
    return ans;
}

int main(){
    setlocale(LC_ALL,"");
    int size=0; // не трогать
    double m=1; // параметр сходимости
    int N=100000000; // граница для остановки процесса
    double*ans=AllRoots(a,b,m,N,size);
    //cout<<"size"<<size;
    for(int i=0;i<size;i++)
        cout<<ans[i]<<" "
        ;
    //cout<<NewtonWithParam(dx,1.5,1,100);
}
//4b;