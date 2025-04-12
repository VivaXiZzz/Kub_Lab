#include <iostream>
using namespace std;
struct tree
{
    int info;
    tree* right;
    tree* left;
};
void add(tree* t, int x)
{
    tree* q;
    if (x < t->info)
        if (t->left == NULL)
        {
            q = new(tree);
            q->info = x;
            q->left = NULL;
            q->right = NULL;
            t->left = q;
        }
        else add(t->left, x);
    else
        if (t->right == NULL)
        {
            q = new(tree);
            q->info = x;
            q->left = NULL;
            q->right = NULL;
            t->right = q;
        }
        else add(t->right, x);
}
void print(tree* t)
    {
    if (t != NULL) {
        cout << t->info;
        print(t->left);
        print(t->right);
    }
    }
int sum_chet(tree* t)
{
    if (t != NULL) {
        if (t->info % 2 == 0)
            return t->info + sum_chet(t->left) + sum_chet(t->right);
        return sum_chet(t->left) + sum_chet(t->right);
    }
    return 0;
}
int leaf_count(tree* t)
{
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            return 1 + leaf_count(t->left) + leaf_count(t->right);
    return leaf_count(t->left) + leaf_count(t->right);
    }
    return 0;
}
int leaf_sum(tree* t)
{
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            return t->info + leaf_sum(t->left) + leaf_sum(t->right);
        return leaf_sum(t->left) + leaf_sum(t->right);
    }
    return 0;
}
void leaf_proiz(tree* t,int&a)
{
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL && t->info % 5 == 0) {
            a *= t->info;
            leaf_proiz(t->left, a);
            leaf_proiz(t->right, a);
        }
        leaf_proiz(t->left, a);
        leaf_proiz(t->right, a);
    }
    return;
}
bool con_1(tree* p)
{
    for (int i = 2;i < p->info;i++)if (p->info % i == 0)return 0;
    return 1;
}
bool con_2(tree* p)
{
    int a = 0;
    for (int i = 1;i < p->info;++i)if (p->info % i == 0)a += i;
    if (a == p->info)return 1;
    return 0;
}
int sum_prost(tree* t,bool condition(tree*d))
{
    if (t != NULL) {
        if (condition(t))
            return t->info + sum_prost(t->left,con_1) + sum_prost(t->right,con_1);
        return sum_prost(t->left,con_1) + sum_prost(t->right,con_1);
    }
    return 0;
}
void leaf_pro(tree* t,bool condition(tree*h), int& a)
{
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL && condition(t)) {
            a *= t->info;
            leaf_pro(t->left,con_2, a);
            leaf_pro(t->right,con_2, a);
        }
        leaf_pro(t->left,con_2 ,a);
        leaf_pro(t->right,con_2 ,a);
    }
    return;
}
int no_leaf_sum(tree* p)
{
    if (p != NULL)
    {
        if ((p->right != NULL or p->left != NULL))if(p->info % 2 == 1)
            return p->info + no_leaf_sum(p->left) + no_leaf_sum(p->right);
        return no_leaf_sum(p->left) + no_leaf_sum(p->right);
    }
    return 0;
}
int main()
{
    tree* root = new(tree);
    int x, a = 1;
    cout << "input x"<<"\n";
    cin >> x;
    root->info = x;
    root->left = NULL;
    root->right = NULL;
    cin >> x;
    while (x)
    {
        add(root, x);
        cin >> x;
    }
    //leaf_proiz(root,a);
    //cout << a;
    
    //leaf_pro(root,con_2,a);
    //cout << a;

    cout << no_leaf_sum(root);
}