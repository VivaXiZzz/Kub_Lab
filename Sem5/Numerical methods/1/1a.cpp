#include <iostream>
#include <fstream>
using namespace std;

const float eps=1e-9;

int main(){
    double** matrix;
    int n;
    ifstream f("1in.txt");
    f >> n;
    double* vector = new double[n];
    double* ans = new double[n];
    matrix = new double*[n];
    for(int i=0;i<n;++i){
        matrix[i] = new double[n];
        for(int j=0;j<n;++j)
            f >> matrix[i][j];
    }
    for(int i=0;i<n;++i){
        f >> vector[i];
    }
    f.close();

    //начало прямого хода
    for(int i=0;i<n;++i){
        int max_element = i;
        for(int j=max_element+1;j<n;++j){
            if(matrix[max_element][j]<matrix[i][j])max_element=i;
        }
        for(int k=0;k<n;++k){
            swap(matrix[i][k],matrix[max_element][k]);
        }
        swap(vector[i],vector[max_element]);
        for(int j=i+1;j<n;++j){
            double menace = matrix[j][i]/matrix[i][i];
            for(int p=i;p<n;++p)
                matrix[j][p] -= menace * matrix[i][p];
        vector[j] -= menace * vector[i];
        }
    }
    //конец прямого хода

    //начало обратного хода
    for(int i = n-1; i>=0; --i){
        double sum=0;
        for(int j=i+1; j<n; ++j){
            sum += matrix[i][j]*ans[j];
        }
        ans[i] = (vector[i] - sum) / matrix[i][i];
    }
    //конец обратного хода

    ofstream fout("1out.txt");
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
        fout << ans[i] << " ";
    }

    for(int i=0;i<n;++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] vector;
    delete[] ans;

    return 0;
}