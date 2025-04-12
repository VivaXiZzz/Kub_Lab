#include <iostream>
#include <algorithm>
using namespace std;
struct tree
{
    int info;
    int lvl;
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
            q->lvl = t->lvl += 1;
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
            q->lvl = t->lvl += 1;
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
        t->lvl = 0;
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
void print(tree* r)
{
    if (r != NULL) {
        print(r->left);
        cout << r->info << " ";
        print(r->right);
    }
}
bool pol(tree*t)
{
    if (t) {
        if (t->info < 0)
        {
            return 1;
        }
        else return pol(t->left) + pol(t->right);;
    }
    return 0;
}
bool prime(int& a)
{
    if (a == 1)return 0;
    for (int i = 2;i < a;++i)if (a % i == 0)return 0;
    return 1;
}

int sum_prost(tree* t)
{
    if (t)
    {
        if (prime(t->info))return t->info + sum_prost(t->left) + sum_prost(t->right);
        return sum_prost(t->left) + sum_prost(t->right);
    }
    return 0;
}

void zam(tree* t,int&a)
{
    if (t)
    {
        if (t->info% 2 == 0)t->info = a;
        zam(t->left, a);
        zam(t->right, a);
    }
    return;
}
void ex()
{
    cout << "input nums:\n";
    tree* r = create();
    cout << "answer:\n";
    if (!pol(r))
    {
        int x = sum_prost(r);
        zam(r, x);
    }
    print(r);
}
int main()
{
    ex();
}
