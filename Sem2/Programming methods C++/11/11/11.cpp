#include <iostream>
using namespace std;
int min;
struct list
{
    int info;
    list* next;
    list* pred;
};
list* init()
{
    int x;
    cin >> x;
    list* h = new(list);
    h->next = NULL;
    h->pred = NULL;
    if (x) {
        h->info = x;
        list* p = h;
        cin >> x;
        while (x)
        {
            list* q = new(list);
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
    void print(list * h)
    {
        while (h != NULL)
        {
            cout << h->info<<" ";
            h = h->next;
        }
    }
    void del (list*& h)
    {
        while (h != NULL)
        {
            list* d = h;
            h = h->next;
            delete d;
        }
    }
    list* del_con(list* h,bool condition(list*h))
    {
        list* p = h;
        h = h->next;
        list* q = new(list);
        while (h!= NULL)
        {
            if (condition(h))
            {   
                q = h;
                h->pred->next = h->next;
                if (h->next != NULL)h->next->pred = h->pred;
                h = h->next;
                delete q;
            }   
            else h = h->next;
        }
        if (condition(p))
        {
            list* q = p;
            p = p -> next;
            delete q;
        }
        return p;
    }
    bool con_1(list* h)
    {
        if (h->next != NULL && h->pred!=NULL)
        {
            if (h->pred->info == h->next->info)return 1;
        }
        return 0;
    }
    bool con_2(list* h)
    {
        if (h != NULL)
            for (int i = 2;i < h->info;++i)if (h->info % i == 0)return 0;
            return 1;
    }
    bool con_3(list* h)
    {
        if(h->next!=NULL)if (h->info % 2 == 0 && h->next->info % 10 == 3)return 1;
        return 0;
    }
    int mint(list* p)
    {
        int mint = p->info;
        p = p->next;
        while (p->next!=NULL)
        {
            if (mint > p -> info)mint = p->info;
            p = p->next;
        }
        return mint;
    }
    bool con_4(list* h)
    {
        if (h->info == ::min)return 1;
        return 0;
    }
    bool sov(int d)
    {
        int a = 0;
        for (int i = 1;i < d;i++)if (d % i == 0)a += i;
        if (d == a)return 1;
        return 0;
    }
    bool con_5(list* h)
    {
        if (sov(h->info) && h->next != NULL && h->next->info % 2 == 0)
        return 1;
        return 0;
    }
    bool check_5(int a)
    {
        int d=a;
        while (d)
        {
            if (d % 10 == 5)return 1;
            d /= 10;
        }
        return 0;
    }
    bool con_6(list* h)
    {
        if (check_5(h->info))return 1; 
        return 0;
    }
    bool con_7(list* h)
    {
        int a = h->info;
        while (a > 9)
        {
            a /= 10;
        }
        if (a % 10 == 5)return 1;
        return 0;
    }
    bool con_8(list* h)
    {
        int a(h->info), s(0);
        while (a)
        {
            s += a % 10;
            a /= 10;
        }
        if (s % 2 != 0)return 1;
    return 0;
    }

int main()
{
    list* h = init();

    //::min = mint(h);

    h = del_con(h, con_8);

    print(h);
    del(h);
}
