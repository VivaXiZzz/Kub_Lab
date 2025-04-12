// 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    //    const int n = 3;
    //    int a[n][n], imax,k;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            a[i][j] = rand() % 10+1;
    //    imax = a[0][0];
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            if(imax<a[i][j])imax=a[i][j];
    //    cout << endl;
    //    for (int i = 0;i < n;i++) {
    //        for (int j = 0;j < n;j++) {
    //            k=0;
    //            for (int p = 1;p <= a[i][j];p++)if (a[i][j] % p == 0)k++;
    //            if (k == 2)a[i][j] = imax;
    //            }
    //        }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //}

    //    const int n = 3;
    //    int a[n][n], imax, k=0;
    //    bool f;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin>>a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        f = 1;
    //        for (int j = 0;j < n-1;j++) {
    //            if (a[i][j] >= a[i][j+1])f=0;
    //        }
    //        if (f)k++;
    //    }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    cout << endl << k;
    //}


    //    const int n = 3;
    //    int a[n][n], imax, k = 0;
    //    bool f;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin >> a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        f = 1;
    //        for (int j = 0;j < n;j++) {
    //            if (a[i][j] != a[i][n - j - 1])f = 0;
    //        }
    //        if (f)k++;
    //    }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    cout << endl << k;
    //}

    //    const int n = 5;
    //    int a[n][n], imax,imin,i1,i2,s;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            a[i][j] = rand() % 20+1;
    //    imax = a[0][0];
    //    imin = a[0][0];
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    for (int i = 0;i < n;i++) {
    //        for (int j = 0;j < n;j++) {
    //            if (imax < a[i][j])imax = a[i][j], i1 = i;
    //            if (imin > a[i][j])imin = a[i][j], i2 = i;
    //        }
    //    }
    //    cout << endl << i1<< " " << i2 << endl;
    //        for (int j = 0;j < n;j++) {
    //            s = a[i1][j];
    //            a[i1][j] = a[i2][j];
    //            a[i2][j] = s;
    //            }
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //}

    //    const int n = 3;
    //    int a[n][n],k,p=0,a1,s=0;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin>>a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    cout << endl;
    //    for (int i = 0;i < n;i++) {
    //            k=0;
    //            for (int p = 1;p < a[i][n-i-1];p++)if (a[i][n-i-1] % p == 0)k+=p;
    //            if (a[i][n-i-1] == k)s++;
    //    }
    //    cout << s;
    //}

    //const int n = 3;
    //    int a[n][n],imax=0,a1,k ;
    //    float;
    //    for (int i = 0;i < n;i++)
    //        for (int j = 0;j < n;j++)
    //            cin>>a[i][j];
    //    for (int i = 0;i < n;i++) {
    //        cout << endl;
    //        for (int j = 0;j < n;j++)
    //            cout << a[i][j] << " ";
    //    }
    //    cout << endl;
    //    for (int i = 0;i < n;i++) {
    //            a1=a[i][i];
    //            k = 0;
    //            for (;a1;) {
    //                k += a1 % 10;
    //                a1 /= 10;
    //            }
    //            if(imax<k)imax=k;
    //    }
    //    cout << imax;
    //}

//    const int n = 3;
//    int a[n][n], s1, s2, z;
//    float;
//    cin >> s1;
//    cin >> s2;
//    for (int i = 0;i < n;i++)
//        for (int j = 0;j < n;j++)
//            a[i][j] = rand() % 10;
//    for (int i = 0;i < n;i++) {
//        cout << endl;
//        for (int j = 0;j < n;j++)
//            cout << a[i][j] << " ";
//    }
//    cout << endl;
//    for (int i = 0;i < n;i++) {
//        z = a[i][s1];
//        a[i][s1] = a[i][s2];
//        a[i][s2] = z;
//    }
//    for (int i = 0;i < n;i++) {
//        cout << endl;
//        for (int j = 0;j < n;j++)
//            cout << a[i][j] << " ";
//    }
//}

//    const int n = 3;
//    int a[n][n], k = 0;
//    bool f;
//    for (int i = 0;i < n;i++)
//        for (int j = 0;j < n;j++)
//            cin>>a[i][j];
//    for (int i = 0;i < n;i++) {
//        cout << endl;
//        for (int j = 0;j < n;j++)
//            cout << a[i][j] << " ";
//    }
//    cout << endl;
//    for (int i = 0;i < n;i++) {
//        f = 1;
//        for (int j = 0;j < n - 1;j++) {
//            if (a[j][i] <= a[j+1][i])f = 0;
//        }
//        if (f)k++;
//    }
//    cout << k;
//}

//    const int n = 3;
//    int a[n][n],k=0,a1;
//    bool f;
//    for (int i = 0;i < n;i++)
//        for (int j = 0;j < n;j++)
//            cin>>a[i][j];
//    for (int i = 0;i < n;i++) {
//        cout << endl;
//        for (int j = 0;j < n;j++)
//            cout << a[i][j] << " ";
//    }
//    cout << endl;
//    for (int i = 0;i < n;i++) {
//        a1 = a[i][n - i - 1];
//        f = 0;
//        for(;a1;) {
//            if (a1 % 10 == 5)f = 1;
//            a1 /= 10;
//        }
//        if (f)k++;
//    }
//    cout << k;
//}

//const int n = 3;
//int a[n][n], k = 0, a1,f;
//bool;
//for (int i = 0;i < n;i++)
//    for (int j = 0;j < n;j++)
//        cin >> a[i][j];
//for (int i = 0;i < n;i++) {
//    cout << endl;
//    for (int j = 0;j < n;j++)
//        cout << a[i][j] << " ";
//}
//cout << endl;
//for (int i = 0;i < n;i++) {
//    for (int j = 0;j < n;j++) {
//        a1 = a[i][j];
//        f = 0;
//        for (;a1;) {
//            if (a1 % 10 == 1)f += 1;
//            a1 /= 10;
//        }
//        if (f>=2)k+=a[i][j];
//    }
//}
//cout << k;
//}

//const int n = 3;
//int a[n][n], k = 0, a1,x;
//bool f;
//cin >> x;
//for (int i = 0;i < n;i++)
//    for (int j = 0;j < n;j++)
//        cin >> a[i][j];
//for (int i = 0;i < n;i++) {
//    cout << endl;
//    for (int j = 0;j < n;j++)
//        cout << a[i][j] << " ";
//}
//cout << endl;
//    for(int j=0;j<n;j++){
//        if (a[x][j] > 0)k++;
//}
//    if (k >= 2) {
//        for (int i = 0;i < n;i++) {
//            for (int j = 0;j < n;j++) {
//                a[i][j] = 1;
//            }
//        }
//    }
//    else{
//                for (int i = 0;i < n;i++) {
//            for (int j = 0;j < n;j++) {
//                a[i][j] = 0;
//            }
//        }
//    }
//
//    for (int i = 0;i < n;i++) {
//        cout << endl;
//        for (int j = 0;j < n;j++)
//            cout << a[i][j] << " ";
//    }
//}

    const int n = 3;
    int a[n][n], k, x, s=0;
    bool f;
    cin >> x;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> a[i][j];
    for (int i = 0;i < n;i++) {
        cout << endl;
        for (int j = 0;j < n;j++)
            cout << a[i][j] << " ";
    }
    cout << endl;
    for (int j = 0;j < n;j++) {
        k = 0;
        for (int p = 1;p<=a[x][j];p++) {
            if (a[x][j] % p == 0)k++;
        }
        if (k == 2)s += a[x][j];
    }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                a[i][j] = s;
            }
        }
    for (int i = 0;i < n;i++) {
        cout << endl;
        for (int j = 0;j < n;j++)
            cout << a[i][j] << " ";
    }
}