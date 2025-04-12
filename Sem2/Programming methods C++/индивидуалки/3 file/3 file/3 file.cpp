#include <iostream>
#include <fstream>
using namespace std;

struct tree
{
    int info;
    tree* right;
    tree* left;
};
void add(tree* t, int& x)
{
    if (x < t->info)
        if (t->left == NULL)
        {
            tree* q = new(tree);
            q->info = x;
            q->right = NULL;
            q->left = NULL;
            t->left = q;
        }
        else add(t->left, x);
    else
        if (t->right == NULL)
        {
            tree* q = new(tree);
            q->info = x;
            q->right = NULL;
            q->left = NULL;
            t->right = q;
        }
        else add(t->right, x);
}
tree* create()
{
    int x;
    cin >> x;
    if (x) {
        tree* t = new(tree);
        t->info = x;
        t->right = NULL;
        t->left = NULL;
        cin >> x;
        while (x)
        {
            add(t, x);
            cin >> x;
        }
        return t;
    }
    return NULL;
}

tree* zcreate(int&n,int*a)
{
    if (a[0]) {
        tree* t = new(tree);
        t->info = a[0];
        t->right = NULL;
        t->left = NULL;
        for(int i=1;i<n;++i)
        {
            add(t, a[i]);
        }
        return t;
    }
    return NULL;
}

void print(tree* t)
{
    if (t != NULL) {
        print(t->left);
        cout << t->info << " ";
        print(t->right);
    }
}

// void vivod(tree* r,int*i,int*&a)
//{
//     if (r == NULL)return; 
//        vivod(r->left,i,a);
//        a[*i] = r->info;
//        ++*i;
//        vivod(r->right,i,a);
//}

void vivod(tree* r, int*i, int*& a)
{
    if (r == NULL)return;
    vivod(r->left, i, a);
    a[*i] = r->info;
    ++*i;
    vivod(r->right, i, a);
}

int kol_node(tree* r)
{
    if (r)
    {
        return 1 + kol_node(r->right) + kol_node(r->left);
    }
    return 0;
}

int main()
{
    int an, bn;
    tree* r1, * r2;
    int x;
    ofstream f1("f1.txt");
    cout << "input nums in 1st file\n";
    r1 = create();
    an = kol_node(r1);
    int* a = new int[an];

    int p = 0;
    //vivod(r1, &p, a);
    vivod(r1,&p, a);

    for (int i = 0;i < an;++i) {
        x = a[i];
        f1 << x << endl;
    }

    f1.close();
    ofstream f2("f2.txt");
    cout << "input nums in 2nd file\n";
    r2 = create();
    bn = kol_node(r2);
    int* b = new int[bn];

    p = 0;
    //vivod(r2, &p, b);
    vivod(r2,&p, b);

    for (int i = 0;i < bn;++i) {
        x = b[i];
        f2 << x << endl;
    }

    f2.close();

    ifstream h1("f1.txt");

    int k = an + bn;
    int* c = new int[k];
    {int j = 0;

    while (h1 >> x)
    {
        c[j++] = x;
    }
    h1.close();

    ifstream h2("f2.txt");

    while (h2 >> x)
    {
        c[j++] = x;
    }
    h2.close();}
    
    tree* r3 = zcreate(k,c);
    p = 0;
    //vivod(r3, &p, c);
    vivod(r3,&p, c);

    ofstream h3("f3.txt");
    for (int i = 0;i < k;++i) {
        h3 << c[i] << endl;
    }
    h3.close();

    ifstream f3("f3.txt");
    while (f3>>x)
        cout << x << " ";
    f3.close();
}
