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
	char& operator [] (const int i);
	int* strstr(const MyString& s);          //KMP
	inline int get_size() {return size;};
	int* strtok(const char token);          //split str
	bool shift_n(int bit);
	void display();
private:
	int* calculate_shift(const MyString& s);
	char* strcpy(const char* str,char* dst,int i);
	bool init(const MyString& s);
	bool init(char* s,int i);
	void reverse(char* beg,char* end);
	char* string;
	int size;
};

