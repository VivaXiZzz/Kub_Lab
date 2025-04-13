// 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		for (int i = 1;i < a;i++) {
//			if (a % i == 0)d1 += i;
//		}
//		if (d1 == a)c++;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		bool d1 = 0, d2 = 0;
//		int x = a;
//		for (;x;) {
//			if (x % 10 % 5==0)d1 = 1;
//			if (x% 10 % 3==0)d2 = 1;
//			x /= 10;
//		}
//		if (!d1&&d2)c+=a;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		for (;a;) {
//			d1+=a%10;
//			a /= 10;
//		}
//		if (d1%2 == 0)c++;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 1;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		d2 = a;
//		for (;d2;) {
//			d1+=d2%10;
//			d2 /= 10;
//		}
//		if (d1%4 == 0)c*=a;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		for (;a;) {
//			d1+=a%10;
//			a /= 10;
//		}
//		for (int i = 2;i <=d1;i++) {
//			if (d1 % i == 0)d2++;
//		}
//		if (d2 == 1)c++;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		for (int i = 2;i<=a;i++) {
//			if (a % i == 0)d1++;
//		}
//		cin >> b;
//		if (d1 == 1&&b%2==0)c+=a;
//		a = b;
//	}
//	cout << c;
//}

//	int a, b, c = 0;
//	cin >> a;
//	while (a) {
//		int d1 = 0, d2 = 0;
//		for (;a>9;) {
//			a /= 10;
//		}
//		if (a == 2)c++;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//int a, b, c = 0;
//cin >> a;
//while (a) {
//	int d1 = 0, d2 = 0,b1,a1=a;
//	for (int i=2;i<=a1;i++) {
//		if (a1 % i == 0)d1++;
//	}
//	cin >> b;
//	b1 = b;
//	for (;b1>9;) {
//		if(b1%10==3)d2++;
//		b1 /= 10;
//	}
//	if (d1==1&&(d2||b1%10==3))c+=a;
//	a = b;
//}
//cout << c;
//}