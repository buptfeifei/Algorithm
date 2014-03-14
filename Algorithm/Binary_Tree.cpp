#include "stdafx.h"
#include "Binary_Tree.h"
#include <iostream>
using namespace std;

#define STACK_DEFAULT_SIZE 20

array_queue::array_queue(int s)
			:size(s),
			array(NULL),
			beg(0),
			end(0)
{
	if(init_queue() != true)
	{
		cout<<"init queue error"<<endl;
	}
}

array_queue::~array_queue()
{
	if(array != NULL)
	{
		delete[] array;
		array = NULL;
		size = 0;
		beg = 0;
		end = 0;
	}
}
array_queue::array_queue()
{
}
bool array_queue::init_queue(void)
{
	array = new Binary_Tree* [size];
	if(array == NULL)
		return false;
	else
	{
		memset(array,0,sizeof(int) * size);
		return true;
	}

}
bool array_queue::enqueue(Binary_Tree* elem)
{
	if(elem != NULL)
	{
		if((end + 1) % size == beg)                //full
		{
			return false;
		}
		else
		{
			array[end] = elem;
			end = (end + 1) % size;
			return true;
		}
	}
	return false;
}
Binary_Tree* array_queue::dequeue(void)
{
	if(beg == end)
		return NULL;
	else
	{
		Binary_Tree* tmp = array[beg];
		beg = (beg + 1) % size;
		return tmp;
	}
}
array_stack::array_stack(void)
{

}
array_stack::array_stack(int s)
	:size(s),array(NULL),top(0)
{
	if(init_stack() != true)
	{
		cout<<"init stack error"<<endl;
	}
}
bool array_stack::init_stack(void)
{
	array = new Binary_Tree* [size];
	if(array == NULL)
		return false;
	else
	{
		memset(array,0,sizeof(int) * size);
		return true;
	}
}
Binary_Tree* array_stack::pop(void)
{
	if(top > 0)
	{
		return array[--top];
	}
	else
	{
		cout<<"stack pop error"<<endl;
		return NULL;
	}
}
bool array_stack::push(Binary_Tree* elem)
{
	if(elem != NULL && top < size)
	{
		array[top++] = elem;
		return true;
	}
	else
	{
		cout<<"stack push error"<<endl;
		return false;
	}
}
array_stack::~array_stack(void)
{
	if(array!=NULL)
	{
		delete[] array;
		array = NULL;
		size = 0;
		top = 0;
	}
}
Binary_Tree::Binary_Tree(void)
{
}


