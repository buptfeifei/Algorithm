// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Quick_Sort.h"
#include "Fibonacci.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	int test[] = {1,3,4,9,10,12,17,5,8};
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

 	system("pause");
	return 0;
}

