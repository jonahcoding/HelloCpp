#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
	friend ostream& operator<<(ostream & cout, MyString & str);
	friend istream&  operator>>(istream & cin, MyString & str);
	
public:
	MyString(char  * str);
	MyString(const MyString & str);

	MyString& operator=(const char * str);
	MyString& operator=(const MyString & str);

	char& operator[](int index);

	MyString operator+(const char * str);
	MyString operator+(const MyString&str);

	bool operator==(const char *str);
	bool operator==(const MyString &str);

	~MyString();

private:
	char * pString; //维护在堆区开辟的字符数组
	int m_Size; //字符串长度 不统计\0
};