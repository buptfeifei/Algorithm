#pragma once
class Quick_Sort
{
public:
	Quick_Sort(void);
	void process_sort(int* array,int beg,int end);
	~Quick_Sort(void);
private:
	int partion(int* array,int beg,int end);
	void exchange(int& a,int& b);
};

