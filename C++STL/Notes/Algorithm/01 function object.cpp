#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
--------------------------------------------------
函数对象（仿函数）：
	重载函数操作符()的类（行为类似函数），类对象如
	函数调用。

分类（依据参数个数）：
	一元仿函数。
	二元仿函数。

特点：
	1.不定义构造/析构函数。
	2.可内联编译。
	3.通过模板函数，获得通用性。
	
用途：
	1.常见运算。
	2.以template参数的形式来指定算法所要采取的策略。
--------------------------------------------------
*/

class FUNC_Object_Printer
{
public:
	void operator()(int num)
	{
		cout <<num << endl;
	}
};

void test()
{
	FUNC_Object_Printer printer;
	printer(15);
}

int main()
{
	test();
	
	system("pause");
	return 0;
}