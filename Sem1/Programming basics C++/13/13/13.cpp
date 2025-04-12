// 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
//    int n, a1, s = 0;
//    cin >> n;
//    int *a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin >> a[i];
//        a1 = 0;
//        for (int p = 1;p < a[i];p++)
//            if (a[i] % p == 0)a1 += p;
//        if (a1 == a[i])s += a[i];
//    }
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    cout <<endl<< s;
//}

//    int n, a1;
//    float s = 0;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        a[i]=rand()%100;
//        s += a[i];
//    }
//    s /= n;
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    cout << endl << s;
//}

//    int n, a1,s,k=0;
//    float;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        a[i] = rand() % 100;
//        a1 = a[i];
//        s = 0;
//        for (;a1;) {
//            s += a1 % 10;
//            a1 /= 10;
//        }
//        if (s % 2 == 0)k++;
//    }
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    cout << endl << k;
//}

//    int n, a1, s, k = 0;
//    float;
//    bool f;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin>>a[i];
//        a1 = a[i];
//        f = 0;
//        for (;a1;) {
//            if(a1%10==0)f=1;
//            a1 /= 10;
//        }
//        if (f)k++;
//    }
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    cout << endl << k;
//}

//    int n, a1, s, max=0;
//    float;
//    bool f;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        a[i]=rand()%100;
//    }
//    a1 = a[0];
//    for (;a1;) {
//        max += a1 % 10;
//        a1 /= 10;
//    }
//
//    for(int i =1;i<n;i++){
//        a1 = a[i];
//        s = 0;
//        for (;a1;) {
//            s+=a1%10;
//            a1 /= 10;
//        }
//        if (s>max)max=s;
//    }
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    cout << endl << max;
//}

//    int n, a1, s, max = 0;
//    float;
//    bool f=1;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0;i < n;i++) {
//        cin>>a[i];
//    }
//    for (int i = 0;i < n-1;i++) {
//        if (a[i] <= a[i + 1])f = 0;
//    }
//    if (f) {
//        for (int i = 0;i < n;i++)
//            if (a[i] > 0)a[i] = 0;
//    }
//    else {
//        for (int i = 0;i < n;i++)
//            if (a[i] < 0)a[i] = abs(a[i]);
//    }
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//}

//int n, a1, s, max = 0;
//float;
//bool f = 0;
//cin >> n;
//int* a = new int[n];
//for (int i = 0;i < n;i++) {
//    cin >> a[i];
//}
//for (int i = 0;i < n;i++) {
//    s = 0;
//    for (int p = 1;p <= a[i];p++)if (a[i] % p == 0)s++;
//    if (s == 2)max++;
//}
//if (max >= 2)f = 1;
//if (f) {
//    for (int i = 0;i < n;i++)
//        if (a[i]%2==0)a[i] *= 2;
//}
//else {
//    for (int i = 0;i < n;i++)
//        if (9<a[i]&&a[i]<100)a[i] -= 3;
//}
//for (int i = 0;i < n;i++)
//    cout << a[i] << " ";
//}

int n, a1, s=0, max;
float;
bool f = 0;
cin >> n;
int* a = new int[n];
for (int i = 0;i < n;i++) {
    cin >> a[i];
}
max = a[0];
for (int i = 1;i < n;i++) {
    if (max < a[i])max = a[i];
}
for (int i = 0;i < n;i++) {
    if(a[i]==max)s++;
}
if (s >= 2)f = 1;
s = 0;
if (f) {
    for (int i = 0;i < n;i++)
        if (a[i] % 3 == 0)s += a[i];
}
else {
    for (int i = 0;i < n;i++)
        if (a[i]%2==0)s++;
}
    cout << s;
}