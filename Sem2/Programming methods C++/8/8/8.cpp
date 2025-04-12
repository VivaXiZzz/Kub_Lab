#include <iostream>
using namespace std;
struct list
{
	int info;
	list* next;
};
void gen(list*& p, list* h)
{
	int x;
	cin >> x;
	while (x)
	{
		list* q = new list;
		q->info = x;
		q->next = NULL;
		p->next = q;
		p = q;
		cin >> x;
	}
	p = h;
}
void print(list*& p, list* h)
{
	while (p != NULL) {
		cout << p->info << " ";
		p = p->next;
	}
	p = h;
}
void del(list*& p, list*& h)
{
	while (p != NULL) {
		list* d = p;
		p = p->next;
		delete d;
	}
}
float sum(list* p, int& k, int& s)
{
	if (p != NULL) {
		if (p->info > 0)k++, s += p->info;
		sum(p->next, k, s);
	}
	return(float)s / k;
}
void square(list*& p)
{
	if (p != NULL) {
		if (p->info > 0)p->info *= p->info;
		square(p->next);
	}
}
int count3or5(list*& p)
{
	if (p != NULL)
	{
		if (p->info % 10 == 3 || p->info % 10 == 5)return count3or5(p->next) + 1;
		return count3or5(p->next);
	}
	return 0;
}
int primarysum(list*& p)
{
	if (p != NULL)
	{
		for (int i = 2;p->info > i;i++) {
			if (p->info % i == 0)break;
			if (p->info % (i + 1) == 0)return primarysum(p->next) + 1;
		}
		if (p->info == 1)return primarysum(p->next) + 1;
		if (p->info == 2)return primarysum(p->next) + 1;
		return primarysum(p->next);
	}
	return 0;
}
int sum1(list* p)
{
	if (p != NULL)
	{
		int x = p->info;
		while (x)
		{
			if (x % 10 == 1)return sum1(p->next) + p->info;
			x /= 10;
		}
		return sum1(p->next);
	}
	return 0;
}
int chetproiz(list*& p, int& c)
{
	if (p != NULL)
	{
		if (p->info % 2 == 0)c *= p->info;
		return chetproiz(p->next, c);
	}
	return c;
}
int chetproizcifr(list*& p, int& c)
{
	if (p != NULL)
	{
		int x = p->info;
		int s = 0;
		while (x)
		{
			s += x % 10;
			x /= 10;
		}
		if (s % 2 == 0)c *= p->info;
		return chetproiz(p->next, c);
	}
	return c;
}
void uv2kr5(list*& p)
{
	if (p != NULL)
	{
		if (p->info % 5 == 0)p->info = 2 + p->info;
		uv2kr5(p->next);
	}
}
void inselemifkr2(list*& p)
{
	if (p != NULL) {
		if (p->info % 2 == 0)
		{
			list* q = new list;
			q->info = 25;
			q->next = p->next;
			p->next = q;
			p = q;
		}
		inselemifkr2(p->next);
	}
}

int main()
{
	int x, k = 0, s = 0, c = 1;
	cin >> x;
	list* h = new list;
	h->info = x;
	h->next = NULL;
	list* p = h;
	gen(p, h);

	//cout<<sum(p,k,s);

	//square(p);
	//p = h;

	//cout << count3or5(p) << endl;

	//cout << primarysum(p) << endl;

	//cout << sum1(p) << endl;

	//cout << chetproiz(p,c) << endl;

	//cout << chetproizcifr(p, c) << endl;

	//uv2kr5(p);
	//p = h;

	//там задачки отвратительные дальше и долгие

	inselemifkr2(p);

	print(p, h);
	del(p, h);
}
