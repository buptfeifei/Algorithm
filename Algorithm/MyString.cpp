#include "stdafx.h"
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(void)
	:sting(NULL),size(0)
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
	if(this->sting != NULL)
	{
		delete[] this->sting;
		this->sting = NULL;
		size = 0;
	}
}
MyString& MyString::operator = (const MyString& s)
{
	if(this != &s)
	{
		delete[] this->sting;
		this->sting = new char[s.size];
		if(this->sting != NULL)
		{
			this->sting = strcpy(s.sting,this->sting);
			this->size = s.size;
			return *this;
		}
	}
	return *this;
}
char* MyString::strcpy(const char* str,char* dst)
{
	if(str != NULL && dst != NULL)
	{
		const char* tmp1 = str;
		char* tmp2 = dst;
		while(*tmp1 != '\0')
			*tmp2++ = *tmp1++;
		return dst;
	}
	return NULL;
}
bool MyString::init(const MyString& s)
{
	if(s.sting != NULL)
	{
		this->sting = new char[s.size];
		if(this->sting!=NULL)
		{
			this->sting = strcpy(s.sting,this->sting);
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
		this->sting = new char[i];
		if(this->sting!=NULL)
		{
			this->sting = strcpy(s,this->sting);
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
			while( k > -1 && s.sting[i] != s.sting[k+1]) k = array_shift[k];
			if(s.sting[i] == s.sting[k+1])
				k = k + 1;
			array_shift[i] = k;
		}
		return array_shift;
	}
	return NULL;
}
int* MyString::strstr(const MyString& s)
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
		string_l = this->sting;
		string_s = s.sting;
	}
	else
	{
		shift = calculate_shift(*this);
		shift_size = this->size;
		string_long = s.size;
		string_l = s.sting;
		string_s = this->sting;
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