#include <iostream>
using namespace std;
int main()
{//массив целых если он симметричен найти кол-во совершенных иначе уменьшить все элементы на 3
    int a[10], n, x, num = 0;
    bool f = 0;
    cout << "input amount of nums in array" << endl;
    cin >> n;
    cout << "input nums" << endl;
    for (int i = 0;i < n;i++)cin >> a[i];
    for (int i = 0;i < n / 2 + 1;i++) {
        if (a[i] != a[n - i - 1])f = 1;
    }
    if (!f) {
        for (int i = 0;i < n;i++) {
            x = 0;
            for (int j = 1;j < a[i];j++) { if (a[i] % j == 0)x += j; }
            if (x == a[i])num++;
        }
    }
    else {
        for (int i = 0;i < n;i++)a[i] -= 3;
    }
    if (!f)cout << "amount of require num = " << num;
    else {
        cout << "array = ";
        for (int i = 0;i < n;i++)cout << a[i] << " ";
    }
}

