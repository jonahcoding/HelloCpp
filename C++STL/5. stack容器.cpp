#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stack>
#include <algorithm>

using namespace std;

/*
--------------------------------------------------
stack（栈）：
	stack是一种先进后出(FILO)的数据结构，只有一个出口。
	只允许从最顶端存取元素（stack不允许有遍历行为。）
	没有迭代器。

push:将元素推入栈。
pop:将元素推出栈。

【常用API操作】
构造函数：
	stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
	stack(const stack &stk);//拷贝构造函数

赋值操作：
	stack& operator=(const stack &stk);//重载等号操作符

大小操作：
	empty();//判断堆栈是否为空
	size();//返回堆栈的大小

数据存取：
	push(elem);//向栈顶添加元素
	pop();//从栈顶移除第一个元素
	top();//返回栈顶元素

--------------------------------------------------
*/

void test()
{
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);

	stack<int> s2(s1);
	stack<int> s3 = s2;

	cout << "Size: " << s3.size() << endl;
	cout << "Top: " << s3.top() << endl;
	s3.pop();

	cout << "移除栈顶元素后Size: " << s3.size() << endl;
	if (s3.empty())
	{
		cout << "栈s3为空。" << endl;
	}
	else
	{
		cout << "栈s3不为空。" << endl;
	}
}

int main()
{
	test();

	system("pause");
	return 0;
}
