#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>

using namespace std;

/*
--------------------------------------------------
内建函数对象：
	STL内建函数对象。

分类：
	算术类函数对象。
	关系运算符函数对象。
	逻辑运算类仿函数。
	其它无名临时对象...
	
头文件：
	#include <functional>
	
算数类函数对象（negate为一元运算）：
	template<class T> T plus<T>//加法仿函数
	template<class T> T minus<T>//减法仿函数
	template<class T> T multiplies<T>//乘法仿函数
	template<class T> T divides<T>//除法仿函数
	template<class T> T modulus<T>//取模仿函数
	template<class T> T negate<T>//取反仿函数

算数类函数对象：
	template<class T> bool equal_to<T>//等于
	template<class T> bool not_equal_to<T>//不等于
	template<class T> bool greater<T>//大于
	template<class T> bool greater_equal<T>//大于等于
	template<class T> bool less<T>//小于
	template<class T> bool less_equal<T>//小于等于

逻辑运算类运算函数（not为一元运算）：
	template<class T> bool logical_and<T>//逻辑与
	template<class T> bool logical_or<T>//逻辑或
	template<class T> bool logical_not<T>//逻辑非

--------------------------------------------------
*/

//取反仿函数
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//加法仿函数
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

//大于仿函数
void test03()
{
	vector<int> v;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++){
		v.push_back(rand() % 100);
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "----------------------------" << endl;
	cout << "通过greater 使其从大到小排序" << endl;
	cout << "----------------------------" << endl;
	
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}
