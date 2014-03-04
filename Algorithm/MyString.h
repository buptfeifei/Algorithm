#pragma once
class MyString
{
public:
	MyString(char* s,int i);
	MyString(void);
	~MyString(void);
	MyString(const MyString& s );
	MyString& operator = (const MyString& s);
	bool operator == (const MyString& s) const;
	int* strstr(const MyString& s);          //KMP
	inline int get_size() {return size;};
private:
	int* calculate_shift(const MyString& s);
	char* strcpy(const char* str,char* dst);
	bool init(const MyString& s);
	bool init(char* s,int i);
	char* sting;
	int size;
};

