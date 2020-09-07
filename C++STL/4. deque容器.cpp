#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include <deque>
#include <algorithm>

/*
--------------------------------------------------
vector与deque（双端队列）：
	Vector容器是单向开口的连续内存空间。
	deque则是一种双向开口的连续线性空间。

双向开口：
	可以在头尾两端分别做元素的插入和删除操作。
	vector容器也可以在头尾两端插入元素，
	但是在其头部操作效率奇差，无法被接受。

deque：
	deque是动态的。以分段连续空间组合而成，随时可
	以增加一段新的空间并链接起来。
	迭代器和运算复杂，以致排序操作为考虑高效率先完
	整复制到vector，排序完成再拷贝回deque。

deque原理：
	Deque是由一段一段的定量的连续空间构成，需要扩展
	时在头部或尾部串接配置好的新空间。deque的重点在
	于对分段连续内存空间的维护，并提供随机存取接口。
	（迭代器架构复杂的原因）deque采用一块map作为主控。
	map：一小块连续的内存空间，其中每一个元素(此处成
	为一个结点)都是一个指针，指向另一段连续性内存空间，
	称作缓冲区。缓冲区才是deque的存储空间的主体。


【常用API操作】

构造函数：
	deque<T> deqT;//默认构造形式
	deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	deque(n, elem);//构造函数将n个elem拷贝给本身。
	deque(const deque &deq);//拷贝构造函数。

赋值操作：
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	deque& operator=(const deque &deq); //重载等号操作符
	swap(deq);// 将deq与本身的元素互换

大小操作：
	deque.size();//返回容器中元素的个数
	deque.empty();//判断容器是否为空
	deque.resize(num);//重新指定容器的长度为num,长则默认值填充，短则删除。
	deque.resize(num, elem); //重新指定容器的长度为num,长则elem填充，短则删除。

双端插入与删除：
	push_back(elem);//在容器尾部添加一个数据
	push_front(elem);//在容器头部插入一个数据
	pop_back();//删除容器最后一个数据
	pop_front();//删除容器第一个数据

数据存取：
	at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
	operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
	front();//返回第一个数据。
	back();//返回最后一个数据

插入操作：
	insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

删除操作：
	clear();//移除容器的所有数据
	erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	erase(pos);//删除pos位置的数据，返回下一个数据的位置。

--------------------------------------------------
*/


void printDeque(const deque<int>& d)
{
	//iterator普通迭代器
	//reverse_iterator 反转迭代器
	//const_iterator  只读迭代器

	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	deque<int>d2;
	d2 = d;
	printDeque(d2);

	if (d2.empty())
	{
		cout << "d2为空" << endl;
	}
	else
	{
		cout << "d2不为空 size = " << d2.size() << endl;
	}
}

void test02()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//  300 200 100 10 20 30
	printDeque(d);

	d.pop_back(); //尾删
	d.pop_front(); //头删
	// 200 100 10 20
	printDeque(d);

	cout << "第一个元素为： " << d.front() << endl;
	cout << "最后一个元素为：" << d.back() << endl;
}


void test03()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//插入 insert
	d.insert(++d.begin(), 2, 1000);
	//  300 1000 1000  200 100 10 20 30
	printDeque(d);
	//删除erase
	//d.erase(++d.begin());
	//d.erase(++d.begin());
	//随机访问
	deque<int>::iterator it1 = d.begin();
	it1 = it1 + 1;
	deque<int>::iterator it2 = d.begin();
	it2 = it2 + 3;
	//删除元素（不包括it2）
	d.erase(it1, it2);
	printDeque(d);
	//清空
	d.clear();
	printDeque(d);
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//默认排序从小到大
	//sort(d.begin(), d.end());
	//从大到小排序（提供回调函数，底层实现详见源码）
	sort(d.begin(), d.end(), myCompare);
	printDeque(d);
}


int main() {
	test01();
	test02();
	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}