#include <iostream>
using namespace std;
struct Queue
{
    int info;
    Queue* next;
    Queue* prev;
};
Queue* Create()
{
    return NULL;
}
bool Empty(Queue* end)
{
    return end == NULL;
}
void Push(int Data, Queue*& end)
{
    Queue* r = new Queue;
    r->info = Data;
    if (!Empty(end))
    end->next = r;
    r->prev = end;
    r->next = NULL;
    end = r;
}
int Pop(Queue*& begin)
{
    if (!Empty(begin))
    {
        Queue* r = begin;
        int x = r->info;
        if (!Empty(begin->next))
            begin->next->prev = NULL;
        delete r;
        return x;
    }
    return NAN;
}
void Print(Queue*begin)
{
    while (!Empty(begin))cout << Pop(begin) << " ";
}
void Delete(Queue*& begin)
{
    while (!Empty(begin))Pop(begin);
}
int main()
{
    
}
