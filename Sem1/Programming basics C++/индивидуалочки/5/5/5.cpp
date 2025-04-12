// 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(0, "Russain");
    struct tovar
    {
        string name;
        string country;
        string sort;
        int price;
        int mass;
    };
    int n,r,mn,mx;
    cout << "введите кол-во товаров"<<'\n';
    cin >> n;
    tovar* a = new tovar[n];
    for (int i = 0;i < n;i++) {
        cout << "введите название товара,страну,сорт,цену,вес"<<'\n';
        cin >> a[i].name;
        cin >> a[i].country;
        cin >> a[i].sort;
        cin >> a[i].price;
        cin >> a[i].mass;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (char(a[j].name[0]) > char(a[j + 1].name[0])) {
                tovar b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
    mn = mx = a[0].price;
    for (int i = 1;i < n;i++) {
        if (a[i].price > mx)mx = a[i].price;
        if (a[i].price < mn)mn = a[i].price;
    }
    r = mx - mn;
    for (int i = 0;i < n;i++) {
        if (a[i].price < r)
            cout << a[i].name;
    }
}

