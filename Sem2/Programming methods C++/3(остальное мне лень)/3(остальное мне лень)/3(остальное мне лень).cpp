#include <iostream>
using namespace std;

struct list {
    int info;
    list* next;
};

int main()
{
    int x, s;
    cin >> x;
    list* h = new(list);
    h->info = x;
    h->next = NULL;
    list* p = h;
    cin >> x;
    while (x) {
        list* q = new list;
        q->info = x;
        q->next = NULL;
        p->next = q;
        p = q;
        cin >> x;
    }
    p = h;
    //bool f = 0;
    //while (p!= NULL) {
    //    if (p->info % 2 == 0)s *= p->info;

    //   if (p->info % 5 == 0)p->info *= 2;
    //    int k = 0;
    //    for (int i = 2; i < p->info;++i)
    //    {
    //        if (p->info % i == 0) {
    //            k++;
    //        }
    //        if (k < 1)f = 1;
    //    }
    //    p = p->next;
    //}
    //p = h;
    //if (f)
    //{
    //    while (p != NULL)
    //    {
    //        if (p->info % 2 == 0)p->info -= 1;
    //        p = p->next;
    //    }
    //}
    //if(!f)
    //{
    //    while (p != NULL)
    //    {
    //        if (p->info < 0)p->info = abs(p->info);
    //        p = p->next;
    //    }
    //}

    //    p = h;
    //    while (p != NULL) {
    //        cout << p->info << " ";
    //        p = p->next;
    //}
    //cout << s;

    //int k = 0;
    //while (p != NULL)
    //{
    //    if (p->info % 3 == 0)k++;
    //    p = p->next;
    //}
    //p = h;
    //if (k > 2)
    //{
    //    int t = 0;
    //    while (p != NULL)
    //    {
    //        t += p->info;
    //        p = p->next;
    //    }
    //    cout << t;
    //}
    //else
    //{
    //    int t = 1;
    //    while (p != NULL)
    //    {
    //        t *= p->info;
    //        p = p->next;
    //    }
    //    cout << t;
    //}
    int max = p->info;
    p = p -> next;
    while (p != NULL)
    {
        if(p->info > max)max = p->info;
        p = p->next;
    }
    cout << max;
}

