#pragma once
class Reverse_List
{
public:
	Reverse_List(int value);
	~Reverse_List(void);
	static Reverse_List* gen_list(int* array,int size);
	inline void set_next(Reverse_List* node){next = node;};
	void print_list(Reverse_List* head);
	Reverse_List* iterative_process(Reverse_List* head);
	Reverse_List* recursive_process(Reverse_List* head,Reverse_List*& newhead);
	void delete_list(Reverse_List* head);
private:
	Reverse_List(void);
	int element;
	Reverse_List* next;
	
};

