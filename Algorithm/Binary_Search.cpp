#include "stdafx.h"
#include "Binary_Search.h"

Binary_Search::Binary_Search(void)
{
}


Binary_Search::~Binary_Search(void)
{
}
int Binary_Search::recursive_process(const int* array,int beg,int end,const int value) const 
{
	if(array != NULL && beg <= end)
	{
		int k = (beg + end) / 2;
		if(value == array[k])
			return k;
		else
		{
			if(value < array[k])
				return recursive_process(array,beg,k-1,value);
			else
				return recursive_process(array,k+1,end,value);
		}
	}
	return -1;
}
int Binary_Search::iterative_process(const int* array,int beg,int end,const int value) const 
{
	if(array != NULL)
	{
		while(beg <= end)
		{
			int k = (beg + end) / 2;
			if(value == array[k])
				return k;
			else
			{
				if(value < array[k])
					end = k - 1;
				else
					beg = k + 1;
			}
		}
		return -1;
	}
	return -1;
}