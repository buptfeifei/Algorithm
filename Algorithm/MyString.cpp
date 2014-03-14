#include "stdafx.h"
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(void)
	:string(NULL),size(0)
{
}
MyString::MyString(char* s,int i)
{
	if(init(s,i) != true)
	{
		cout<<"copy constructor error"<<endl;
	}
}
MyString::MyString(const MyString& s)
{
	if(init(s) != true)
	{
		cout<<"copy constructor error"<<endl;
	}
}
MyString::~MyString(void)
{
	if(this->string != NULL)
	{
		delete[] this->string;
		this->string = NULL;
		size = 0;
	}
}
MyString& MyString::operator = (const MyString& s)
{
	if(this != &s)
	{
		delete[] this->string;
		this->string = new char[s.size];
		if(this->string != NULL)
		{
			this->string = strcpy(s.string,this->string,s.size);
			this->size = s.size;
			return *this;
		}
	}
	return *this;
}
char& MyString::operator[](const int i)
{
	if(this->string!=NULL && i>=0 && i<size)
	{
		return this->string[i];
	}
}
char* MyString::strcpy(const char* str,char* dst,int i)
{
	if(str != NULL && dst != NULL)
	{
		const char* tmp1 = str;
		char* tmp2 = dst;
		for(int count = 0;count < i;count++)
		{
			*tmp2++ = *tmp1++;
		}
		return dst;
	}
	return NULL;
}
bool MyString::init(const MyString& s)
{
	if(s.string != NULL)
	{
		this->string = new char[s.size];
		if(this->string!=NULL)
		{
			this->string = strcpy(s.string,this->string,s.size);
			this->size = s.size;
			return true;
		}
	}
	return false;
}
bool MyString::init(char* s,int i)
{
	if(s != NULL)
	{
		this->string = new char[i];
		if(this->string!=NULL)
		{
			this->string = strcpy(s,this->string,i);
			this->size = i;
			return true;
		}
	}
	return false;
}
int* MyString::calculate_shift(const MyString& s)
{
	int* array_shift = NULL;
	array_shift = new int[s.size];
	if(array_shift != NULL)
	{
		array_shift[0] = -1;
		int k = -1;
		for(int i=1;i < s.size;i++)
		{
			while( k > -1 && s.string[i] != s.string[k+1]) k = array_shift[k];
			if(s.string[i] == s.string[k+1])
				k = k + 1;
			array_shift[i] = k;
		}
		return array_shift;
	}
	return NULL;
}
int* MyString::strstr(const MyString& s)
{
	if(this->string!=NULL && s.string != NULL)
	{
		int* shift = NULL;
		int shift_size = 0;
		int string_long = 0;
		char* string_l = NULL;
		char* string_s = NULL;
		if(this->size > s.size)
		{
			shift = calculate_shift(s);
			shift_size = s.size;
			string_long = this->size;
			string_l = this->string;
			string_s = s.string;
		}
		else
		{
			shift = calculate_shift(*this);
			shift_size = this->size;
			string_long = s.size;
			string_l = s.string;
			string_s = this->string;
		}
		for(int i = 0 ; i < shift_size;i++)
		{
			cout<<shift[i]<<endl;
		}
		int q = - 1;
		int* find_result = new int[string_long / shift_size];
		memset(find_result,-1,sizeof(int) * (string_long / shift_size));
		int count = 0;
		for(int j = 0;j < string_long;j++)
		{
			while(q > -1 && string_s[q+1]!=string_l[j])
				q = shift[q];
			if(string_s[q+1] == string_l[j]) q = q + 1;
			if(q == shift_size -1 )
			{
				cout<<"find string with shift "<<j-q<<endl;
				find_result[count++] = j - q;
				q = shift[q];
			}	
		}
		delete[] shift;

		if(count > 0)
			return find_result;
		else
		{
			delete[] find_result;
			return NULL;
		}
	}
	
	return NULL;
	
}
int* MyString::strtok(const char token )
{
	if(this->string!=NULL)
	{
		int* string_pos = new int[this->size];
		memset(string_pos,-1,sizeof(int) * this->size);
		const char* p = this->string;
		const char* q = this->string;
		int count = 0;
		while (*p!='\0')
		{
			if(*p != token)
			{
				string_pos[count++] = p - this->string;
				while(*q != token && *q !='\0')
					q++;
				string_pos[count++] = q - this->string;
				if(*q == '\0')
					return string_pos;
				else
				{
					p = q + 1;
					q = q + 1;
				}
			}
			else
			{
				p++;
				q++;
			}
		}
		return string_pos;
	}
	return NULL;
}
bool MyString::shift_n(int n)
{
	if(this->string != NULL && this->size > 0 && n > 0 && n < size)
	{
		reverse(this->string,this->string + n - 1);
		reverse(this->string + n ,this->string + size - 2); // without '\0' at the end of string
		reverse(this->string,this->string + size - 2);
		return true;
	}
	return false;
}
void MyString::reverse(char* beg,char* end)
{
	while(beg < end)
	{
		char tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}
void MyString::display(void)
{
	if(this->string != NULL && this->size > 0)
	{
		for(int i = 0;i < size - 1;i++)
			cout<<this->string[i];
		cout<<endl;
	}
}