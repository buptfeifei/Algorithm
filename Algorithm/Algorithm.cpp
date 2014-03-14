// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Quick_Sort.h"
#include "Fibonacci.h"
#include "Binary_Search.h"
#include "Find_Kth.h"
#include "Reverse_List.h"
#include "Binary_Tree.h"
#include "MyString.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	int test[] = {9,5,12,3,8,10,17,1,4};

	char s1[] = "ababababca";
	char s2[] = "bacbababababcacbab";
    char s3[] = "shang peng fei";
	MyString string1(s1,sizeof(s1) / sizeof(char) - 1);
	MyString string2(s2,sizeof(s2) / sizeof(char) - 1);
	int* finds = string2.strstr(string1);
	if(finds!=NULL)
	{
		cout<<" find string in"<<endl;
		int count = 0;
		while(finds[count] > -1)
			cout<<finds[count++];
		delete[] finds;
	}
	cout<<endl;

	cout<<sizeof(s3)<<endl;
	MyString string3(s3,sizeof(s3) / sizeof(char));
	
	string3.display();
	string3.shift_n(2);
	string3.display();

	finds = string3.strtok(' ');
	if(finds!=NULL)
	{
		cout<<" split string in"<<endl;
		int count = 0;
		int beg = 0;
		int end = 0;
		while(finds[count] > -1)
		{
			beg = finds[count++];
			end = finds[count++];
			while(beg < end)
				cout<<string3[beg++];
			cout<<endl;
		}
		delete[] finds;
	}
	cout<<endl;

 	Binary_Tree* root = Binary_Tree::gen_tree(test,sizeof(test) / sizeof(int));
	root->find_parent(root);
	root->set_parent(NULL);
	root->print_tree(root);

	Binary_Tree* next = root->find_next_node(root);
	cout<<"root next is "<<next->get_element()<<endl;
	Binary_Tree* prev = root->find_prev_node(next);
	cout<<"next prev is "<<prev->get_element()<<endl;

	int LCA = root->find_LCA(root,1,8);
	cout <<" 1 and 8 LCA is "<<LCA<<endl;

	Binary_Tree* LCA_pointer = NULL;
	LCA_pointer = root->find_LCA(root,root->find_pointer(root,1),root->find_pointer(root,8));
	if(LCA_pointer != NULL)
		cout<<"1 and 8 LCA pointer is "<<LCA_pointer->get_element()<<endl;
	root->delete_tree(root);
	root = NULL;

	Reverse_List* head = NULL;
	head = Reverse_List::gen_list(test,sizeof(test) / sizeof(int));
	cout<<"before reverse"<<endl;
	if(head != NULL)
		head->print_list(head);

	head = head->iterative_process(head);
	cout<<"after iterative reverse"<<endl;
	if(head != NULL)
		head->print_list(head);

	Reverse_List* newhead = NULL; 
	head = head->recursive_process(head,newhead);
	head->set_next(NULL);
	cout<<"after recursive reverse"<<endl;
	if(newhead != NULL)
		newhead->print_list(newhead);
	newhead->delete_list(newhead);
	newhead = NULL;

	Find_Kth find_kth;
	int k = find_kth.recursive_process(test,0,sizeof(test) / sizeof(int) -1,5);
	cout<<"find_kth can find "<<k<<endl;

	Quick_Sort test_quick_sort;
	test_quick_sort.process_sort(test,0,sizeof(test) / sizeof(int) -1);
	for(int i=0;i<sizeof(test) / sizeof(int);i++)
	{
		cout<<test[i]<<" ";
	}
	cout<<endl;

	Fibonacci fibonacci;
	cout<<"iterative fibo is "<<fibonacci.iterative_process(10)<<endl;
	cout<<"recursive fibo is "<<fibonacci.recursive_process(10)<<endl;

	Binary_Search binary_search;
	int test1 = binary_search.recursive_process(test,0,sizeof(test) / sizeof(int) -1,5);
	int test2 = binary_search.iterative_process(test,0,sizeof(test) / sizeof(int) -1,5);
	cout<<"binary_search can find "<<test1<<endl;
	cout<<"binary_search can find "<<test2<<endl;

	
 	system("pause");
	return 0;
}

