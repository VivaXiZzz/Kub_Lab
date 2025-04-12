// ФИНАЛОЧКА.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int f24(int n) {
	int a, k = 0;
	for (int i = 0;i < n;i++) {
		cin >> a;
		if (a < 0)k++;
	}
	if (k >= 3)return 1;
	else return 0;
}

void f25(int**a,int n,int m)
{
	for(int j=0;j<m;j++)
		for (int i = 0;i < n;i++)
		{
			if (a[i][j] < 0) {
				cout << a[i][j] << endl;
				break;
			}
		}
}

bool f26(int** a, int n, int m) {
	for (int j = 0;j < m;j++) {
		if (a[n][j] > 0)return 1;
		break;
	}
	return 0;
}

int f27(int n) {
	int a,k=0;
	for (int i = 0;i < n;i++) {
		cin >> a;
		int a1 = 0;
		for (int j = 1;j < a;j++)
			if (a % j == 0)a1 += j;
		if (a == a1) {
			k++;
		}
	}
	return k;
}

struct abiturent {
	char surname[64];
	char name[64];
	char patronymic[64];
	char adr[64];
	int evaluation;
};

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
//	int n;
//	float s=0;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++) {	
//		cin >> a[i];
//		s += a[i];
//	}
//	s /= n;
//	for (int i = 0;i < n;i++) {
//		if (a[i] <= s)cout << a[i] << " ";
//	}
//}

//13
	//int n,k=0;
	//cin >> n;
	//int* a = new int[n];
	//for (int i = 0;i < n;i++)
	//	cin >> a[i];
	//for (int i = 0;i < n;i++) {
	//	int a1 = 0;
	//	for (int j = 1;j < a[i];j++) {
	//		if (a[i] % j == 0)a1 += j;
	//	}
	//	if (a1 == a[i])k++;
	//	}
	//if (k >= 2)cout << "est";
	//}

//14
//	int a[3][3], p = 1;
//	for (int i = 0;i < 3;i++)
//		for (int j = 0;j < 3;j++)
//			cin >> a[i][j];
//	for (int i = 0;i < 3;i++)
//		for (int j = 0;j < 3;j++) {
//			if (i > j && a[i][j] != 0)p *= a[i][j];
//		}
//	cout << p;
//}
//15
//	int n;
//	float min, max;
//	cin >> n;
//	float** a = new float *[n];
//	for (int i = 0;i < n;i++)
//		a[i] = new float[n];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	min = max = a[0][0];
//	for(int i=0;i<n;i++)
//		for (int j = 0;j < n;j++) {
//			if (min > a[i][j])min = a[i][j];
//			if (max < a[i][j])max = a[i][j];
//		}
//	cout << max-min;
//}

//16
//	int a, b, u;
//	float h;
//	cin >> a >> b >> u;
//	int* a1=&a, * b1=&b, * u1=&u;
//	h = fabs((*a1) * (*b1) * 0.5 * sin((*u1)*3.14/180));
//		cout << h;
//}

//17
//	int n;
//	float s = 0;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//		s += a[i];
//	}
//	s /= n;
//	for (int i = 0;i < n;i++)
//		if (a[i] < s)cout << a[i]<<" ";
//}
//18.1
//	int a;
//	float s;
//	cin >> a;
//	int *a1 = &a;
//	s = (*a1) * (*a1) * 3.14;
//	cout << s;
//}

//18.2
//	int n;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//		if (a[i] % 2 == 0) a[i] /= 2;
//		else a[i] *= 2;
//		cout << a[i]<<" ";
//	}
//}

//19
//	int n,k=0;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//		if ((i + 1) % 3 != 0 && a[i] % 2 == 0)k++;
//	}
//	cout << k;
//}

//20
//	int n;
//	cin >> n;
//	float** a = new float* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new float[n];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	int min = fabs(a[0][0]);
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			if (min > fabs(a[i][j]))min = fabs(a[i][j]);
//	cout << min;
//}

//21
//	int n,i1,j1,el;
//	float p = 0;
//	cin >> n;
//	float** a = new float* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new float[n];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	el = fabs(a[0][0]);
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			if (el < fabs(a[i][j]))el = a[i][j],i1=i,j1=j;
//	el = 1;
//	for (int i = 0;i < n;i++)
//		el *= a[i][j1];
//	p += el;
//	el = 1;
//	for (int j = 0;j < n;j++)
//		el *= a[i1][j];
//	p += el;
//	cout << p;
//}

//22
//	int n,j1,el;
//	float s=0;
//	cin >> n;
//	float** a = new float* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new float[n];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	el = a[0][0];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			if (el < a[i][j])el = a[i][j],j1=j;
//	for (int i = 0;i < n;i++)
//		s += a[i][j1];
//	cout << s;
//}

//23
//int n,s1=0,s2=0;
//float ot;
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[n];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> a[i][j];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++) {
//			if (i > j)s1 += a[i][j];
//			if (i < j)s2 += a[i][j];
//		}
//	ot = (float)s2 / s1;
//	cout << ot;
//}


////24
//	int n;
//	cin >> n;
//	cout<<f24(n);
//}

//25
//	int n,m;
//	cin >> n>>m;
//	int** a = new int* [n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	f25(a, n, m);
//}

//26
//	int n, m;
//	cin >> n >> m;
//	int** a = new int*[n];
//	for (int i = 0;i < n;i++)
//		a[i] = new int[m];
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> a[i][j];
//	for (int i = 0;i < n;i++)
//		cout<<f26(a, i, m);
//
//}


//27
//	int n;
//	cin >> n;
//	cout<<f27(n);
//}

//28
	abiturent degenerates[3];
	int n,max;
	cin >> n;
	for (int i = 0;i < 3;i++) {
		cin >> degenerates[i].surname;
		cin >> degenerates[i].name;
		cin >> degenerates[i].patronymic;
		cin >> degenerates[i].adr;
		cin >> degenerates[i].evaluation;
	}
	max = degenerates[0].evaluation;
	cout << "neud" << endl;
	for (int i = 0;i < 3;i++)
		if (degenerates[i].evaluation < 3)cout << degenerates[i].name << " " << degenerates[i].surname << " ";
	cout << endl << "necessary" << endl;
	for(int i=0;i<n;i++)
		if(degenerates[i].evaluation>=n)cout << degenerates[i].name << " " << degenerates[i].surname << " ";
	cout << endl << "max evaluation" << endl;
	for (int i = 0;i < n;i++)
		if (degenerates[i].evaluation > max)max = i;
	cout << degenerates[max].evaluation;
}