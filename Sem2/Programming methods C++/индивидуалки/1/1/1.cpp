#include <iostream>
using namespace std;
struct list
{
    int info;
    list* next;
};
void gen(list*& p, list*& h)
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

void print(list*& p,list*&h)
{
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "\n";
    p = h;
}

void del(list*& h)
{
    while (h != NULL) {
        list* d = h;
        h = h->next;
        delete d;
    }
}

int main()
{
    int x;
    list* h = new list;
    cin >> x;
    h->info = x;
    h->next = NULL;
    list* p = h;
    gen(p, h);
    print(p, h);
    del(p);
}
