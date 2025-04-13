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
	int a, b = 0;
	cin >> a;
	while (a)
	{
		b += a % 10;
		a /= 10;
	}
	cout << b;
}