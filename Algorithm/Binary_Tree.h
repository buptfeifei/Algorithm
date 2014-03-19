#pragma once
class Binary_Tree;
class array_queue
{
public:
	array_queue(int s);
	~array_queue(void);
	bool enqueue(Binary_Tree* elem);
	Binary_Tree* dequeue(void);
private:
	array_queue(void);
	bool init_queue(void);
	Binary_Tree** array;
	int size;
	int beg;
	int end;
};
class array_stack
{
public:
	array_stack(int s);
	~array_stack(void);
	Binary_Tree* pop(void);
	bool push(Binary_Tree* elem);
	int get_size(void){return top;};
	void print_stack(void);
private:
	array_stack(void);
	bool init_stack(void);
	Binary_Tree** array;
	int size;
	int top;
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
	int find_LCA(Binary_Tree* root,const int a,const int b);
	Binary_Tree* find_LCA(Binary_Tree* root,Binary_Tree* a,Binary_Tree* b);
	Binary_Tree* find_pointer(Binary_Tree* root,const int value);
	void find_path_sum(Binary_Tree* root, int sum);
	int find_max_node(Binary_Tree* root);
private:
	void find_node(Binary_Tree* root,Binary_Tree* node,bool& flag);
	void find_path_sum(Binary_Tree* root, int sum, array_stack& mystack);
	int find_max_node(Binary_Tree* root,int& max);
	Binary_Tree(void);
	int element;
	Binary_Tree* lchild;
	Binary_Tree* rchild;
	Binary_Tree* parent;
};


