#include <iostream>
using namespace std;
struct list {
    int info;
    list*next;
    list*pred;
};
int minx;
list* init()
{
    int x;
    cin >> x;
    list* h = new(list);
    h->next = h;
    h->pred = h;
    if (x)
    {
        h->info = x;
        list* p = h;
        cin >> x;
        while (x)
        {
            list* q = new(list);
            q->info = x;
            q->next = h;
            h->pred = q;
            q->pred = p;
            p->next = q;
            p = q;
            cin >> x;
        }
    }
    return h;
}
    void print(list*p)
    {
        if (p == nullptr) {
            return;
        }
        list* b = p;
        do
        {
            cout << b->info << " ";
            b = b->next;
        } while (b != p);
}
    void del(list*& h)
    {
        list* b = h;
        do{
            list* q = h;
            h = h->next;
            delete q;
        } while (b != h);
    }

    int min(list* p) {
        int min = p->info;
        list* b = p;
        do
        {
            if (min > b->info)min = b->info;
            b = b->next;
        } while (b != p);
        return min;
    }

    void zam(list* p, int a)
    {
        list* b = p;
        do
        {
            if (b->info % 2 == 1)b->info = a;
            b = b->next;
        } while (b != p);
    }

    int sum_md_ravn(list* p)
    {
        int s = 0;
        list* b = p;
        do {
            if ((b->pred->info == b->next->info)&&b->info>0)s += b->info;
            b = b->next;
        } while (b != p);
        return s;
    }

    list*udal(list*&p,bool condition(list*h))
    {
        list*b = p;
        b = b->next;
        do
        {
        //list*q=b;
            if (condition(b))
            {
                b->pred->next = b->next;
                b->next->pred = b->pred;
            }
            b = b->next;
            //if(condition(b))delete q;
        } while (b!= p);
        
        if (condition(b))
        {
            list* q = new(list);
            b = b->next;
            delete q;
        }
        //if (condition(b))
        //{
        //    return nullptr;
        //}
        return b;
    }


    bool con_1(list* p)
    {
        if (p->info == ::minx)return 1;
        return 0;
    }

    bool con_2(list* p)
    {
        int a = 0;
        for (int i = 1;i < p->info;i++)if (p->info % i == 0)a += i;
        if (a == p->info)
            return 1;
        return 0;
    }

    bool con_3(list* p)
    {
        int a = p->info;
        while (a)
        {
            if (a % 10 == 5)return 1;
            a /= 10;
        }
        return 0;
    }

    list* vstav(list* p, bool condition(list* p),int a,bool d)
    {
        list* b = p;
        if(d)
        {
            do {//vstav posle
                if (condition(b))
                {
                    list* q = new(list);
                    q->info = a;
                    q->pred = b;
                    q->next = b->next;
                    b->next->pred = q;
                    b->next = q;
                    b = q;
                }
                b = b->next;
            } while (b != p);
        }
        else
        {
            do {
                if (condition(b))
                {
                    list* q = new(list);
                    q->info = a;
                    q->pred = b->pred;
                    q->next = b;
                    b->pred->next = q;
                    b->pred = q;
                }
                b = b->next;
            } while (b != p);
        }
        return b;
    }
    bool con_4(list* p)
    {
        if (p->info > 0)return 1;
        return 0;
    }
    int maxA(list*p)
    {
        int max = p->info;
        list* b = p;
        do
        {
            if (max < b->info)max = b->info;
            b = b->next;
        } while (b != p);
        return max;
    }

int main()
{
    list* h = init();

    //::minx = min(h);

    ::minx = maxA(h);

    //zam(h, mint);

    //cout<<sum_md_ravn(h)<<endl;

    //h = udal(h, con_3);

    h = vstav(h, con_4, ::minx, 0);

    print(h);

    del(h);
}
