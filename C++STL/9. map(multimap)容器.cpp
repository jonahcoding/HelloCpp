#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
--------------------------------------------------
map：
	map的所有元素都是pair，同时拥有键值（第一元素）
	和实值（第二元素），并且会根据键值自动排序。无
	法通过迭代器改变map的值（改变排序规则，破坏map
	组织）。插入删除不会使原有迭代器失效。

疑问：
	如何指定按照实值排序。

multimap：
	特性、用法同map，区别在于允许键值重复。

map/multimap：
	底层实现是红黑树（RB-tree，平衡二叉树的一种）。

【常用API操作】
构造函数：
	map<T1, T2> mapTT;//map默认构造函数:
	map(const map &mp);//拷贝构造函数

赋值操作：
	map& operator=(const map &mp);//重载等号操作符
	swap(mp);//交换两个集合容器

大小操作：
	size();//返回容器中元素的数目
	empty();//判断容器是否为空

数据插入：
	map.insert(...); //往容器插入元素，返回pair<iterator,bool>
	map<int, string> mapStu;
	// 第一种 通过pair的方式插入对象
	mapStu.insert(pair<int, string>(3, "Judy"));
	// 第二种 通过pair的方式插入对象
	mapStu.inset(make_pair(-1, "Andi"));
	// 第三种 通过value_type的方式插入对象
	mapStu.insert(map<int, string>::value_type(1, "Kate"));
	// 第四种 通过数组的方式插入值
	mapStu[3] = "Jobs";
	mapStu[5] = "Jenny";

数据删除：
	clear();//删除所有元素
	erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	erase(keyElem);//删除容器中key为keyElem的对组。

查找：
	find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
	count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

函数对象：
	即调用操作符的类，其对象常称为函数对象它们是行
	为类似函数的对象。表现出函数的特征，即就是通过
	“对象名+(参数列表)”的方式使用一个类，其实质是
	对operator()操作符的重载。

--------------------------------------------------
*/

void test01()
{
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式  推荐
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种
	m[4] = 40;
	//cout << m[10] << endl; //如果利用第四种 使用未指定的key，生成一个key为为指定的值，value为0的数据插入到容器中

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

void test02()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	m.erase(3); //删除传入key值

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

void test03()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	map<int, int>::iterator ret = m.find(3);
	if (ret != m.end())
	{
		cout << "找到了 key为 " << ret->first << " value = " << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计  count 
	int num = m.count(4);
	cout << "key为4的对组个数为： " << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	map<int, int>::iterator pos = m.lower_bound(3);

	if (pos != m.end())
	{
		cout << "找到了lower_bound key: " << pos->first << " value: " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	pos = m.upper_bound(3);
	if (pos != m.end())
	{
		cout << "找到了upper_bound key: " << pos->first << " value: " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair<map<int, int>::iterator, map<int, int>::iterator>  ret2 = m.equal_range(3);
	if (ret2.first != m.end())
	{
		cout << "找到了equal_range中的 lower_bound的 key =  " << ret2.first->first << " value = " << ret2.first->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (ret2.second != m.end())
	{
		cout << "找到了equal_range中的 upper_bound的 key =  " << ret2.second->first << " value = " << ret2.second->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//函数对象：自定义按Key值从大到小排序
class CmpByKey {
public:
	bool operator()(int k1, int k2) const {
		return k1 > k2;
	}
};

void test04()
{
	/***Key值排序***/
	//自定义排序方式：key值从小到大排序
	map<int, int, CmpByKey> m;
	//默认按照key值从小到大排序
	//map<int, int> m;
	//设置key值从大到小排列
	//map<int, int, greater<string> > m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

int main()
{
	test01();
	test02();
	test03();
	test04();

	system("pause");
	return 0;
}
