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
    while (p != NULL){
    cout << p->info << " ";
    p = p->next;
}
}
    void del(list* p) {
        while (p != NULL){
        list* d = p;
        p = p->next;
        delete d;
    }
}
    int sum(list* h)
    {
        list* p = h;
        int s = 0;
        while (p != NULL) {
            if (p->info > 0)s += p->info;
            p = p->next;
        }
            return s;
    }
    bool sim(list* h) {
        list* p = h;
        list* q = h;
        while (p->next!= NULL) {
            p = p->next;
        }
        while (p != h) {
            if (p->info != q->info)return 0;
            p = p->pred;
            q = q->next;
        }
        return 1;
    }
    int sum_in_ravn(list* h)
    {
        list* p = h;
        int s = 0;
        while (p->next->next!= NULL)
        {
            if (p->info == p->next->next->info)s += p->next->info;
            p = p ->next;
        }
        return s;
    }
    int ne_prev_x_pos_otrits(list* h)
    {
        list* p = h;
        int x,s(0);
        cout << "vvedi x" << endl;
        cin >> x;
        while (p->next != NULL)
        {
            if (p->info < x && p->next->info < 0)s += p->info;
            p = p->next;
        }
        return s;
    }
    int chet_sum(list* h)
    {
        list* p = h;
        int s = 0;
        while (p != NULL)
        {
            if (p->info % 2 == 0)s += p->info;
            p = p->next;
        }
        return s;
    }
    int zam(list* h, int s)
    {
        while (h != NULL)
        {
            if(h->info%2==0)h->info = s;
            h = h->next;
        }
        return s;
    }
int main()
{
    list* h = init();

    //cout << sum(h) << endl;
    
    //if (sim(h))cout << "ye"<<endl;
    //else cout << "no"<<endl;
    
    //cout<<sum_in_ravn(h)<<endl;

    //cout << ne_prev_x_pos_otrits(h) << endl;

    if (sim(h))
    {
        int s = chet_sum(h);
        zam(h, s);
    }

    print(h);
    del(h);
}
