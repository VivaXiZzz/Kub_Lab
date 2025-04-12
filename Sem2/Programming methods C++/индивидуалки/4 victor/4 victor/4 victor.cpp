#include <iostream>
#include <vector>
using namespace std;

    struct tovar
    {
        string name;
        string country;
        string sort;
        int price;
        int mass;
    };

    int main()
    {
        system("chcp 1251");
        setlocale(0, "Russain");
        int n;
        cout << "введите кол-во товаров" << '\n';
        cin >> n;
        vector <tovar> a;
        a.resize(n);
        for (int i = 0;i < n;i++) {
//            a.push_back(tovar());
            cout << "введите название товара,страну,сорт,цену,вес" << '\n';
            cin >> a[i].name;
            cin >> a[i].country;
            cin >> a[i].sort;
            cin >> a[i].price;
            cin >> a[i].mass;
        }

        int mn = a.at(0).mass, mx = a[0].mass;
        for (int i = 1;i < n;++i)
        {
            if (mn > a[i].mass)mn = a[i].mass;
            if (mx < a[i].mass)mx = a[i].mass;
        }

        int raz = mx - mn;

        for (auto it = a.begin(); it != a.end();++it)
        {
            if (it->mass<raz)
            {
                it = a.erase(it);
            }
        }

        for (auto i : a)
        {
            cout << i.name << " " << i.country << " " << i.sort << " " << i.price << " " << i.mass<<"\n";
        }
}

