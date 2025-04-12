#include <iostream>
#include <algorithm>
using namespace std;
struct tree {
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
            q->left = NULL;
            q->right = NULL;
            t->left = q;
        }
        else add(t->left, x);
    else
        if (t->right == NULL)
        {
            tree* q = new(tree);
            q->info = x;
            q->left = NULL;
            q->right = NULL;
            t->right = q;
        }
        else add(t->right, x);
}
    void print(tree * t)
    {
        if(t!=NULL){
        cout << t->info<<" ";
        print(t->left);
        print(t->right);
    }
}
    int min(tree* t)
    {
        if (t->left!= NULL)return min(t->left);
        return t->info;
    }
    int leaf_sum(tree* t)
    {
        if (t != NULL)
        {
            if (t->left == NULL && t->right == NULL)
                return t->info + leaf_sum(t->right) + leaf_sum(t->left);
        return leaf_sum(t->right) + leaf_sum(t->left);
        }
        return 0;
    }   
    void zam(tree*t,int x)
    {
        if (t != NULL)
        {
            if (t->info % 2 == 0)t->info = x;
            zam(t->left, x);
            zam(t->right, x);
        }
        return;
    }
    bool con_1(tree* t)
    {
        if (t->info % 3 == 0)return 1;
        return 0;
    }
    void uv(tree* t, bool f(tree* p))
    {
        if (t != NULL)
        {
            if(f(t))t->info *= 2;
            uv(t->right, f);
            uv(t->left, f);
        }
        return;
    }
    bool con_2(tree* t)
    {//я хз по поводу того колво делителей это до самого числа или нет и с 1
        int k = 0;
        for (int i = 1;i <= t->info;++i,k!=4)if(t->info%i==0)k++;
        if (k == 3)return 1;
        return 0;
    }
    void m_1(tree* t, bool f(tree* p))
    {
        if (t != NULL)
        {
            if (f(t))t->info -= 1;
            m_1(t->right, f);
            m_1(t->left, f);
        }
        return;
    }
    bool con_3(tree* t)
    {// я до сих пор не знаю
        int k = 0;
        for (int i = 1;i <= t->info;++i)if (t->info % i == 0)k++;
        if (k % 2 == 0)return 1;
        return 0;
    }
    int counter(tree* t, bool f(tree* p))
    {
        if (t != NULL)
        {
            if (f(t))
                return 1 + counter(t->left, f) + counter(t->right, f);
            return counter(t->left, f) + counter(t->right, f);
        }
        return 0;
    }
    void zam(tree* t)
    {
        if (t != NULL)
        {
            if (t->info < 0)
                t->info = 13;
            zam(t->left);
            zam(t->right);
        }
        return;
    }
int main()
{
    int x;
    tree* root = new(tree);
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
    //cout << min(root);

    //int s = leaf_sum(root);

    //zam(root, s);

    //uv(root, con_1);

    //m_1(root, con_2);

    //cout<<counter(root, con_3);

    zam(root);

    print(root);
}
