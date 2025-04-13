#include <iostream>
using namespace std;
bool f1(int a) {
	int k = 0;
	for (int i = 1;i <= a;i++)
		if ((a % i == 0)&&(i%2==0))k++;
	if (k > 2) return 1;
	return 0;
}

bool f2(int a) {
	int a1 = a;
	while (a1) {
		if (a1 % 10 == 5)return 0;
		if (a1 % 10 == 2)return 0;
		a1 /= 10;
	}
	return 1;
}

int f3_2(int* a,int n) {
	if (n == -1) return 0;
	if (a[n] > 0 && a[n] % 2 == 0) return f3_2(a, n - 1) + a[n];
	return f3_2(a, n - 1);
}

void f3_1(int* a, int n,int s) {
	if (n > -1) {
		if (a[n] < 0)a[n] = s;
		return f3_1(a, n - 1, s);
	}
}

int f4(int n) {
	if (n<2) return 1;
		return f4(n - 2) * n;
}

bool f5_1(int* a,int n, int x) {
	int p = 1;
	bool f = 0;
	for (int i = 0;i < n;i++)
		if (a[i] % 10 == 0) { p *= a[i];
	f = 1; }
	cout << p << " ";
	if ((f)&&(p > x))return 1;
	p = 0;
	if (p > x)return 1;
	return 0;
}
void f5_2(int* a,int n) {
	for (int i = 0;i < n;i++)
		if (a[i] > 0)a[i] *= 2;
}
bool f8(int a) {
	int a1 = a;
	while (a1 > 9) {
		a1 /= 10;
	}
	if (a % 10 == a1)return 1;
	return 0;
}
double f9(int* a, int n) {
	double s = 0;
	for (int i = 1;i < n;i++)
		s += (double)cos(a[i]);
	return s;
}
int f10(int** a, int i, int m) {
	int max = a[i][0];
	for (int j = 1;j < m;j++)
		if (abs(max) < abs(a[i][j]))max = a[i][j];
	return max;
}
double* f11(int* a, int* b, int n) {
	double*k = new double[n];
	for (int i = 0;i < n;i++) {
		if (a[i] > 0)k[i] = (double)sin(a[i]);
		if (a[i] < 0)k[i] = b[i];
		if (a[i]==0)  k[i] = 1;
	}
	return k;
}
double* f12(int* a, int* b, int n) {
	double* k = new double[n];
	for (int i = 0;i < n;i++) {
		if (a[i] < 0)k[i] = a[i] * a[i];
		if (a[i] > 0) {
			k[i] = 1;for (int j = 2;j < i;j++)k[i] *= j;
		}
		if (a[i] == 0)k[i] = 3;
	}
	return k;
}
int f13(int** a, int n, int j) {
	int s = 0;
	for (int i = 0;i < n;i++)
		if (a[i][j]>0)s += a[i][j];
	return s;
}

double f14(int* a, int n) {
	double s = 0;
	for (int i = 0;i < n;i++) {
		s += sin(a[i] * a[i]);
	}
	return s;
}
int main()
{
	//1
//	int n, m;
//	cin >> n >> m;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	int* b = new int[m];
//	for (int i = 0;i < m;i++)
//		b[i] = 0;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	for(int j=0;j<m;j++)
//		for(int i=0;i<n;i++)
//			if(f1(a[i][j]))b[j]+=a[i][j];
//	for (int i = 0;i < m;i++)
//		cout << b[i]<<" ";
//}


//2
//	int n, m;
//	cin >> n >> m;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	int* b = new int[n];
//	for (int i = 0;i < m;i++)
//		b[i] = 0;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	for (int j = 0;j < m;j++) {
//			int p = 1;
//			bool f = 0;
//		for (int i = 0;i < n;i++) {
//			if (f2(a[i][j]))p *= a[i][j];
//			if (a[i][j] == 1)f=1;
//		}
//		if(p!=1||f)b[j] = p;
//	}
//	for (int i = 0;i < m;i++)
//		cout << b[i] << " ";
//}

//3
//	int n,s=0;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	s = f3_2(a, n);
//	f3_1(a, n, s);
//	for (int i = 0;i < n;i++)
//		cout << a[i]<< " ";
//}

//4
//	signed int n;
//	cin >> n;
//	cout << f4(n);
//}

//5
//	int n,x;
//	cin >>n>>x;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	if (f5_1(a, n, x))f5_2(a, n);
//	for (int i = 0;i < n;i++)
//		cout << a[i]<<" ";
//	delete[]a;
//}

//7	
//	int n,x,s=0;
//	cin >> n>>x;
//	int* a = new int[n];
//	int* b = new int[n];
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//		b[i] = 0;
//	}
//	for (int i = 0;i < n;i++)
//		s += a[i];
//	if (s <= x) {
//		int p = 0;
//		for (int i = 0;i < n;i++) {
//			p += (i + 1) * (i + 1);
//			if (a[i] > 0) {
//				b[i] = p;
//			}
//		}
//	for (int i = 0;i < n;i++)
//		cout << b[i]<<" ";
//	}
//	else delete[]b;
//	delete[]a;
//}

//8
//	int n,k=0;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	for (int i = 0;i < n;i++)
//		if (f8(a[i]))k++;
//	cout << k;
//}

//9
//	int n,m;
//	double max;
//	cin >> n>> m;
//	int* a = new int[n];
//	int* b = new int[m];
//	for(int i = 0;i < n;i++)
//		cin >> a[i];
//	for (int i = 0;i < m;i++)
//		cin >> b[i];
//	max = (f9(a, n) > f9(b, m)) ? f9(a, n) : f9(b, m);
//	cout << max;
//}

//10
//	int n, m,s=0;
//	cin >> n >> m;
//	int** a = new int*[n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	for (int i = 0;i < n;i++) {
//		s += f10(a, i, m);
//	}
//	cout << s;
//}

//11
//	int n;
//	cin >> n;
//	int* a = new int[n];
//	int* b = new int[n];
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	for (int j = 0;j < n;j++)
//		cin >> b[j];
//	double*k=f11(a, b, n);
//	for (int i = 0;i < n;i++)
//		cout << k[i]<<" ";
//}

//12
//	int n;
//	cin >> n;
//	int* a = new int[n];
//	int* b = new int[n];
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	for (int i = 0;i < n;i++)
//		cin >> b[i];
//	double* k = f12(a, b, n);
//	for (int i = 0;i < n;i++)
//		cout << k[i]<<" ";
//	delete[]a;
//	delete[]b;
//}

//13
//	int n, m,s=0;
//	cin >> n >> m;
//	int** a = new int*[n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	for (int j = 0;j < m;j++)
//		s += f13(a, n, j);
//	cout << s;
//	for (int i = 0;i < n;i++)
//		delete[]a[i];
//	delete[]a;
//}

//14
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
		cin >> b[i];
	cout << (f14(a, n) > f14(b, n) ? f14(a, n) : f14(b, n));
	delete[]a;
	delete[]b;
}