Binary_Tree::~Binary_Tree(void)
{
	element = 0;
	lchild = NULL;
	rchild = NULL;
	parent = NULL;
}
Binary_Tree::Binary_Tree(int value)
			:element(value),
			lchild(NULL),
			rchild(NULL),
			parent(NULL)
{

}
Binary_Tree* Binary_Tree::gen_tree(int* array,int size)
{
	if(array != NULL && size > 0)
	{
		int i = 0;
		Binary_Tree* root = new Binary_Tree(array[i++]);
		array_queue myqueue(size / 2 + 1);
		if(myqueue.enqueue(root) == true)
		{
			while(i<size)
			{
				Binary_Tree* tmp = myqueue.dequeue();
				if(tmp != NULL)
				{
					tmp->lchild = new Binary_Tree(array[i++]);
					if(myqueue.enqueue(tmp->lchild)==false)
						break;
					if(i<size)
					{
						tmp->rchild = new Binary_Tree(array[i++]);
						if(myqueue.enqueue(tmp->rchild)==false)
						break;
					}
				}
			}
		}
		return root;
	}
	return NULL;
}
void Binary_Tree::print_tree(Binary_Tree* root)
{
	if(root != NULL)
	{
		print_tree(root->lchild);
		cout<<"node is "<<root->element<<endl;
		if(root->parent != NULL)
			cout<<"node parent is "<<root->parent->element<<endl;
		else
			cout<<"root no parent "<<endl;
		print_tree(root->rchild);
	}
}
void Binary_Tree::delete_tree(Binary_Tree* root)
{
	if(root != NULL)
	{
		print_tree(root->lchild);
		print_tree(root->rchild);
		delete root;
	}
}
void Binary_Tree::find_parent(Binary_Tree* root)
{
	if(root != NULL)
	{
		if(root->lchild != NULL)
		{
			root->lchild->parent = root;
			find_parent(root->lchild);
		}
		if(root->rchild != NULL)
		{
			root->rchild->parent = root;
			find_parent(root->rchild);
		}
	}
}
Binary_Tree* Binary_Tree::find_next_node(Binary_Tree* node)
{
	if(node != NULL)
	{
		Binary_Tree* tmp = NULL;
		if(node->rchild != NULL)
		{
			tmp = node->rchild;
			while (tmp->lchild != NULL)
				tmp = tmp->lchild;
		}
		else
		{
			tmp = node->parent;
			Binary_Tree* tmp2 = node;
			while (tmp!= NULL)
			{
				if(tmp->lchild == tmp2)
					return tmp;
				tmp2 = tmp;
				tmp = tmp->parent;
			}
		}
		return tmp;
	}
	return NULL;
}
Binary_Tree* Binary_Tree::find_prev_node(Binary_Tree* node)
{
	if(node !=NULL)
	{
		Binary_Tree* tmp = NULL;
		if(node->lchild != NULL)
		{
			tmp = node->lchild;
			while(tmp->rchild != NULL)
				tmp = tmp->rchild;
		}
		else
		{
			tmp = node->parent;
			Binary_Tree* tmp2 = node;
			while(tmp!=NULL)
			{
				if(tmp->rchild == tmp2)
					return tmp;
				tmp2 = tmp;
				tmp = tmp->parent;
			}
		}
		return tmp;
	}
	return NULL;
}
int Binary_Tree::find_LCA(Binary_Tree* root,const int a,const int b)   //this function has a bug , if a is b child , it will not work!
{
	if(root!=NULL)
	{
		if((a < root->element && b > root->element) || (b < root->element && a > root->element) )
			return root->element;
		else
		{
			if(a < root->element && b < root->element)
				return find_LCA(root->lchild,a,b);
			else
				return find_LCA(root->rchild,a,b);
		}
	}
	cout<<"int find_LCA root is NULL"<<endl;
	return 0;
}
Binary_Tree* Binary_Tree::find_LCA(Binary_Tree* root,Binary_Tree* a,Binary_Tree* b)
{
	if(root != NULL && a!= NULL && b!= NULL)
	{
		array_stack stack(STACK_DEFAULT_SIZE);
		
		Binary_Tree* tmp = root;
		Binary_Tree* next = NULL;
		
		while(tmp != NULL || stack.get_size() != 0)
		{
			if(tmp != NULL) 
			{
				stack.push(tmp);
				tmp = tmp ->lchild;
			}
			else
			{
				tmp = stack.pop();
				if(tmp == a || tmp == b)
				{
					if(tmp == a )
						next = b;
					else
						next = a;

					bool find_flag = false;
					while(stack.get_size() != 0)
					{
						tmp = stack.pop();
						find_node(tmp->rchild,next,find_flag);
						if(find_flag) return tmp;
					}
					return NULL;
				}
				else
				{
					tmp = tmp->rchild;
				}
			}
			
			
		}
		return NULL;
	}
	return NULL;
}
 void Binary_Tree::find_node(Binary_Tree* root,Binary_Tree* node,bool& flag)
{
	if(root != NULL && node != NULL && flag != true)
	{
		find_node(root->lchild,node,flag);
		if(root == node)
		{
			flag = true;
		}
		find_node(root->rchild,node,flag);
	}
}
 Binary_Tree* Binary_Tree::find_pointer(Binary_Tree* root,const int value)
 {
	 if(root != NULL)
	 {
		 if(value == root->element)
			 return root;
		 else
		 {
			 if(value < root->element)
			 {
				 return find_pointer(root->lchild,value);
			 }
			 else
			 {
				 return find_pointer(root->rchild,value);
			 }
		 }
	 }
 }