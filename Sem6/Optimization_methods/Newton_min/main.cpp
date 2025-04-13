#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const double EPS =1e-7;

double f(vector<double> x){
    return pow(x[0],2)+5*pow(x[1],2)-x[0]*x[1]+x[0];
}

vector<vector<double>> inversematrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> aug(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = matrix[i][j];
        }
        aug[i][n + i] = 1.0;
    }
    
    for (int i = 0; i < n; i++) {
        double pivot = aug[i][i];
        if (fabs(pivot) < 1e-9) {
            bool found = false;
            for (int k = i + 1; k < n; k++) {
                if (fabs(aug[k][i]) > 1e-9) {
                    swap(aug[i], aug[k]);
                    pivot = aug[i][i];
                    found = true;
                    break;
                }
            }
        }
        for (int j = 0; j < 2 * n; j++) {
            aug[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aug[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }
    
    vector<vector<double>> inv(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = aug[i][n + j];
        }
    }
    
    return inv;
}

double determinant(vector<vector<double>> matrix) {
    int n = matrix.size();
    
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[pivot][i])) {
                pivot = j;
            }
        }
        if (fabs(matrix[pivot][i]) < 1e-9) {
            return 0.0;
        }
        if (i != pivot) {
            swap(matrix[i], matrix[pivot]);
            det = -det;
        }
        det *= matrix[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return det;
}

bool ispositivedefinite(const vector<vector<double>>& matrix) {
    for (int k = 1; k <= matrix.size(); k++) {
        vector<vector<double>> submatrix(k, vector<double>(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                submatrix[i][j] = matrix[i][j];
            }
        }
        double det = determinant(submatrix);
        if (det <= 0) {
            return false;
        }
    }
    return true;
}

vector<double> gradient(vector<double> v){
    vector<double> g;
    vector<double> dv;
    double init;
    for(int i=0;i<size(v);++i){
        init = f(v);
        v[i]+=EPS;
        g.push_back((f(v)-init)/EPS);
        v[i]-=EPS;
    }
    return g;
}

double partial_differential(vector<double>&v,int v1,int v2){
    double sum=0;
    v[v1]+=EPS;
    v[v2]+=EPS;
    sum+=f(v);
    v[v2]-=2*EPS;
    sum-=f(v);
    v[v1]-=2*EPS;
    sum+=f(v);
    v[v2]+=2*EPS;
    sum-=f(v);
    v[v2]-=EPS;
    v[v1]+=EPS;
    return sum/4/EPS/EPS;
}

vector<vector<double>> hessian(vector<double> v){
    vector<vector<double>> matrix(size(v), vector<double>(size(v)));
    for(int i=0;i<size(v);++i){
        for(int j=0;j<size(v);++j){
            matrix[i][j]=partial_differential(v,i,j);
        }
    }
    return matrix;
}

void printmatr(vector<vector<double>> m){
    for(int i=0;i<size(m);++i){
        cout<<endl;
        for(int j=0;j<size(m);++j)
            cout<<m[i][j]<<" ";
    }
}

double p(vector<double> v,double t){
    vector<double> dv;
    vector<double> vg = gradient(v);
    for(int i=0;i<size(v);++i){
        dv.push_back(v[i]-t*vg[i]);
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

vector<double> dproiz(vector<vector<double>> m,vector<double> v){
    double sum;
    vector<double> sumv;
    for(int i=0;i<size(v);++i){
        sum = 0;
        for(int j=0;j<size(v);++j){
            sum+=m[i][j]*v[j];
        }
        sumv.push_back(-sum);
    }
    return sumv;
}

vector<double> invertedgrad(vector<double> v){
    for(int i=0;i<size(v);++i){
        v[i]=-v[i];
    }
    return v;
}

double dichotomy_method(vector<double> v,double a=0, double b=1, double l=0.05, double epsilon =0.005) 
{
    int k = 0;
    double y,z;
    while (b - a >= l) {

        y = (a + b - epsilon) / 2.0;
        z = (a + b + epsilon) / 2.0;
        
        double fy = p(v,y);
        double fz = p(v,z);

        if (fy < fz) {
            b = z;
        } else {
            a = y;
        }
    }
    double min = (a+b)/2.0;
    return (a + b) / 2.0;
}

vector<double> newton(vector<double>&v,int&steps,string&exit,double EPS1=0.1,double EPS2=0.15,int m = 10){
    fstream fin("points.txt");
    int p=0;
    double norma, t;
    vector<double> grad,vtemp,d;
    vector<vector<double>> h, h_;
    fin<<v[0]<<" "<<v[1]<<endl; //...
    for(int k=0;k<m;++k){
    steps = k; // чтобы узнать N не более
    vtemp = v;
    grad = gradient(v);
    if(norm(grad)<EPS1){
        exit = "EPS1";
        return v;
    }
    h = hessian(v);
    h_ = inversematrix(h);
    if(ispositivedefinite(h_)){
        d = dproiz(h_,grad);
        for (int i=0;i<size(v);i++){
            v[i]+=d[i];
            fin<<v[i]<<" "; //...
        }
    }
    else{
        d = invertedgrad(grad);
        t = dichotomy_method(v);
        for(int i=0;i<size(v);i++){
            v[i]+=t*d[i];
            fin<<v[i]<<" "; //...
        }
    }
    fin<<endl; //...
    if((norm_razn(v,vtemp)<EPS2)&&abs((f(v)-f(vtemp))<EPS2))p++;
    else p=0;
    if(p==2){
        exit = "EPS2";
        return v;}
    }
    exit = "M";
    return v;
}

int main(){
    int steps;
    string exit;
    vector<double> initial = {-1.2,1};
    vector<double> vmin = newton(initial,steps,exit);
    double fmin = f(vmin);
    cout<<"X_min = [ ";
    for(auto i:vmin)
        cout<<i<<" ";
    cout<<"]"<<endl<<"f(X_min) = "<<fmin<<endl<<"N = "<<steps+1<<endl<<"exit: "<<exit<<endl;
}