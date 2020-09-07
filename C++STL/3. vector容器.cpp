#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include <vector>
#include <list>

/*
--------------------------------------------------
数组与vector：
	Array是静态空间，一经配置无法改变，只能配置新空
	间，迁移数据，释放旧空间（时间成本高，效率低）。

	vector是动态空间，自动扩充空间以容纳新元素。

vector：
	维护线性空间，普通指针作为其迭代器。
	支持随机存取（随机访问迭代器）。

vector的数据结构：
	1、线性连续空间。
	2、以迭代器_Myfirst和_Mylast分别指向配置得来的
		连续空间中目前已被使用的范围。
	3、并以迭代器_Myend指向整块连续内存空间的尾端。
	4、vector容量永远大于或等于其大小，已被扩展。
注：
	动态增加大小（非接续）：超出容量后，空间重新配
	置，原vector的迭代器将失效。

【常用API操作】
构造函数：
	vector<T> v; //采用模板实现类实现，默认构造函数
	vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
	vector(n, elem);//构造函数将n个elem拷贝给本身。
	vector(const vector &vec);//拷贝构造函数。
	//例：
		int arr[] = {2,3,4,1,9};
		vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

赋值：
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	vector& operator=(const vector  &vec);//重载等号操作符
	swap(vec);// 将vec与本身的元素互换。

大小：
	size();//返回容器中元素的个数
	empty();//判断容器是否为空
	resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
	capacity();//容器的容量
	reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

数据存取：
	at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
	operator[];//返回索引idx所指的数据，越界时，运行直接报错
	front();//返回容器中第一个数据元素
	back();//返回容器中最后一个数据元素

插入与删除：
	insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
	push_back(ele); //尾部插入元素ele
	pop_back();//删除最后一个元素
	erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
	erase(const_iterator pos);//删除迭代器指向的元素
	clear();//删除容器中所有元素

--------------------------------------------------
*/

void test01()
{
	vector<int> v;
	for (int i = 0; i < 50; i++) {
		v.push_back(i);
		// v.capacity()容器的容量
		//此处验证动态分配（每次容量增加的规律是什么？）
		cout << v.capacity() << endl;
	}
}

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(v1.begin(), v1.end());

	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.end());

	printVector(v3);


	vector<int> v4(10, 100);
	printVector(v4);

	cout << "v3和v4互换后：" << endl;
	v3.swap(v4);

	printVector(v3);
	printVector(v4);
}


void test03()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空 ，大小为： " << v1.size() << endl;
	}

	//第二个参数代表默认填充值
	v1.resize(10, 100);
	printVector(v1);

	v1.resize(3);
	printVector(v1);

	cout << "v1的front = " << v1.front() << endl;
	cout << "v1的back  = " << v1.back() << endl;
}

void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	v.insert(v.begin(), 100);
	printVector(v);

	v.push_back(1000);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end()); 等价于  v.clear();
	v.clear();
	printVector(v);
}

//案例1 巧用swap收缩内存
void test05()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	v.resize(3);
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	vector<int>(v).swap(v);
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;
}

//案例2 巧用reserve预留空间
void test06()
{
	vector<int>v;
	v.reserve(100000);
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num = " << num << endl;
}

void test07()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//逆序遍历
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}
	//vector的迭代器是随机访问迭代器，支持跳跃访问
	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 3;

	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	list<int>::iterator itBegin2 = L.begin();
	//itBegin2 = itBegin2 + 1;//list容器的迭代器是不支持随机访问的
	cout << *itBegin << endl;
}


int main() {

	test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();

	system("pause");
	return EXIT_SUCCESS;
}
