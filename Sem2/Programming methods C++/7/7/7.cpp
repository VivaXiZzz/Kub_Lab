#include <iostream>
using namespace std;
struct list
{
    int info;
    list* next;
};
void gen(list*&p, list*&h)
{
    int x;
    cin >> x;
    while (x)
    {
        list* q = new list;
        q->info = x;
        q->next = NULL;
        p->next = q;
        p = q;
        cin >> x;
    }
    p = h;
}
void conditiongen(list*&p, int a)
{
        list* q = new list;
        q->info = a;
        q->next = NULL;
        p->next = q;
        p = q;
}
void print(list*&p)
{
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "\n";
}
bool perfcount(int p)
{
    int k = 0;
    for (int i = 1;i < p;i++)if (p % i == 0)k += i;
    if (k == p)return 1;
    return 0;
}
void del(list*& h)
{
    while (h != NULL) {
        list* d = h;
        h = h->next;
        delete d;
    }
}
    float sred(list * &h,list*&p)
    {
        float s = 0;
        float k = 0;
        while (h != NULL)
        {
            s += h->info;
            h = h->next;
        }
        h = p;
        return s /= k;
    }
int main()
{
    int x;
    list* h = new list;
    cin >> x;
    h->info = x;
    h->next = NULL;
    list* h1 = new list;
    h1->info = NULL;
    h1->next = NULL;
    list* h2 = new list;
    h2->info = NULL;
    h2->next = NULL;
    list* p2 = h2;
    list* p1= h1;
    list* p = h;
    gen(p,h);


    //while (p != NULL && h1->info == NULL) //////
    //{
    //    if (perfcount(p->info))
    //    {
    //        h1->info = p->info;
    //    }
    //    p = p->next;
    //    }
    //while (p != NULL)
    //{
    //    if (perfcount(p->info))conditiongen(p1, p->info);
    //    p = p->next;
    //}

    //while (p != NULL&&h1->info==NULL)
    //{
    //    if (p->info % 10 == 4)h1->info=p->info;
    //        p = p->next;
    //}
    //while (p != NULL)
    //{
    //    if (p->info % 10 == 4)conditiongen(p1, p->info);
    //        p = p->next;
    //}

    //while (p != NULL && h1->info == NULL)
    //{
    //    if (p->info % 2 == 0)h1->info = p->info;
    //    p = p->next;
    //}
    //while (p != NULL)
    //{
    //    if (p->info % 2 == 0)conditiongen(p1, p->info);
    //    p = p->next;
    //} /////// в кавычках тупая реализация

    gen(p1, h1);
    float s = sred(p,h), s1 = sred(p1,h1);
    while (p != NULL)
    {
        if (p->info > s)conditiongen(p2, p->info);
        p = p->next;
    }
    p = h;
    while (p1 == NULL)
    {
        if (p1->info > s1)conditiongen(p2, p->info);
        p = p->next;
    }
    p1 = h1;
    list* d = h2;
    h2 = h2->next;
    delete d;

    p = h;
    p1 = h1;
    p2 = h2;
    print(p2);
    //del(p2);
    del(p1);
    del(p);
}
