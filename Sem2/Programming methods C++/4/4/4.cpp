#include <iostream>
using namespace std;

struct list
{
	int info;
	list* next;
};

typedef list l;

int main()
{
	int x,s;
	l* h = new l;
	//cin >> s;
	cin >> x;
	h->info = x;
	h->next = NULL;
	l* p = h;
	cin >> x;
	while (x != 0)
	{
		l* q = new l;
		q->info = x;
		q->next = NULL;
		p->next = q;
		cin >> x;
		p = p->next;
	}
	p = h;
	//int k = 0;
	//while (p->next != NULL)
	//{
	//	if (p->info < s && p->next->info < 0)k++;
	//	p = p->next;
	//}
	//cout << k;

	//int min = p->info;
	//int k = 0;
	//p = p->next;
	//while (p != NULL)
	//{
	//	min=(min > p->info) ? p->info : min;
	//	p = p->next;
	//}
	//p = h;
	//while (p != NULL)
	//{
	//	if (min == p->info)k++;
	//	p = p->next;
	//}
	//cout << k;
	
	//int k = 0;

	//while (p->next != NULL) {
	//	if (p->info % 2 == 0 && p->next->info % 3 == 0)k += p->info;
	//	p = p->next;
	//}
	//cout << k;

	int k = 0;
	while (p->next != NULL)
	{
		if (p->info < 0 && p->next->info>0)k++;
			p = p->next;
	}
	cout << k;
}
