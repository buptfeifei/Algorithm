#pragma once
class Binary_Tree;
class array_queue
{
public:
	array_queue(int s);
	~array_queue();
	bool init_queue(void);
	bool enqueue(Binary_Tree* elem);
	Binary_Tree* dequeue(void);
private:
	array_queue();
	Binary_Tree** array;
	int size;
	int beg;
	int end;
};
class Binary_Tree
{
public:
	Binary_Tree(int value);
	~Binary_Tree(void);
	static Binary_Tree* gen_tree(int* array,int size);
	void print_tree(Binary_Tree* root);
	void find_parent(Binary_Tree* root);
	Binary_Tree* find_next_node(Binary_Tree* node);
	Binary_Tree* find_prev_node(Binary_Tree* node);
	void delete_tree(Binary_Tree* root);
	inline int get_element(void) {return element;};
	inline void set_parent(Binary_Tree* node) { parent = node;};
private:
	Binary_Tree(void);
	int element;
	Binary_Tree* lchild;
	Binary_Tree* rchild;
	Binary_Tree* parent;
};

