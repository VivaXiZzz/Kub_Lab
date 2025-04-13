// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
//    float n,x=0, a[10];
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        if (a[i] > 0)x++;
//    }
//    cout << x;
//}

//    int n, x = 0, a[10];
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        if ((i+1)%2==0)x+=a[i];
//    }
//    cout << x;
//}

//    int n, a[10],c=0;
//    float x = 0;
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        if (a[i] > 0)c++, x+=a[i];
//    }
//    x = (float)x / c;
//    cout << x;
//}

//    int n, x = 1, a[10];
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        if ((i+1)%2!=0&&a[i]%2==0)x*=a[i];
//    }
//    cout << x;
//}

//    float n, x = 0, a[10];
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    x = a[0];
//    for (int i = 0;i < n;i++) {
//        if (a[i]>x)x=a[i];
//    }
//    cout << x;
//}

//    int n, x = 1, a[10];
//    cin >> n;
//    for (int i = 0;i < n;i++) { cin >> a[i]; }
//    for (int i = 0;i < n;i++) {
//        if (a[i]%3==0)x*=a[i];
//    }
//    cout << x;
//}

    float n, x = 0, a[10];
    cin >> n;
    for (int i = 0;i < n;i++) { cin >> a[i]; }
    for (int i = 0;i < n;i++) {
        a[i] = a[i] * a[i];
        cout << a[i] << "; ";
    }

}