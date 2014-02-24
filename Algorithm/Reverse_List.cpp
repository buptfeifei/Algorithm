#include "stdafx.h"
#include "Reverse_List.h"
#include <iostream>
using namespace std;

Reverse_List::Reverse_List(void)
{
}


Reverse_List::~Reverse_List(void)
{
}
Reverse_List::Reverse_List(int value)
{
	element = value;
	next = NULL;
}

Reverse_List* Reverse_List::gen_list(int* array,int size)
{
	if(array !=NULL && size >0)
	{
			
		Reverse_List* head = new Reverse_List(array[0]);
		Reverse_List* p = head;
		Reverse_List* q = NULL;
		for(int i=1;i<size;i++)
		{
			q = new Reverse_List(array[i]);
			p->set_next(q);
			p = q;
		}
		return head;
	}
	cout<<"array is error"<<endl;
	return NULL;
}
void Reverse_List::print_list(Reverse_List* head)
{
	Reverse_List* tmp = head;
	while (tmp != NULL)
	{
		cout<<tmp->get_element()<<endl;
		tmp=tmp->get_next();
	}
}
Reverse_List* Reverse_List::iterative_process(Reverse_List* head)
{
	if(head != NULL && head->get_next() != NULL)
	{
		Reverse_List* p = head;
		Reverse_List* q = head->get_next();
		head->set_next(NULL);
		while (q->get_next() != NULL)
		{
			Reverse_List* tmp = q->get_next();
			q->set_next(p);
			p = q;
			q = tmp;
		}
		q->set_next(p);
		return q;
	}
	return NULL;
}
Reverse_List* Reverse_List::recursive_process(Reverse_List* head,Reverse_List*& newhead)
{
	if(head != NULL)
	{
		if(head->get_next()==NULL)
		{
			newhead = head;
			return head;
		}
		else
		{
			Reverse_List* tmp = recursive_process(head->get_next(),newhead);
			tmp->set_next(head);
			return head;
		}
	}
	return NULL;
}
