#include <iostream>
using namespace std;
typedef struct l
{
    int info;
    l* next;
};

bool sov(int p)
{
    int k = 0;
    for (int i = 1;i < p;i++)if (p % i == 0)k += i;
    return (p == k);
}

int prost(int p)
{
    int k = 0;
    for (int i = 2;i < p;i++)if (p % i == 0)k++;
    if (k < 1)return p;
    return 0;
}

bool prostsum(int p) {
    int k = 0;
    int s = 0;
    int p1 = p;
    while (p)
    {
        k += p % 10;
        p /= 10;
    }
    for (int i = 2;i < k;i++)if (k % i == 0)s++;
    if (s < 1)return 1;
    return 0;
}

int main()
{
    int x;
    cin >> x;
    l* h = new l;
    h->info = x;
    h->next = NULL;
    l* p = h;
    cin >> x;
    while (x)
    {
        l* q = new l;
        q->info = x;
        q->next = NULL;
        p->next = q;
        p = p->next;
        cin >> x;
    }
    p = h;

    //int max = p->info; //вставить после пол элементы со значением макс
    //p = p->next;
    //while (p != NULL)
    //{
    //    if (p->info > max)max = p->info;
    //    p = p->next;
    //}
    //p = h;
    //while (p->next != NULL)
    //{
    //    if (p->info > 0) {
    //        l* q = new l;
    //        q->info = max;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}

    //int s = 0; //новый элемент равный сумме модулей отрицательных перед нечетными
    //while (p->next != NULL) {
    //    if (p->info < 0)s += abs(p->info);
    //    p = p->next;
    //}
    //p = h;
    //while (p->next != NULL) {
    //    if (p->next->info % 2 == 1) {
    //        l* q = new l;
    //        q->info = s;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}
    //if (h->info % 2 == 1)
    //{
    //    l* q = new l;
    //    q->info = s;
    //    q->next = h;
    //    h = q;
    //}

    //bool f = 1;
    //while (p->next != NULL) {
    //    if (p->info >= p->next->info)f = 0;
    //    p = p->next;
    //}
    //if (f)cout << "yea list is increasing\n";
    //else cout << "no it isnt\n";

    //int k = 0;
    //while (p!= NULL) { //после каждого отрицательного вставить элемент равный количеству положительнх элементов
    //    if (p->info > 0)k++;
    //        p = p->next;
    //}
    //p = h;
    //while (p != NULL)
    //{
    //    if (p->info < 0) {
    //        l* q = new l;
    //        q->info = k;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}
    //if (h->info < 0)
    //{
    //    l* q = new l;
    //    q->info = k;
    //    q->next = h;
    //    h = q;
    //}

    //while (p != NULL)
    //{   
    //    int k = 0;
    //    for (int i = 2;i < p->info;i++)
    //        if (p->info % i == 0)k++;
    //        if (k<2) {
    //            l* q = new l;
    //            q->info = 13;
    //            q->next = p->next;
    //            p->next = q;
    //            p=q;          
    //    }
    //    p = p->next;
    //}
    //int k = 0;
    //for (int i = 2;i < h->info;i++) 
    //    if (h->info % i == 0)k++;
    //    if(k<2) {
    //        l* q = new l;
    //        q->info = 13;
    //        q->next = h;
    //        h = q;
    //}

    //while (p->next != NULL)
    //{
    //    if (sov(p->info) && sov(p->next->info))
    //    {
    //        l* q = new l;
    //        q->info = 5;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}

    //int sum = 0;
    //while (p != NULL)
    //{
    //    sum += prost(p->info);
    //    p = p->next;
    //}
    //p = h;
    //while (p->next != NULL)
    //{
    //    if(p->info%2==0){
    //        l* q = new l;
    //        q->info = sum;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}
    //if (h->info % 2 == 0)
    //{
    //    l* q = new l;
    //    q->info = sum;
    //    q->next = h;
    //    h = q;
    //}

    //int s = 0;
    //while (p != NULL)
    //{
    //    if (sov(p->info))s += p->info;
    //    p = p->next;
    //}
    //p = h;
    //while (p->next != NULL) {
    //    if (p->info % 10 == 4) {
    //        l* q = new l;
    //        q->info = s;
    //        q->next = p->next;
    //        p->next = q;
    //        p = q;
    //    }
    //    p = p->next;
    //}
    //if (h->info % 10 == 4)
    //{
    //    l* q = new l;
    //    q->info = s;
    //    q->next = h;
    //    h = q;
    //}

    int s = 0;
    while (p != NULL)
    {
        s += prost(p->info);
        p = p->next;
    }
    p = h;
    bool f=0;
    while (p != NULL)
    {
        if (prostsum(p->info))f = 1;
        p = p->next;
    }
    cout << f<<"\n";
    p = h;
    if (f)
    {
        while (p != NULL)
        {
            if (sov(p->info))
            {
                l* q = new l;
                q->info = s;
                q->next = p->next;
                p->next = q;
                p = q;
            }
            p = p->next;
        }
    }
    p = h;
    if(!f)
    {
        while (p->next != NULL)
        {
            if (sov(p->next->info))
            {
                l* q = new l;
                q->info = s;
                q->next = p->next;
                p->next = q;
                p = q;
            }
            p = p->next;
        }
        if (sov(h->info))
        {
            l* q = new l;
            q->info = s;
            q->next = h;
            h = q;
        }
    }

    p = h;
    while (p != NULL)
    {
        cout << p->info<<" ";
        p = p->next;
    }

    p = h;
    while (p != NULL)
    {
        l* d = p;
        p = p->next;
        delete d;
    }
}
