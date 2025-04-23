#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
const double EPS =1e-07;

double f(vector<double> x){
    return pow(x[0],2)+5*pow(x[1],2)-x[0]*x[1]+x[0];
}

//double f(vector<double> x){
//    return 2*pow(x[0],2)+x[0]*x[1]+pow(x[1],2);
//}

vector<double> gradient(vector<double> v){
    vector<double> g;
    double init;
    for(int i=0;i<size(v);++i){
        init = f(v);
        v[i]+=EPS;
        g.push_back((f(v)-init)/EPS);
        v[i]-=EPS;
    }
    return g;
}

double p(vector<double> v,double t,vector<double>d){
    vector<double> dv;
    for(int i=0;i<size(v);++i){
        dv.push_back(v[i]+t*d[i]);
    }
    return f(dv);
}

double norm(vector<double> v){
    double sum = 0;
    for(int i=0;i<size(v);++i)
        sum+=pow(v[i],2);
    return sqrt(sum);
}

double norm_razn(vector<double> v1,vector<double> v2){
    double sum = 0;
    for(int i=0;i<size(v1);++i){
        sum+=pow(v1[i]-v2[i],2);
    }
    return sqrt(sum);
}

vector<double> minus_grad(vector<double> v){
    for(int i=0;i<size(v);++i)
        v[i]=-v[i];
    return v;
}

vector<double> dsum(vector<double>grad,vector<double> d,double beta){
    vector<double> v;
    for(int i=0;i<size(grad);++i){
        v.push_back(-grad[i]+beta*d[i]);
    }
    return v;
}

double dichotomy_method(vector<double> v,vector<double> d,double a=0, double b=1, double l=0.05, double epsilon =0.005) 
{
    int k = 0;
    double y,z;
    while (b - a >= l) {

        y = (a + b - epsilon) / 2.0;
        z = (a + b + epsilon) / 2.0;
        
        double fy = p(v,y,d);
        double fz = p(v,z,d);

        if (fy < fz) {
            b = z;
        } else {
            a = y;
        }
    }
    double min = (a+b)/2.0;
    return (a + b) / 2.0;
}

vector<double> grad_min(vector<double>&v,int&steps,string&exit,double EPS1=0.1,double EPS2=0.15,int m = 10){
    fstream fin("points.txt");
    int p=0;
    double norma,norma_pred,t,beta;
    vector<double> grad,vtemp,d;
    fin<<v[0]<<" "<<v[1]<<endl; //график будет только для функции 2ух переменных
    for(int k=0;k<m;++k){
    steps = k; // чтобы узнать N не более
    vtemp = v;
    grad = gradient(v);
    if(k!=0)norma_pred=norma;
    if(k==0) d = minus_grad(grad);
    norma = norm(grad);
    if(norma<EPS1){
        exit = "EPS1";
        return v;
    }
    if(k!=0){beta = pow(norma,2) / pow(norma_pred,2);
    d = dsum(grad,d,beta);
    }
    t = dichotomy_method(v,d);
    for(int i=0;i<size(v);++i){
        v[i]+=t*d[i];
        fin<<v[i]<<" "; //...
    }
    fin<<endl; //...
    if((norm_razn(v,vtemp)<EPS2)&&abs(f(v)-f(vtemp))<EPS2)p++;
    else p=0;
    if(p==2){
        exit = "EPS2";
        steps;
        return v;}
    }
    exit = "M";
    return v;
}

int main(){
    int steps;
    string exit;
    vector<double> initial = {-1.2,1};
    vector<double> vmin = grad_min(initial,steps,exit);
    double fmin = f(vmin);
    cout<<"X_min = [ ";
    for(auto i:vmin)
        cout<<i<<" ";
    cout<<"]"<<endl<<"f(X_min) = "<<fmin<<endl<<"N = "<<steps+1<<endl<<"exit: "<<exit<<endl;
}
