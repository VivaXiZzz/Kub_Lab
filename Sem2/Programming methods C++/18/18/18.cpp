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
void add(tree* t, int&x)
{
    if (x < t->info)
        if (t->left == NULL)
        {
            tree* q = new(tree);
            q->info = x;
            q->lvl = t->lvl+=1;
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
        q->lvl = t->lvl+=1;
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
        print(r);
        cout << r->info << " ";
        print(r);
    }
}
void maxlvl1(tree*& t, int& a)
{
    if (t) {
        if (t->left != NULL || t->right != NULL)
        {
            maxlvl1(t->left, a = t->lvl);
            maxlvl1(t->right, a = t->lvl);
        }
    }
    return;
}
int count_list_on_lvl(tree* t, int& a)
{
    if (t!=NULL)return (t->lvl == a) + count_list_on_lvl(t->left, a) + count_list_on_lvl(t->right, a);
    return 0;
}
int leaf_sum(tree* t)
{
    if (t)
    {
        if (t->left == NULL && t->right == NULL)return t->info + leaf_sum(t->left) + leaf_sum(t->right);
        return leaf_sum(t->left) + leaf_sum(t->right);
    }
    return 0;
}
void zam(tree* t, int& a,int&p)
{
    if (t)
    {
        if (t->info == a && t->info % 2 == 0)t->info = p;
        zam(t->left,a,p);
        zam(t->right,a,p);
    }
    return;
}
int main()
{
    int a=0;
    tree* t = create();
    //maxlvl1(t, a);cout << a;

    //maxlvl1(t, a);cout << count_list_on_lvl(t, a);

    int x;cin >> x;int k = leaf_sum(t);zam(t, x, k);
}
