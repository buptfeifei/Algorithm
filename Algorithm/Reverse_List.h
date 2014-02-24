#pragma once
class Reverse_List
{
public:
	Reverse_List(int value = 0);
	~Reverse_List(void);
	static Reverse_List* gen_list(int* array,int size);
	inline Reverse_List* get_next(void) {return next;};
	inline void set_next(Reverse_List* node) {next = node;}; 
	inline int get_element(void) {return element;};
	void print_list(Reverse_List* head);
	Reverse_List* iterative_process(Reverse_List* head);
	Reverse_List* recursive_process(Reverse_List* head,Reverse_List*& newhead);
private:
	Reverse_List(void);
	int element;
	Reverse_List* next;
	
};

