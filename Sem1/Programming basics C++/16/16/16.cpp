// 16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int rec1(int n) {
    if (n == 0)return 1;
    return 2 * rec1(n - 1) + 1;
}

int rec2(int n) {
    if (n == 0)return 1;
    if (n == 1)return 2;
    return 2 * rec2(n - 1) + 3 * rec2(n - 2);
}

int rec3(int n) {
    if (n == 0)return 1;
    if (n == 1)return 2;
    return rec3(n - 1) + 2 * rec3(n - 2);
}
int msn(int n) {
    if (n == 0) return 0;
    return msn(n / 10) + n % 10;
}

int mcn(int n){
    if (n == 0) return 0;
    return msn(n / 10) + (n%2==0);
}

bool cn6(int n) {
    if (n == 0) return 0;
    if (n % 10 == 6) { n = 0; return 1; }
    return(n / 10);
}


int sc(int* x,int n) {
    if (n == 0)return 0;
    if (x[n] % 2 == 0)return sc(x, n - 1) + x[n];
    return sc(x,n-1);
}

void udc(int* x, int n,int sum) {
    if (n != 0){
    if (x[n] > 9 && x[n] < 100) { x[n] +=sum;return udc(x, n - 1, sum); }
    return udc(x, n - 1, sum);}
}

int prchet(int* x, int n) {
    if (n == 0)return x[n];
    if ((x[n] % 2 == 0) && (n%3!=0))return sc(x, n - 1)*x[n];
    return sc(x, n - 1);        
}

void zam(int* x, int n, int sum) {
    if (n != 0) {
        if (x[n] % 5 == 0) { x[n] += sum;return udc(x, n - 1, sum); }
        return udc(x, n - 1, sum);
    }
}

int main()
{
    //    int n;
    //    cin >> n;
    //    cout<<rec1(n)<<'\n';
    //    cout <<rec2(n)<<'\n';
    //    cout <<rec3(n);
    //}

//    int n,max=0;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin >> a[i];
//        if (msn(a[i]) > max)max = msn(a[i]);
//    }
//    cout << max;
//}

//    int n, max = 0,i1;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin >> a[i];
//        if (mcn(a[i]) > max)max = msn(a[i]),i1=i;
//    }
//    cout << i1+1;
//}

//    int n, sum=0;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin >> a[i];
//        if (cn6(a[i]))sum += a[i];
//    }
//    cout << sum;
//}

//    int n, su;
//    cin >> n;
//    int *b = new int[n];
//    for (int i = 0;i < n;i++)
//        cin >> b[i];
//    su = sc(b, n);
//    udc(b, n, su);
//    for (int i = 0;i < n;i++)
//        cout << b[i]<<" ";
//}

    int n, su;
    cin >> n;
    int* b = new int[n];
    for (int i = 0;i < n;i++)
        cin >> b[i];
    su = prchet(b, n);
    cout << su << '\n';
    zam(b, n, su);
    for (int i = 0;i < n;i++)
        cout << b[i] << " ";
}