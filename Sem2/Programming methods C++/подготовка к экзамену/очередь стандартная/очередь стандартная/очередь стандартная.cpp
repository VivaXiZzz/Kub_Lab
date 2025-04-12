#include <iostream>
#define MAX_SIZE_QUEUE 1000
using namespace std;
typedef int T;
struct Queue {
	T data[MAX_SIZE_QUEUE];
	int head = 0;
	int tail = 0;
};
void push(Queue* queue, const T value)
{
	queue->data[queue->tail] = value;
	queue->tail++;
}
T pop(Queue* queue)
{
	queue->head++;
	return queue->data[queue->head - 1];
}
bool empty(Queue* queue)
{
	return queue->head == queue->tail;
}
bool full(Queue* queue)
{
	return queue->tail >= MAX_SIZE_QUEUE;
}
int main()
{
	Queue queue;
	for (int i = 0;i < 30;++i)
	{
		if (!full(&queue))
			push(&queue, i);
		else
		{
			cout << "queue is full\n";
			break;
		}
		cout << pop(&queue)<<" ";
	}
}