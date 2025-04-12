#include <iostream>
using namespace std;
struct Stack
{
    int info;
    Stack* next;
};
Stack* Create_Stack()
{
    return NULL;
};
bool IsEmpty(Stack* top)
{
    return top == NULL;
}
void StackPush(int Data, Stack*& top)
{
    Stack*r = new Stack;
    r->info = Data;
    r->next = top;
    top = r;
}
int pop(Stack*& top)
{
    if (!IsEmpty(top))
    {
        Stack* r = top;
        int x = r->info;
        top = top->next;
        delete r;
        return x;
    }
    return NAN;
}
void print(Stack*& top)
{
    while (!IsEmpty(top))
        cout << pop(top) << " ";
}
void Delete(Stack*& top)
{
    while (!IsEmpty(top))
        pop(top);
}

int main()
{
    setlocale(0, "rus");
    Stack* top = Create_Stack();
    
    //int x;
    //cout << "введите элементы\n";
    //for (cin >> x;x;cin >> x)
    //    StackPush(x, top);
    //    cout << endl << "Элементы стека:" << endl;
    //    print(top);

    bool flag = 1;
    for (char x = getchar();x != '\n';x = getchar())
    {
        switch (x)
        {
        case'(':
        case'[': {StackPush(x,top);break;}
        case')': {flag = flag && (pop(top) == '(');break;}
        case']': {flag = flag && (pop(top) == '[');break;}
        default:flag = false;//введен неверный символ
        }
    }
    flag = flag && IsEmpty(top);
    if (flag)cout << "да";
    else cout << "нет";

    Delete(top);
}
