#include "stdafx.h"
#include "Quick_Sort.h"


Quick_Sort::Quick_Sort(void)
{
}


Quick_Sort::~Quick_Sort(void)
{
}
void Quick_Sort::process_sort(int* array,int beg,int end)
{
	if(beg < end && array != NULL)
	{
		int k = partion(array,beg,end);
		process_sort(array,beg,k-1);
		process_sort(array,k+1,end);
	}

}
int Quick_Sort::partion(int* a,int beg,int end)
{
	int i = beg;
	for(int j = beg;j<end;j++)
	{
		if(a[j]<a[end])
		{
			exchange(a[i],a[j]);
			i++;
		}
	}
	exchange(a[i],a[end]);
	return i;
}

void Quick_Sort::exchange(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}