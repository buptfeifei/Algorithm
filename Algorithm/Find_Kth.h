#pragma once
class Find_Kth
{
public:
	Find_Kth(void);
	~Find_Kth(void);
	int recursive_process(int* array,int beg,int end,const int n);
private:
	int partion(int* array,int beg,int end);
	void exchange(int& a,int& b);
};

