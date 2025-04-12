// 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
//	const int n = 3, m = 3;
//	int a[3][3],p=1;
//	float;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand()%5+1;
//	for (int i = 0;i < n;i++)
//			p *= a[i][n - i - 1];
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	cout <<"\n" << p;
//}

//	const int n = 3, m = 3;
//	int a[n][m], sum = 0;
//	float;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand() % 5 + 1;
//	for (int i = 0;i < n;i++) {
//		for (int j = 0;j < i;j++) {
//			sum += a[i][j];
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	cout << "\n" << sum;
//}

//	const int n = 3, m = 3;
//	int a[n][m];
//	float sum=0;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand() % 5 + 1;
//	for (int i = 0;i < n;i++) {
//		sum += a[i][n- i - 1];
//	}
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	sum /= n;
//	cout << "\n" << sum;
//}

//	const int n = 4, m = 4;
//	int a[n][m], sum = 0;
//	float;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand() % 5 + 1;
//		for (int i = 0;i < n;i++) {
//			for (int j = 0;j < i&&i<n-j-1;j++) {
//			sum += a[i][j];
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	cout << "\n" << sum;
//}

//	const int n = 3, m = 3;
//	int a[n][m], imax;
//	float;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand() % 10 + 1;
//	imax = a[1][0];
//	for (int i = 0;i < n;i++) {
//		for (int j = 0;i > j;j++) {
//			if(a[i][j]>imax)imax=a[i][j];
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	cout << "\n" << imax;
//}

//	const int n = 4, m = 4;
//	int a[n][m], p=1;
//	float;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			a[i][j] = rand() % 6 + 1;
//	for (int i = 0;i < n;i++)
//		if (a[i][i] % 2 == 0)p *= a[i][i];
//	for (int i = 0;i < n;i++) {
//		cout << "\n";
//		for (int j = 0;j < m;j++)
//			cout << a[i][j] << " ";
//	}
//	cout << "\n" << p;
//}

//const int n = 4, m = 4;
//int a[n][m], imax;
//float;
//for (int i = 0;i < n;i++)
//	for (int j = 0;j < m;j++)
//		a[i][j] = rand() % 10 + 1;
//imax = a[0][0];
//for (int i = 0;i < n;i++) {
//	if (a[i][i] > imax)imax = a[i][i];
//}
//for (int i = 0;i < n;i++) {
//	cout << "\n";
//	for (int j = 0;j < m;j++)
//		cout << a[i][j] << " ";
//}
//cout << "\n" << imax;
//}

//const int n = 7, m = 7;
//int a[n][m], imax,g=0;
//float;
//for (int i = 0;i < n;i++)
//	for (int j = 0;j < m;j++)
//		a[i][j] = rand() % 10 + 1;
//imax = a[1][0];
//for (int i = 0;i < n;i++) {
//	if (a[i][n - i - 1] < imax)imax = a[i][n - i - 1], g = i+1;
//}
//for (int i = 0;i < n;i++) {
//	cout << "\n";
//	for (int j = 0;j < m;j++)
//		cout << a[i][j] << " ";
//}
//cout << "\n" << imax<<" "<<g;
//}

//const int n = 5, m = 5;
//int a[n][m], imax=0;
//float;
//for (int i = 0;i < n;i++)
//	for (int j = 0;j < m;j++)
//		a[i][j] = rand() % 2 + 22;
//for (int i = 0;i < n;i++) {
//	for (int j = 0;j < n;j++) {
//		if (i < j) {
//			if (a[i][j] % 100 == 22)imax++;
//		}
//	}
//}
//for (int i = 0;i < n;i++) {
//	cout << "\n";
//	for (int j = 0;j < m;j++)
//		cout << a[i][j] << " ";
//}
//cout << "\n" << imax;
//}

const int n = 4, m = 4;
int a[n][m], p=1;
float;
for (int i = 0;i < n;i++)
	for (int j = 0;j < m;j++)
		a[i][j] = rand() % 5 + 1;
for (int i = 0;i < n;i++) {
	for (int j = 0;j < n;j++) {
		if (i>j&&i<n-j-1)p*= a[i][j];
	}
}
for (int i = 0;i < n;i++) {
	cout << "\n";
	for (int j = 0;j < m;j++)
		cout << a[i][j] << " ";
}
cout << "\n" << p;
}