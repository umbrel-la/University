#include <iostream>

using namespace std;

struct A
{
	int key;
};

struct List
{
	A a;
	List *next;
};

void init(List **begin);
void showList(List *begin);
void Init(List **begin, const A& a);
void DeleteList(List **begin, const A& b);
void freeList(List **begin);

int main()
{
	List *begin = NULL;
	A a = { 33 }, b = {44};
	init(&begin);
	showList(begin);
	Init(&begin, a);
	showList(begin);
	DeleteList(&begin, b);
	showList(begin);
	freeList(&begin);
	showList(begin);
	system("pause");
}

void init(List **begin)
{
	A a[5] = { 11, 12, 44, 55, 66 };
	*begin = new List;
	(*begin)->a.key = 5;
	(*begin)->next = NULL;
	List *end = *begin;
		
	for (int i = 0; i < 5; i++)
	{
		end->next = new List;
		end = end->next;
		end->a = a[i];
		end->next = NULL;
	}
}

void showList(List *begin)
{
	List *ptr = begin;
	while (ptr)
	{
		cout << ptr->a.key << "->";
		ptr = ptr->next;
	}
	cout << "NULL";
	cout << endl;
}


void Init(List **begin, const A& a)
{
	List *ins = new List;
	ins->a = a;
	if (*begin == NULL)
	{
		ins->next = NULL;
		*begin = ins;
		return;
	}
	List *t = *begin;
	if (t->a.key >= ins->a.key)
	{
		ins->next = t;
		*begin = ins;
		return;
	}
	List *t1 = t->next;
	while (1)
	{
		if (t->a.key < ins->a.key && ins->a.key <= t1->a.key)
		{
			t->next = ins;
			ins->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}

	t->next = ins;
	ins->next = NULL;
}

void DeleteList(List **begin, const A& b)
{
	
	if (*begin == NULL)
	{
		return;
	}
	List *t = *begin;
	if (t->a.key == b.key)
	{
		*begin = t->next;
		delete t;
		return;
	}
	List *t1 = t->next;
	while (t1)
	{
		if (t1->a.key == b.key)
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void freeList(List **begin)
{
	if (*begin == 0)
	{
		return;
	}
	List *p = *begin;
	List *t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
}