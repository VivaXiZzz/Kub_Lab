#include <iostream>
using namespace std;
int main()
{
//	int n, a=2, b=1;
//	float s = 0;
//	cin >> n;
//	for (int i = 1;n >= i;i++) {
//		b *= i;
//		cout << "a = " << a << " b = " << b << endl;
//		s += (float)a / (b + 5);
//		a *= 2;
//	}
//	cout << s;
//}

//	int n, a = 2, b = 1, y1, ed=-1,y2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	for (int i = 1;n >= i;i++) {
//		b *= i;
//		s += (float)ed*(2+b) / y2;
//		y2 *= y1 * y1;
//		ed *= -1;
//		a *= 2;
//	}
//	cout << s;
//}

//	int n, y1, y2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	for (int i = 1;n >= i;i++) {
//		b *= i;
//		s += (float)y2/(i+5);
//		y2 *= y1;
//	}
//	cout << s;
//}

//	int n, b = 1, y1, y2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	for (int i = 1;n >= i;i++) {
//		b *= i;
//		s += (float)y2/b;
//		y2 *= y1;
//	}
//	cout << s;
//}

//	int n, b = 1, y1, ed = -1, y2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	y2 *= y1;
//	for (int i = 1;n >= i;i++) {
//		b *= (2*i)*(2*i-1);
//		s += (float)ed * y2 / b;
//		y2 *= y1 * y1;
//		ed *= -1;
//	}
//	cout << s;
//}

//	int n, b = 1, y1, ed = 1, y2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	y2 *= y1 * y1 * y1;
//	for (int i = 1;n >= i;i++) {
//		b *= i;
//		s += (float)ed * (4 + b) / y2;
//		y2 *= y1;
//		ed *= -1;
//	}
//	cout << s;
//}

//	int n, b = 1, y1, ed = 1, y2, a = 2;
//	float s = 0;
//	cin >> n;
//	cin >> y1;
//	y2 = y1;
//	y2 *= y1;
//	for (int i = 1;n >= i;i++) {
//		b *= (i+1);
//		s += (float)ed * (y2 + 1) / (a + b);
//		y2 *= y1 * y1;
//		a *= 4;
//		ed *= -1;
//	}
//	cout << s;
//}

int n, y1, ed = 1, y2;
float s = 0;
cin >> n;
cin >> y1;
y2 = y1;
for (int i = 1;n >= i;i++) {
	s += (float)ed * y2 / i;
	y2 *= y1;
	ed *= -1;
}
cout << s;
}

