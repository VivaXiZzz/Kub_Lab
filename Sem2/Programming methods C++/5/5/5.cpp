#include <iostream>
#include <string>
using namespace std;

struct list
{
    int info;
    list* next;
};

int main()
{
    int x;
    cin >> x;
    list* h = new list;
    h->info = x;
    h->next = NULL;
    list* p = h;
    cin >> x;
    while (x)
    {
        list* q = new list;
        q->info = x;
        q->next = NULL;
        p->next = q;
        p = p->next;
        cin >> x;
    }
    p = h;
    //if (p->next != NULL) {
    //    while (p->next->next != NULL)
    //    {
    //        if (p->info == p->next->next->info)
    //        {
    //            list* d = p->next;
    //            p->next = d->next;
    //            delete d;
    //        }
    //        p = p->next;
    //    }
    //    p = h;
    //    while (p != NULL)
    //    {
    //        cout << p->info << " ";
    //        p = p->next;
    //    }
    //    while (p != NULL)
    //}

    //while (p->next!= NULL)
    //{
    //    int k = 0;
    //    for (int i = 2;i < p->next->info;i++)if(p->next->info%i==0)k++;
    //    if (k == 0)
    //    {
    //        list* r = p->next;
    //        p->next = r->next;
    //        delete r;
    //    }
    //    else p = p->next;
    //}
    //p = h;
    //while (p != NULL)
    //{
    //    cout << p->info<< " ";
    //    p = p->next;
    //}

    //while (p->next != NULL)
    //{
    //    if (p->info % 2 == 0 && p->next->info % 10 == 3)
    //    {
    //        list* q = p->next;
    //        p->next = q->next;
    //        delete q;
    //    }
    //    p = p->next;
    //}
    //p = h;
    //while (p != NULL)
    //{
    //    cout << p->info << " ";
    //    p = p->next;
    //}


    //int min = p->info;    хорошая реализация c удалением головы
    //p = p->next;
    //while (p != NULL)
    //{
    //    if (min > p->info)min = p->info;
    //    p = p->next;
    //}
    //p = h;
    //while (p->next != NULL)
    //{
    //    if (p->next->info == min)
    //    {
    //        list* q = p->next;
    //        p->next = q->next;
    //        delete q;
    //    }
    //    else p = p->next;
    //}
    //if (h->info == min)
    //{
    //    list* q = h;
    //    h = h->next;
    //    delete q;
    //}
    //p = h;
    //while (p != NULL)
    //{
    //    cout << p->info<< " ";
    //    p = p->next;
    //}

    //while (p->next->next != NULL)
    //{
    //    int k = 0;
    //    for (int i = 1;i < p->next->info;++i)
    //    {
    //        if (p->next->info % i == 0)k += i;
    //    }
    //    cout << k<<" ";
    //    if (k == p->next->info && p->next->next->info % 3 == 0)
    //    {
    //        list* q = p->next;
    //        p->next = q->next;
    //        delete q;
    //    }
    //    else p = p->next;
    //}
    //p = h;
    //while (p != NULL)
    //{
    //    cout << p->info << " ";
    //    p = p->next;
    //}

//while (p->next != NULL)
//{
//    if (p->next->info % 10 == 5)
//    {
//        list* q = p->next;
//        p->next = q->next;
//        delete q;
//    }
//    else p = p->next;
//}
//    p = h;
//    while (p != NULL)
//    {
//        cout << p -> info << " ";
//        p = p->next;
//    }


//bool f = 1;
    //while (p->next != NULL)
    //{
    //    if (p->info >= p->next->info)
    //    {
    //        f = 0;
    //    }
    //    p = p->next;
    //}
    //p = h;
    //if (f)
    //{
    //    while (p->next != NULL)
    //    {
    //        int k = 0;
    //        for (int i = 1;i < p->next->info;++i) {
    //            if (p->next->info % i == 0)k += i;
    //        }
    //        //cout << "k=" << k << " ";
    //        if (k == p->next->info)
    //        {
    //            list* q = p->next;
    //            p->next = q->next;
    //            delete q;
    //        }
    //        else p = p->next;
    //    }
    //}
    //if (!f) {
    //    while (p->next != NULL)
    //    {
    //        if (p->next->info < 0)
    //        {
    //            list* q = p->next;
    //            p->next = q->next;
    //            delete q;
    //        }
    //        else p = p->next;
    //    }
    //}

    //float s = 0,k=0;
//while (p != NULL)
//{
//    if (p->info > 0)s += p->info,k++;
//    p = p->next;
//}
//s /= k;
//p = h;
//while (p->next != NULL)
//{
//    if (p->next->info < s)
//    {
//        list* q = p->next;
//        p->next = q->next;
//        delete q;
//    }
//    else p = p->next;
//}

    //while (p->next != NULL)
    //{
    //    int k = 0;
    //    for (int i = 2;i < p->next->info;i++)if (p->next->info % i == 0)k++;
    //    if (!k && p->info % 5 == 0) {
    //        list* q = p->next;
    //        p->next = q->next;
    //        delete q;
    //    }
    //    else p = p->next;
    //}

    while (p->next != NULL)
    {
        int k = p->next->info;
        int s = 0;
        while (k)
        {
            s += k%10;
            k /= 10;
        }
        if (s % 2 == 0) {
            list* q = p->next;
            p->next = q->next;
            delete q;
        }
        else p = p->next;
    }
    p = h;
            while (p != NULL)
            {
                cout << p->info << " ";
                p = p->next;
            }
        p = h;
        while (p != NULL)
        {
            list* r = p;
            p = p->next;
            delete r;
        }
    }

