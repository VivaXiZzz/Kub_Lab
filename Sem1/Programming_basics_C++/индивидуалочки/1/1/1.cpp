#include <iostream>
using namespace std;
int main()
{//получаем числа фибоначчи из последовательности в n элементов
	int n,num, amount=0;
	cout << "input n of num"<<endl;
	cin >> n;
	cout << "input nums" << endl;
	for (int i = 0;i < n;i++) {
		int f1 = 0, f2 = 1, f3=0;
		cin >> num;
		for (;f3<=num;) {
			if (num == f3)amount++;
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}
	cout <<"amount of require num = "<< amount;
}

