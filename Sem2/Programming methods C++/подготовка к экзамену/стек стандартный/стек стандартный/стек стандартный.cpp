#include <iostream>
#define STACK_MAX_SIZE 1000
using namespace std;
typedef int T;

struct Stack_t {
    T data[STACK_MAX_SIZE];
    size_t size; //синоним инт
};

bool full(Stack_t* stack)
{
    return(stack->size >= STACK_MAX_SIZE);
}

bool empty(Stack_t* stack)
{
    return(stack->size == 0);
}

void push(Stack_t* stack, const T value)
{
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t* stack)
{
    stack->size--;
    return stack->data[stack->size];
}

int main()
{
    Stack_t stack;
    stack.size = 0;
    for (int i = 0;i < 30;i++)
    {
        if (!full(&stack))push(&stack, i);
        else
        {
            cout << "stack is full";
            break;
        }
        if (!empty(&stack))
        {
            cout << pop(&stack)<<" ";
        }
    }
}
