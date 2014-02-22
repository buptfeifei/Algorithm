#pragma once
class Binary_Search
{
public:
	Binary_Search(void);
	~Binary_Search(void);
	int iterative_process(const int* array,int beg,int end,const int value) const;
	int recursive_process(const int* array,int beg,int end,const int value) const;
}; 

