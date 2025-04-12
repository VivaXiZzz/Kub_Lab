// 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    //    int a[10], n, b = 0,sum=0;
    //    cin >> n;
    //    for (int i = 0;i < n;i++) { cin >> a[i]; }
    //    for (int i = 0;i < n;i++) {
    //        b = 0;
    //        for (int j = 1;j < a[i];j++) {
    //            if (a[i] % j == 0)b += j;
    //        }
    //        if (b == a[i])sum += a[i];
    //    }
    //    cout << sum;
    //}

    //    int a[10], n, sum = 0;
    //    float b=0;
    //    cin >> n;
    //    for (int i = 0;i < n;i++) { cin >> a[i]; }
    //    for (int i = 0;i < n;i++) {
    //        b += a[i];
    //    }
    //    b /= n;
    //    for(int i =0;i<a[i];i++){
    //        if (a[i] > b)sum++;
    //    }
    //    cout << sum;
    //}

//    int a[10], n, b[10], sum = 0;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        b[i] = a[i] * a[i];
//    }
//    for (int i = 0;i < n;i++) { cout << b[i] << " "; }
//}

//    int a[10], n, b = 0, sum = 0, a1;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        a1 = a[i];
//        while (a1) {
//            b += a1 % 10;
//            a1 /= 10;
//        }
//        if (b % 2 == 0)sum++;
//    }
//    cout << sum;
//}

//    int a[10], n, sum = 0,a1;
//    bool b;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        b = 0;
//        a1 = a[i];
//        while (a1) {
//            if (a1 % 10 == 0)b = 1;
//            a1 /= 10;
//        }
//        if (b)sum++;
//    }
//    cout << sum;
//}

//    int a[10], n, b = 0, sum=0,a1,sam; проверка на соверешнность и 2 случая
//    bool f;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        b = 0;
//                for (int j = 1;j < a[i];j++) {
//                    if (a[i] % j == 0)b += j;
//                }
//                if (b == a[i])sum++;
//    }
//    if (sum) {
//        b = 0;
//        for (int i = 0;i < n;i++) {
//            sam = 0;
//            for (int i = 1;i < a[i];i++) { if (a[i] % i == 0)sam++; }
//            if (sam==2)b += a[i];
//        }
//    }
//    else {
//        b = 1;
//        for (int i = 0;i < n;i++) {
//            f = 0;
//            a1 = a[i];
//            while (a1) {
//                if (a[i] % 10 == 4)f = 1;
//                a1 /= 10;
//            }
//            if (f)b *= a[i];
//        }
//    }
//    cout << b;
//}

//int a[10], n, b = 0, sum = 0,imax;
//bool f = 0;
//cin >> n;
//for (int i = 0;i < n;i++) { cin >> a[i]; }
//imax = a[0];
//for (int i = 0;i < n;i++) { if (imax < a[i])imax = a[i]; }
//if (imax % 2 == 0)f = 1;
//if (f) {
//    for (int i = 0;i < n;i++)
//        if (a[i] < 0)a[i] = abs(a[i]);
//}
//else {
//    for (int i = 0;i < n;i++) if (a[i] > 0)a[i] = imax;
//}
//for (int i = 0;i < n;i++) { cout<<a[i]<<" "; }
//}

//int a[10], n, b[10], sum = 0, imax=0;
//bool f = 0;
//cin >> n;
//for (int i = 0;i < n;i++) { cin >> a[i]; }
//for (int i = 0; i < n;i++) {
//    sum = a[i];
//    while (sum) {
//        imax += sum % 10;
//        sum /= 10;
//    }
//
//}
//cout << imax;
//}

//    int a[10], n, b = 0, sum, imax = 0, f = NULL;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        imax = 0;
//        sum = a[i];
//        while (sum) {
//            imax += sum % 10;
//            sum /= 10;
//        }
//        if (imax > b)b = imax, f = i+1;
//    }
//    cout << f;
//}

//    int a[10], n, b[10], imax;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        imax = 1;
//        for (int j = 0;j < i;j++) 
//            imax *= a[i];
//        b[i] = imax;
//    }
//    for (int i = 0;i < n;i++)cout << b[i] << " ";
//}

//    int a[10], n, b, sum, sam = 0;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        sum = a[i];
//        b = 0;
//        while (sum) {
//            b += sum % 10;
//            sum /= 10;
//        }
//        if (b % 2 == 0)sam++;
//    }
//    cout << sam;
//}

//int a[10], n, b = 0, sum, imax = 0;
//bool f = 1;
//cin >> n;
//for (int i = 0;i < n;i++) { cin >> a[i]; }
//for (int i = 0;i < n-1;i++) {
//    if (a[i] <= a[i + 1])f = 0;
//}
//if (f) {
//    for (int i = 0;i < n;i++) {
//        if (a[i] > 0)a[i] = 0;
//    }
//}
//else {
//    for (int i = 0;i < n;i++) {
//        if (a[i] < 0)a[i] = abs(a[i]);
//    }
//}
//for (int i = 0;i < n;i++) {
//    cout << a[i] << " ";
//}
//}

//int a[10], n, b = 0, sum, imax = 0, f = NULL;что не так с 14
//cin >> n;
//for (int i = 0;i < n;i++) { cin >> a[i]; }
//for (int i = 0;i < n;i++) {
//    b = 0;
//    for (int i = 2;i <= a[i];i++) {
//        if (a[i] % i == 0)b++;
//        sum = a[i] % i;
//    }   
//    if (b == 1)imax++;
//}
//if (imax >= 2) {
//    for (int i = 0;i < n;i++)if (a[i] % 2 == 0)a[i] *= 2;
//}
//else {
//    for (int i = 0;i < n;i++)if (10 < a[i] < 100)a[i] -= 3;
//}
//for (int i = 0;i < n;i++) cout << a[i] << " ";
//}
    int a[10], n, b = 0, sum = 0, imax = 0, f = NULL;
    cin >> n;
    for (int i = 0;i < n;i++) { cin >> a[i]; }
    imax = a[0];
    for (int i = 0;i < n;i++)if (a[i] > imax)imax = a[i];
    for (int i = 0;i < n;i++)if (a[i] == imax)b++;
    if (b >= 2) {
        for (int i = 0;i < n;i++)if (a[i] % 3 == 0)sum += a[i];
    }
    else {
        for (int i = 0;i < n;i++)if (a[i] % 2 == 0)sum++;
    }
cout<<sum;
}
