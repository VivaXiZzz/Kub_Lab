
#include <iostream>
using namespace std;
struct list {
    int info;
    list* next;
    list* pred;
};
list* init()
{
    int x;
    list* h = new list;
    h->next = h->pred = NULL;
    cin >> x;
    if (x) {
        h->info = x;
        list* p = h;
        cin >> x;
        while (x)
        {
            list* q = new list;
            q->info = x;
            q->next = NULL;
            q->pred = p;
            p->next = q;
            p = q;
            cin >> x;
        }
    }
    return h;
}
void print(list* h)
{
    list* p = h;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}
void del(list* p) {
    while (p != NULL) {
        list* d = p;
        p = p->next;
        delete d;
    }
}
void vstav(list*& h, bool condition(list* p), int s, bool f) {
    if (f) {//vstavka posle
        {
            list* p = h;
            while (p != NULL) {
                if (condition(p))
                {
                    list* q = new list;
                    q->info = s;
                    q->next = p->next;
                    q->pred = p;
                    p->next = q;
                    p = q;
                }
                p = p->next;
            }
        }
    }
    if (!f) {//vstavka do
        list* p = h;
        list* r = h;
        p = p->next;
        while (p != NULL) {
            if (condition(p))
            {
                list* q = new list;
                q->info = s;
                q->pred = p->pred;;
                q->next = p;
                p->pred->next = q;
                p->pred = q;
            }
            p = p->next;
        }
        if (condition(r))
        {
            list* q = new list;
            q->info = s;
            q->next = r;
            r->pred = q;
            q->pred = NULL;
            r = q;
        }
    }
}
int max(list* p)
{
    int s = p->info;
    p = p->next;
    while (p != NULL)
    {
        if (s < p->info)s = p->info;
        p = p->next;
    }
    return s;
}
bool con_1(list* p)
{
    if (p->next != NULL)if (p->next->info > 0)return 1;
    return 0;
}
bool con_2(list* p)
{
    if (p != NULL)if (p->info < 0)return 1;
    return 0;
}
int kol_pol(list* p)
{
    int k = 0;
    while (p != NULL) {
        if (p->info > 0)k++;
        p = p->next;
    }
    return k;
}
bool con_3(list* p)
{
    if (p != NULL)if (p->next != NULL)if (p->next->next != NULL) {
        int a(0);
        for (int i = 1;i < p->info;i++)if (p->info % i == 0)a += i;
        cout << a << endl;
        if (a == p->info) {
            a = 0;
            for (int i = 1;i < p->next->info;i++)if (p->info % i == 0)a += i;
            if (a == p->next->info)if (p->info == p->next->info)return 1;
        }
    }
    return 0;
}
bool ub(list* p)
{
    while (p->next != NULL)
    {
        if (p->info <= p->info)return 0;
        p = p->next;
    }
    return 1;
}
bool con_4(list* p)
{
    if (p->info % 10 == 3)return 1;
    return 0;
}
int main()
{
    list* h = init();
    list* d = h;
    int s;

    int k = max(h);

    //s = kol_pol(h);

    //if (ub(h))
    
    if (ub(h))vstav(h, con_3, k, 0);
    else vstav(h, con_2, 5, 1);

    print(h);
    del(h);
}
