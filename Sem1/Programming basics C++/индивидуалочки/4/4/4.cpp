// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
const int n = 3;
int a[n][n],b[n], k = 0,s;
bool f=1;
cout << "input index of str" <<"\n";
cin >>s;
cout << "enter an array" << "\n";
for (int i = 0;i < n;i++)
	for (int j = 0;j < n;j++)
	    cin>>a[i][j];
	for (int i = 0;i < n;i++) {
	    cout << endl;
	    for (int j = 0;j < n;j++)
	        cout << a[i][j] << " ";
	}
cout << endl;
for(int j=0;j<n-1;j++){
	if (a[s-1][j]<=a[s-1][j+1])f=0;
	}
cout << "your arr:" << "\n";
if (f) {
	for (int i = 0;i < n;i++) {
		b[i]= 1;
		cout << b[i] << " ";
	}
}
else{
	for (int i = 0;i < n;i++) {
		b[i] = 0;
		cout << b[i] << " ";
	}
}
}