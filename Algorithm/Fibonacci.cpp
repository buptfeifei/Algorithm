#include "stdafx.h"
#include "Fibonacci.h"


Fibonacci::Fibonacci(void)
{
}


Fibonacci::~Fibonacci(void)
{
}
int Fibonacci::iterative_process(int calculate)
{
	int i = 1;
	int j = 1;
	for(int k=2;k<=calculate;k++)
	{
		i = i + j;
		exchange(i,j);
	}
	return j;
}
int Fibonacci::recursive_process(int calculate)
{
	if(calculate < 2)
		return 1;
	else
		return recursive_process(calculate - 1) + recursive_process(calculate - 2);
}
void Fibonacci::exchange(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}