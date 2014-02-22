// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Quick_Sort.h"
#include "Fibonacci.h"
#include "Binary_Search.h"
#include "Find_Kth.h"

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	int test[] = {1,3,4,9,10,12,17,5,8};
	
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

