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
}

void f3_1(int* a, int n,int s) {
	if (n > -1) {
		if (a[n] < 0)a[n] = s;
	}
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
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	f3_1(a, n, f3_2(a, n));
	for (int i = 0;i < n;i++)
		cout << a[i]<< " ";
}