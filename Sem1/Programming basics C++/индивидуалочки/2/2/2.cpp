#include <iostream>
using namespace std;
int main()
{//сумма ряда который по обьективным причинам я сюда вписать не могу...
    int n, ed = -1, fact = 1;
    float E=0;
    cout << "input amount of iterations of sigma" << endl;
    cin >> n;
    ed *= -1;
    for (int i = 1; i <= n; i++) {
        ed *= (-1) * (-1);//я знаю что это бессмысленно но такого условие задачи
        fact *= i;
        E += (float)ed / fact;
    }
    cout << "value of sigma = " << E;
}
