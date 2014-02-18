#include "stdafx.h"
#include "Binary_Search.h"


Binary_Search::Binary_Search(void)
{
}


Binary_Search::~Binary_Search(void)
{
}
int Binary_Search::process_find(const int* array,int beg,int end,const int value) const 
{
	if(array != NULL && beg <= end)
	{
		int k = (beg + end) / 2;
		if(value == array[k])
			return k;
		else
		{
			if(value < array[k])
				process_find(array,beg,k-1,value);
			else
				process_find(array,k+1,end,value);
		}
	}
	return -1;
}