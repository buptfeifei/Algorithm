#include "stdafx.h"
#include "Reverse_List.h"
#include <iostream>
using namespace std;

Reverse_List::Reverse_List(void)
{
}


Reverse_List::~Reverse_List(void)
{
	element = 0;
	next = NULL;
}
Reverse_List::Reverse_List(int value)
			:element(value),next(NULL)
{
	
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
			p->next =  q;
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
		cout<<tmp->element<<endl;
		tmp=tmp->next;
	}
}
Reverse_List* Reverse_List::iterative_process(Reverse_List* head)
{
	if(head != NULL && head->next != NULL)
	{
		Reverse_List* p = head;
		Reverse_List* q = head->next;
		head->next = NULL;
		while (q->next != NULL)
		{
			Reverse_List* tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}
		q->next = p;
		return q;
	}
	return NULL;
}
Reverse_List* Reverse_List::recursive_process(Reverse_List* head,Reverse_List*& newhead)
{
	if(head != NULL)
	{
		if(head->next ==NULL)
		{
			newhead = head;
			return head;
		}
		else
		{
			Reverse_List* tmp = recursive_process(head->next,newhead);
			tmp->next = head;
			return head;
		}
	}
	return NULL;
}
void Reverse_List::delete_list(Reverse_List* head)
{
	if(head != NULL)
	{
		while (head != NULL)
		{
			Reverse_List* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
}