#include <iostream>
using namespace std;

    bool sov(int x) {
        int x1 = 0;
        for (int i = 1;i < x;i++)if (x % i == 0)x1 += i;
        return x1 == x;
    }

    bool prostsum(int x) {
        int x1 = x,sum=0,k=0;
        while (x1) {
            sum += x1 % 10;
            x1 /= 10;
        }
        for (int i = 1;i <= sum;i++)if (sum % i == 0)k++;
        return k == 2;
    }

    bool ed2(int x) {
        int x1 = x, sum = 0, k = 0;
        while (x1) {
            if(x1%10==1)k++;
            x1 /= 10;
        }
        return k >= 2;
    }
    
    bool fib(int x) {
        int f1 = 0, f2 = 1, f = 0;
        while (f < x) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f == x;
    }

    bool chetsimv(int a) {
        int sum = 0,x=a;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum % 2 == 0;
    }

    bool chis5(int a) {
        int x = a;
        while (a) {
            if (a % 10 == 5)return 1;
            a /= 10;
        }
        return 0;
    }

    int max(int a, int b) {
        return (a < b) ? b:a;
    }

    int maxchis(int a, int b) {
        int b1 = b,sum=0;
        while (b1) {
            sum += b1 % 10;
            b1 /= 10;
        }
        return (a < sum) ? sum : a;
    }

    void main()
    {
        //    int n,sum=0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if(sov(a[i]))sum += a[i];
        //    }
        //    cout << sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if (fib(a[i]))sum++;
        //    }
        //    cout << sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if (prostsum(a[i]))sum++;
        //    }
        //    cout << sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if (ed2(a[i]))sum++;
        //    }
        //    cout << sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int** a = new int*[n];
        //    for (int i = 0;i < n;i++)
        //        a[i] = new int[n];
        //    for (int i = 0;i < n;i++)
        //        for (int j = 0;j < n;j++) {
        //            cin >> a[i][j];
        //            if (sov(a[i][j])&&(i+j)%2==0)sum++;
        //        }
        //    cout << sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if (chetsimv(a[i]))sum++;
        //    }
        //    cout <<endl<< sum;
        //}

        //    int n, sum = 0;
        //    cin >> n;
        //    int* a = new int[n];
        //    for (int i = 0;i < n;i++) {
        //        cin >> a[i];
        //        if (chis5(a[i]))sum++;
        //    }
        //    cout << endl << sum;
        //}

        //    int x, y, z;
        //    cin >> x >> y >> z;
        //    cout <<(float)(max(x, y) + max(y, z)) / (max(x, z) - 2);
        //}

        int n, max = 0;
        cin >> n;
        int** a = new int* [n];
        for (int i = 0;i < n;i++)
            a[i] = new int[n];
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                cin >> a[i][j];
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                max = maxchis(max, a[i][j]);
        cout << max;
    }