// ФИНАЛОЧКА.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{ //1
//	int a, b;
//	float c,p;
//	cin >> a >> b;
//	c = sqrt(a * a + b * b);
//	p = a + b + c;
//cout << c << " "<< p;
//}

// 2
//	int x1, x2, y1, y2;
//	float r;
//	cin >> x1 >> x2 >> y1 >> y2;
//	r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
//	cout << r;
//}

// 3
//	int x, y;
//	cin >> x >> y;
//	if (x > 0) {
//		if (y > 0)cout << "1";
//		if (y < 0)cout << "2";
//	}
//	if (x < 0) {
//		if (y > 0)cout << "4";
//		if (y < 0)cout << "3";
//	}
//}

//4
//	int x, y, z, p = 0;
//	cin >> x >> y >> z;
//	if ((z < 10 && z>0) || (y < 10 && y>0) || (x < 10 && x>0)) {
//		if (x > 0 && x % 2 == 1)p += x;
//		if (y > 0 && y % 2 == 1)p += y;
//		if (z > 0 && z % 2 == 1)p += z;
//	}
//	cout << p;
//}

//5
//	int x, y;
//	cin >> x >> y;
//	if ((x == y * y) || (y == x * x))cout << "odin kv drugogo";
//}

//6
//	int a, b = 0;
//	cin >> a;
//	while (a)
//	{
//		if(a%2==0) b+=a%10;
//		a /= 10;
//	}
//	cout << b;
//}

//7
//	int a, b, c=0;
//	cin >> a;
//	while (a != 0) {
//		cin >> b;
//		if (a > -100 && a < -9)c += a * a;
//		a = b;
//	}
//	cout << c;
//}

//8
//	int a, b, c;
//	cin >> a;
//	b = a;
//	if (a % 2 == 0)c = a;
//	for (;a != 0;) {
//		if (b % 2 == 0 && c > b)c = b;
//		cin >> b;
//		a = b;
//	}
//	cout << c;
//}

//9
//	int n, k, s = 0;//k>0 and <10
//	cin >> n >> k;
//	for (int i = 1;i < n;i++) {
//		if (n % i == 0 && i % 10 == k)s += i;
//	}
//	cout << s;
//}

//10
//	int a, b;
//	cin >> a >> b;
//	for (int i = a;i <= b;i++) {
//		int a1 = 0;
//		for (int j = 1;j < i;j++) {
//			if (i % j == 0)a1 += j;
//		}
//		if (a1 == i)cout << i<< " ";
//	}
//}

//11
//	int a[5], k = 0;
//	for (int i = 0;i < 5;i++) {
//		cin >> a[i];
//		if ((i+1) % 3 != 0 && a[i] % 2 == 0)k++;
//	}
//	cout << k;
//}

//12
	int n;
	float s=0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		s += a[i];
	}
	s /= n;
	for (int i = 0;i < n;i++) {
		if (a[i] <= s)cout << a[i] << " ";
	}
}