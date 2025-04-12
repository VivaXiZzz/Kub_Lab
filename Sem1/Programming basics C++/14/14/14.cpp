// 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	//	int n, max;
	//	cin >> n;
	//	int** a = new int* [n];
	//	for (int i = 0;i < n;i++)
	//		a[i] = new int[n];
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			a[i][j]=rand()%11;
	//
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//
	//	cout << endl;
	//	max = a[0][0];
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			if (max < a[i][j])max = a[i][j];
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0,k;j < n;j++){
	//			k = 0;
	//			for (int p = 1;p <= a[i][j];p++)if (a[i][j] % p == 0)k++;
	//			if (k == 2)a[i][j] = max;
	//		}
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//}

	//	int n, k=0;
	//	bool f;
	//	cin >> n;
	//	int** a = new int* [n];
	//	for (int i = 0;i < n;i++)
	//		a[i] = new int[n];
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			cin >> a[i][j];// = rand() % 11;
	//
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//
	//	cout << endl;
	//
	//	for (int i = 0;i < n;i++) {
	//		f = 1;
	//		for (int j = 0;j < n - 1;j++)
	//			if (a[i][j] >= a[i][j+1])f = 0;
	//		if (f)k++;
	//	}
	//	cout << k;
	//}

	//	int n, k = 0;
	//	bool f;
	//	cin >> n;
	//	int** a = new int* [n];
	//	for (int i = 0;i < n;i++)
	//		a[i] = new int[n];
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			cin >> a[i][j];// = rand() % 11;
	//
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//
	//	cout << endl;
	//
	//	for (int i = 0;i < n;i++) {
	//		f = 1;
	//		for (int j = 0;j < n;j++)
	//			if (a[i][j] != a[i][n-j-1])f = 0;
	//		if (f)k++;
	//	}
	//	cout << k;
	//}

	//	int n, max,min,imx,imn,p;
	//	cin >> n;
	//	int** a = new int* [n];
	//	for (int i = 0;i < n;i++)
	//		a[i] = new int[n];
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			cin >> a[i][j];//=rand()%11;
	//
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//
	//	cout << endl;
	//	max = min = a[0][0];
	//	imn = imx =0;
	//
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++) {
	//			if (max < a[i][j])max = a[i][j],imx=i;
	//			if (min > a[i][j])min = a[i][j],imn=i;
	//		}
	//		for (int j = 0,k;j < n;j++){
	//			p = a[imn][j];
	//			a[imn][j] = a[imx][j];
	//			a[imx][j] = p;
	//		}
	//	for (int i = 0;i < n;i++) {
	//		cout << '\n';
	//		for (int j = 0;j < n;j++)
	//			cout << a[i][j] << " ";
	//	}
	//}

	//int n,t=0;
	//bool f = 0;
	//cin >> n;
	//int** a = new int* [n];
	//for (int i = 0;i < n;i++)
	//	a[i] = new int[n];
	//
	//for (int i = 0;i < n;i++)
	//	for (int j = 0;j < n;j++)
	//		cin >> a[i][j];//=rand()%11;
	//
	//for (int i = 0;i < n;i++) {
	//	cout << '\n';
	//	for (int j = 0;j < n;j++)
	//		cout << a[i][j] << " ";
	//}
	//
	//cout << endl;
	//
	//for (int i = 0;i < n;i++)
	//	for (int j = 0,k;j < n;j++) {
	//		k = 0;
	//		for (int p = 1;p <= a[i][j];p++)if (a[i][j] % p == 0)k++;
	//		if (k == 2)t++;
	//	}
	//if (t >= 2)f = 1;
	//
	//if (f) {
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			if (a[i][j] > 0)a[i][j] = 0;
	//}
	//else {
	//	for (int i = 0;i < n;i++)
	//		for (int j = 0;j < n;j++)
	//			if (a[i][j] < 0)a[i][j] = abs(a[i][j]);
	//}
	//for (int i = 0;i < n;i++) {
	//	cout << '\n';
	//	for (int j = 0;j < n;j++)
	//		cout << a[i][j] << " ";
	//}
	//}

//	int n, sum = 0;
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[n];
//
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//
//	for (int i = 0, a1;i < n;i++) {
//		a1 = 0;
//		for (int p = 1;p < a[i][n - i - 1];p++) {
//			if (a[i][n - i - 1] % p == 0)a1 += p;
//		}
//			if (a1 == a[i][n - i - 1])sum += a[i][n - i - 1];
//	}
//	cout << sum;
//}

//	int n, max=0;
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[n];
//
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	for (int a1 = a[0][0];a1;){
//		max += a1 % 10;
//		a1 /= 10;
//}
//	for (int i = 0, a1;i < n;i++)
//		for (int a1 = a[i][i],s=0;a1;) {
//			s += a1 % 10;
//			a1 /= 10;
//			if (s > max)max = s;
//		}
//	cout << max;
//}

//	int n, i1, i2;
//	cin >> n >> i1 >> i2;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[n];
//
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//
//	for (int j = 0,s;j < n;j++) {
//		s = a[i1-1][j];
//		a[i1-1][j] = a[i2-1][j];
//		a[i2-1][j] = s;
//	}
//	for (int i = 0;i < n;i++) {
//		cout <<'\n';
//		for (int j = 0;j < n;j++)
//			cout << a[i][j] << " ";
//	}
//}

//	int n;
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[n];
//
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//
//	for (int i = 0;i < n;i++) {
//		bool f = 1;
//		for (int j = 0;j < n-1;j++) {
//			if (a[j][i] <= a[j+1][i])f = 0;
//		}
//		if (f)cout << i;
//	}
//}

//int n,c=0;
//cin >> n;
//int** a = new int* [n];
//for (int i = 0;i < n;i++)
//	a[i] = new int[n];
//
//for (int i = 0;i < n;i++)
//	for (int j = 0;j < n;j++)
//		cin >> a[i][j];
//
//for (int i = 0;i < n;i++) {
//	bool f = 0;
//	for (int a1 = a[i][i];a1;) {
//		if (a1 % 10 == 5)f = 1;
//		a1 /= 10;
//	}
//	if (f)c++;
//}
//cout << c;
//}

//int n, c = 0;
//cin >> n;
//int** a = new int* [n];
//for (int i = 0;i < n;i++)
//	a[i] = new int[n];
//
//for (int i = 0;i < n;i++)
//	for (int j = 0;j < n;j++)
//		cin >> a[i][j];
//
//for (int i = 0;i < n;i++) {
//	for (int j = 0;j < n;j++) {
//		int d = 0;
//		for (int a1 = a[i][j];a1;) {
//			if (a1 % 10 == 1)d += 1;
//			a1 /= 10;
//		}
//		if (d >= 2)c += a[i][j];
//	}
//}
//std::cout << c;
//}

	int n, c = 0;
	cin >> n;
	int** a = new int* [n];
	bool* b = new bool[n];
	for (int i = 0;i < n;i++)
		a[i] = new int[n];

	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];

	for (int i = 0, d;i < n;i++) {
		d = 0;
		for (int j = 0;j < n;j++)
			if (a[i][j] > 0)d++;
		if (d >= 2)b[i] = 1;
		else b[i] = 0;
		cout << b[i] << " ";
	}
}