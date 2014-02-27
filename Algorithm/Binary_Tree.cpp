#include "stdafx.h"
#include "Binary_Tree.h"
#include <iostream>
using namespace std;

array_queue::array_queue(int s)
			:size(s),
			array(NULL),
			beg(0),
			end(0)
{
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
	if(array != NULL)
	{
		delete[] array;
		array = NULL;
	}
	array = new Binary_Tree* [size];
	if(array == NULL)
		return false;
	else
		return true;

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
		if(myqueue.init_queue() == true && myqueue.enqueue(root) == true)
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