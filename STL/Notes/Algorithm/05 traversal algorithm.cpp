#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
--------------------------------------------------
【常用遍历算法】

for_each遍历算法：遍历容器元素
@param beg 开始迭代器
@param end 结束迭代器
@param _callback  函数回调或者函数对象
@return 函数对象
for_each(iterator beg, iterator end, _callback);


transform算法：将指定容器区间元素搬运到另一容器中
注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
@param beg1 源容器开始迭代器
@param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器
@param _cakkback 回调函数或者函数对象
@return 返回目标容器迭代器
transform(iterator beg1, iterator end1, iterator beg2, _callbakc);

--------------------------------------------------
*/

class MyPrint1
{
public:
	void operator()(int val)
	{
		cout << val << " ";
		m_Count++;
	}
	int m_Count = 0;
};

//for_each遍历：
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	MyPrint1 print = for_each(v.begin(), v.end(), MyPrint1());
	cout << "\n打印次数：\t" << print.m_Count << endl;
}

//for_each绑定参数遍历输出：
class MyPrint2 :public binary_function<int, int, void>
{
public:
	void operator()(int val, int start) const
	{
		cout << val << endl;
	}
};

void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(MyPrint2(), 1000));
}

class MyTransform
{
public:
	int operator()(int val)
	{
		return val+1000;
	}
};

void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	
	vector<int> v2;
	v2.resize(v1.size());
	transform(v2.begin(), v2.end(), MyTransform());
	for_each(v2.begin(), v2.end(), [](int val){cout << val << endl;});
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}
