// 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    //    const int n = 3;
    //    int a[n][n], x;
    //    bool b[n],f;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin >> a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        f = 1;
    //        for (int j = 0;j < n;j++) {
    //            if (a[i][j] != a[i][n - j - 1])f = 0;
    //        }
    //        b[i] = f;
    //    }
    //    for (int i = 0;i < n;i++)
    //        cout << b[i] << " ";
    //}

    //    const int n = 3;
    //    int a[n][n], min,s=0,a1;
    //    bool b[n], f;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin >> a[i][j];
    //    min = a[0][n - 1];
    //    for (int i = 0;i < n;i++) {
    //        if (min > a[i][n - i - 1])min = a[i][n - i - 1];
    //    }
    //    for (int i = 0;i < n;i++) {
    //        for (int j = 0;j < n;j++) {
    //            f = 1;
    //            a1 = a[i][j];
    //            while (a1) {
    //                if (a1 % 10 == 0)f = 0;
    //                a1 /= 10;
    //            }
    //            if (f&&a[i][j]>min)s += a[i][j];
    //        }
    //    }
    //    for (int i = 0;i < n;i++)
    //        a[0][i] = s;
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for(int j=0;j<n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //}

    //const int n = 3;
    //int a[n][n], min, s, a1=n;
    //bool b[n], f=1;
    //for (int i = 0;i < n;i++)
    //    for (int j = 0;j < n;j++)
    //        cin >> a[i][j];
    
    //for (int i = 0;i < n/2;i++)
    //    if (a[i][i] != a[i][n - i - 1])f = 0;
    
        //if (n % 2 != 0)a1 = a1 / 2 + 1;
    //    else a1 /= 2;
    //
    //    if(f) {
    //        for (int i = 0;i < n;i++) {
    //            for (int j = 0;j < a1;j++) {
    //                s = a[i][j];
    //                a[i][j] = a[i][n-j-1];
    //                a[i][n-j-1] = s;
    //            }
    //        }
    //    }
    //
    //    else {
    //        for (int i = 0;i < a1;i++) {
    //            for (int j = 0;j < n;j++) {
    //                s = a[i][j];
    //                a[i][j] = a[n - i - 1][j];
    //                a[n - i - 1][j] = s;
    //            }
    //        }
    //    }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //}

    //    const int n = 3;
    //    int a[n][n], max;
    //    bool b[n], f;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin >> a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        max = a[i][0];
    //        for (int j = 0;j < n;j++) {
    //            if (max < a[i][j])max = a[i][j];
    //        }
    //        for (int j = 0;j < n;j++) {
    //            if (a[i][j]%2==0)a[i][j]=max;
    //        }
    //    }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for(int j=0;j<n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //}

//    const int n = 3;
//    int a[n][n], s, k, b[n];
//    for (int i = 0;i < n;i++)
//        for (int j = 0;j < n;j++)
//            cin >> a[i][j];
//    for (int i = 0;i < n;i++) {
//        s = 0;
//        for (int j = 0;j < n;j++) {
//            k = 0;
//            for (int p = 1;p <= a[j][i];p++)if (a[j][i] % p == 0)k++;
//            if (k == 2)s += a[j][i];
//        }
//        b[i] = s;
//    }
//    for (int i = 0;i < n;i++) {
//        cout << b[i] << " ";
//    }
//}

//const int n = 3;
//int a[n][n], a1,s=0;
//bool b[n], f;
//for (int i = 0;i < n;i++)
//    for (int j = 0;j < n;j++)
//        cin >> a[i][j];
//for (int i = 0;i < n;i++) {
//    f = 1;
//    for (int j = 0;j < n-1;j++) {
//        if (a[i][j] >= a[i][j + 1])f = 0;
//    }
//    if (f) {
//        for (int j = 0;j < n;j++) {
//            a1 = a[i][j];
//            while (a1) {
//                s += a1 % 10;
//                a1 /= 10;
//            }
//        }
//        for(int j=0;j<n;j++)
//            a[i][j] = s;
//    }
//    else {
//        s = a[i][0];
//        for (int j = 0;j < n;j++) {
//            a[i][j] = s;
//        }
//    }
//}
//for (int i = 0;i < n;i++) {
//    cout << endl;
//    for (int j = 0;j < n;j++)
//        cout << a[i][j] << " ";
//}
//}

//const int n = 3;
//int a1, s = 0;
//bool f;
//float a[n][n], sred=0,b[n];
//for (int i = 0;i < n;i++)
//    for (int j = 0;j < n;j++)
//        cin >> a[i][j];
//
//for (int i = 0;i < n;i++) {
//    for (int j = 0;j < n;j++) {
//        sred += a[j][i];
//    }
//    sred /= n;
//    b[i] = sred;
//    }
//
//for (int i = 0;i < n;i++) {
//        cout << b[i] << " ";
//}
//}

const int n = 3;
int a1, s = 0,min;
bool f;
float a[n][n], proiz = 1, b[n];
for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
        cin >> a[i][j];

    min = a[0][n - 1];
    for (int i = 0;i < n;i++) {
        if (min > a[i][n - i - 1])min = a[i][n - i - 1];
    }

for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++) {
        a1 = a[i][j];
        f = 1;
        while (a1) {
            if (a1 % 10 == 5 || a1 % 10 == 3)f = 0;
            a1 /= 10;
        }
        if(f&&a[i][j]>min)proiz *= a[i][j];
    }
}
for (int i = 0;i < n;i++) {
    a[i][0] = proiz;
}

for (int i = 0;i < n;i++) {
    cout << endl;
    for(int j=0;j<n;j++)
    cout << a[i][j] << " ";
}
}