#pragma once
class Fibonacci
{
public:
	Fibonacci(void);
	~Fibonacci(void);
	int iterative_process(int calculate);
	int recursive_process(int calculate);
private:
	void exchange(int& a,int& b);
};

