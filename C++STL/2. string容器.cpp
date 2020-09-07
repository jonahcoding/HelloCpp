#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<vector>

using namespace std;

/*
--------------------------------------------------
string与c-type字符串：
1.string类，char*指针。（string封装了char*）。
2.string成员方法：查找、拷贝、删除、替换、插入。
3.string无需考虑内存释放和越界，由String类维护。

构造函数：
string();//创建一个空字符串。
string(const string& str);//使用string对象初始化。
string(const char* s);//使用字符串s初始化。
string(int n, char c);//使用n个字符c初始化。

基本赋值：
string& operator=(const char* s);//char*类型字符串s
string& operator=(const string &s);//字符串s
string& operator=(char c);//字符c
string& assign(const char *s);//char*类型字符串s
string& assign(const char *s, int n);//char*类型字符串s的前n个字符
string& assign(const string &s);//字符串s
string& assign(int n, char c);//n个字符c
string& assign(const string &s, int start, int n);//字符串s的子串

获取字符：
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符

拼接字符串：
string& operator+=(const string& str);//重载+=操作符(string)
string& operator+=(const char* str);//重载+=操作符(char*)
string& operator+=(const char c);//重载+=操作符(char c)
string& append(const char *s);//char*类型字符串s
string& append(const char *s, int n);//char*类型字符串s的前n个字符
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//字符串s的子串
string& append(int n, char c);//n个字符c

查找与替换：
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s


比较字符串：
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
int compare(const string &s) const;//与字符串s比较。
int compare(const char *s) const;//与字符串s比较。

子串：
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

插入和删除：
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符

string 与 c-style字符串转换：
string 转 char*：
string str = "itcast";
const char* cstr = str.c_str();
char* 转 string ：
char* s = "itcast";
string str(s);

--------------------------------------------------
*/

//[]和at区别，[]访问越界,直接挂掉；at访问越界，抛出out_of_range异常。


//构造
void test01()
{
	string str1;
	string str2(str1);
	string str3 = "abc";
	string str4(10, 'a');

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
}

//赋值
void test02()
{
	string  str1;
	str1 = "abc";
	str1.assign("abcde", 3);
	cout << str1 << endl;

	string str2;
	str2.assign(str1);
	cout << str2 << endl;

	str2.assign(str1, 0, 2);
	cout << str2 << endl;
}

//获取字符
void test03()
{
	string str = "hello world";

	for (int i = 0; i < str.size();i++)
	{
		//cout << str[i] << endl;
		cout << str.at(i);
	}
	cout << endl;

	//[]和at区别，[]访问越界 直接挂掉 ， at访问越界  抛出out_of_range异常

	try
	{
		//cout << str[100] << endl;
		cout << str.at(100) << endl;
	}
	catch (out_of_range & e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "异常捕获" << endl;
	}
}

//拼接、查找、替换
void test04()
{
	//拼接
	//string str1 = "我";
	//string str2 = "爱北京";
	//str1 += str2;
	//cout << str1 << endl;
	//str1.append("天安门");
	//cout << str1 << endl;

	//查找
	string str = "abcdefgde";
	int pos = str.find("de");
	//rfind 是从右往左查找
	if (pos == -1)
	{
		cout << "未找到目标字符串" << endl;
	}
	else
	{
		cout << "已找到目标字符串，位置为： " << pos << endl;
	}

	//替换
	//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	str.replace(1, 3, "11111");
	//a11111efgde（bcd替换为11111）
	cout << str << endl;
}

//比较
void test05()
{
	string str1 = "abcde";
	string str2 = "abcdef";

	if (str1.compare(str2) == 0)
	{
		cout << "str1 == str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}

//子串
void test06()
{
	string email = "jonahcoding@sina.com";
	int pos = email.find("@"); // 11
	string userName = email.substr(0, pos);
	cout << userName << endl;
}

//解析字符串
void test07()
{
	string str = "the.world.is.massed.up";
	vector<string> v; //将单词截取到 vector容器中
	int start = 0;
	int pos = -1;

	while (true)
	{
		pos = str.find(".", start);
		if (pos == -1)
		{
			//无分割符号'.'
			string tempStr = str.substr(start, str.size() - start);
			v.push_back(tempStr);
			break;
		}
		string tempStr = str.substr(start, pos - start);
		v.push_back(tempStr);
		start = pos + 1;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

//插入、删除
void test08()
{
	string str = "hello";
	str.insert(1, "111");
	//h111ello 
	cout << str << endl;
	//删除 
	str.erase(1, 3);
	cout << str << endl;
}

//string与c-type字符串转换
void test09()
{
	//string 转 char*
	string str1 = "memory";
	const char* cstr = str1.c_str();
	cout << cstr << endl;
	//char* 转 string 
	char* s = "missing";
	string str2(s);
	cout << str2 << endl;
}


int main() {

	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();

	system("pause");
	return EXIT_SUCCESS;
}