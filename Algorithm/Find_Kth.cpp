#include "stdafx.h"
#include "Find_Kth.h"
#include <iostream>
using namespace std;

Find_Kth::Find_Kth(void)
{
}


Find_Kth::~Find_Kth(void)
{
}
int Find_Kth::recursive_process(int* array,int beg,int end,const int n) 
{
	if(array != NULL && beg <= end)
	{
		int k = partion(array,beg,end);
		if(n == k )
			return array[k];
		else
		{
			if(n < k)
				return recursive_process(array,beg,k-1,n);
			else
				return recursive_process(array,k+1,end,n);    //we do not calculate the offsite in sub-array.
		}
	}
	return -1;
}
int Find_Kth::partion(int* array,int beg,int end)
{
	int i = beg;
	for(int j = beg;j<end;j++)
	{
		if(array[j] < array[end])
		{
			exchange(array[i],array[j]);
			i++;
		}
	}
	exchange(array[i],array[end]);
	return i;
}
void Find_Kth::exchange(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}