#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
--------------------------------------------------
queue（队列）：
	Queue是一种先进先出(FIFO)的数据结构。两个端口，
	一端新增元素，从另一端移除元素。
	不提供遍历，没有迭代器。

【常用API操作】
构造函数：
	queue<T> queT;//queue采用模板类实现。
	queue(const queue &que);//拷贝构造函数。

赋值操作：
	queue& operator=(const queue &que);//重载等号操作符

大小操作：
	empty();//判断队列是否为空
	size();//返回队列的大小

数据存取、插入、删除：
	push(elem);//往队尾添加元素
	pop();//从队头移除第一个元素
	back();//返回最后一个元素
	front();//返回第一个元素

--------------------------------------------------
*/

class Hero
{
public:
	string m_Name;
	int m_Age;

	Hero(string name, int age) :m_Name(name), m_Age(age) {}
};

void printHero(Hero &h)
{
	cout << "Name: " << h.m_Name << " , Age: " << h.m_Age << endl;
}

void test()
{
	queue<Hero> Q1;
	Hero h1("Teemo", 7);
	Hero h2("EZ", 19);
	Hero h3("ZOE", 9999);
	Hero h4("Yasuo", 27);
	Hero h5("Liqing", 5);

	Q1.push(h1);
	Q1.push(h2);
	Q1.push(h3);
	Q1.push(h4);
	Q1.push(h5);

	queue<Hero> Q2(Q1);
	queue<Hero> Q3 = Q2;

	cout << "Size: " << Q3.size() << endl;
	Q3.pop();
	cout << "移除首元素后Size: " << Q3.size() << endl;

	if (Q3.empty())
	{
		cout << "Q3为空。" << endl;
	}
	else
	{
		cout << "Q3不为空。" << endl;
	}

	printHero(Q3.front());
	printHero(Q3.back());
}

int main()
{
	test();

	system("pause");
	return 0;
}