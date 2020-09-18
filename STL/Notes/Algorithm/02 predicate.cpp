#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/*
--------------------------------------------------
谓词：
	普通函数或重载的operator()返回值是bool类型的函
	数对象(仿函数)，可作为判断式。

分类（依据参数个数）：
	一元谓词。
	二元谓词。

--------------------------------------------------
*/

//一元谓词
class GreaterThanSeven
{
public:
	bool operator()(int num)
	{
		return num > 7;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 30; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThanSeven());
	if (it == v.end())
	{
		cout << "Not Found!" << endl;
	}
	else
	{
		cout << "Found it!" << *it << endl;
	}
}

//二元谓词（指定算法策略）
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		//从大到小
		return num1 > num2;
	}
};

void test02()
{
	srand((unsigned)time(NULL));
	vector<int> v;
	for (int i = 0; i<50; ++i)
	{
		//取得[0,num)间的整数随机值。
		//int ran_num = rand() % num;
		//取得[a,b)间的整数随机值。
		//int ran_num = rand() % (b-a)+ a;
		int ran_num = rand() % (101 - 1) + 1;
		//cout << ran_num << " ";
		v.push_back(ran_num);
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
 	cout << "----------------------------" << endl;
	cout << "通过函数对象使其从大到小排序" << endl;
	cout << "----------------------------" << endl;
	sort(v.begin(), v.end(), MyCompare());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
