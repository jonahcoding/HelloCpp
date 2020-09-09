#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/*
--------------------------------------------------
set：
	set的所有元素既是键值也是实值，并且会根据键值
	自动排序。无法通过迭代器改变set的值（改变排序
	规则，破坏set组织）。插入删除不会使原有迭代器
	失效。

multiset：
	特性、用法同set，区别在于允许键值重复。
	
set/multiset：
	底层实现是红黑树（RB-tree，平衡二叉树的一种）。

二叉搜索树：
	二叉树的节点按一定规则进行排序，使对齐元素访问
	更加高效。
二叉搜索树节点放置规则：
	任何节点的元素值一定大于其左子树中每一个节点的
	元素值，同时小于右子树中每一个节点的元素值。

平衡二叉树（AVL树）：
	一棵空树或左右两个子树的高度差的绝对值不超过1，
	并且左右两个子树都是一棵平衡二叉树。

【常用API操作】
构造函数：
	set<T> st;//set默认构造函数：
	mulitset<T> mst; //multiset默认构造函数: 
	set(const set &st);//拷贝构造函数

赋值操作：
	set& operator=(const set &st);//重载等号操作符
	swap(st);//交换两个集合容器

大小操作：
	size();//返回容器中元素的数目
	empty();//判断容器是否为空

数据插入、删除：
	insert(elem);//在容器中插入元素(键值+实值)。
	clear();//清除所有元素
	erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	erase(elem);//删除容器中值为elem的元素。

查找：
	find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
	count(key);//查找键key的元素个数
	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

【对组(pair)】
	对组(pair)将一对值组合成一个值，这一对值可以具有不同的数据类型，
	两个值可以分别用pair的两个公有属性first和second访问。
	
类模板：template <class T1, class T2> struct pair.

如何创建对组?
	//第一种方法创建一个对组
	pair<string, int> pair1(string("name"), 20);
	cout << pair1.first << endl; //访问pair第一个值
	cout << pair1.second << endl;//访问pair第二个值
	
	//第二种
	pair<string, int> pair2 = make_pair("name", 30);
	cout << pair2.first << endl;
	cout << pair2.second << endl;
	
	//pair=赋值
	pair<string, int> pair3 = pair2;
	cout << pair3.first << endl;
	cout << pair3.second << endl;

--------------------------------------------------
*/

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	printSet(s);

	if (s.empty())
	{
		cout << "set容器为空" << endl;
	}
	else
	{
		cout << "set容器不为空  大小为： " << s.size() << endl;
	}

	s.erase(30);
	printSet(s);
}

void test02()
{
	set<int>s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	//插入失败
	s.insert(40);

	set<int>::iterator pos = s.find(30);
	//查而未果时pos = s.end();
	if (pos != s.end())
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	int num = s.count(40);
	cout << "key为40的个数为：" << num << endl;
	//返回第一个key>=30元素的迭代器。（40）
	set<int>::iterator pos2 = s.lower_bound(30);

	if (pos2 != s.end())
	{
		cout << "lower_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//返回第一个key>30元素的迭代器。
	pos2 = s.upper_bound(30);
	if (pos2 != s.end())
	{
		cout << "upper_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair< set<int>::iterator, set<int>::iterator>  ret = s.equal_range(30);

	if (ret.first != s.end())
	{
		cout << "equal_range中的lower_bound的值为：" << *ret.first << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (ret.second != s.end())
	{
		cout << "equal_range中的upper_bound的值为：" << *ret.second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//pair创建
void test03()
{
	pair<string, int> p("Tom", 10);
	cout << "姓名： " << p.first <<  " 年龄： "<< p.second << endl;
	pair<string, int> p2 = make_pair("Jerry", 18);
	cout << "姓名： " << p2.first << " 年龄： " << p.second << endl;
}

void test04()
{
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	
	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}

	printSet(s);
	//multiset允许插入重复的key值
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	cout << "---------" << endl;
	for (multiset<int>::iterator it = ms.begin(); it != ms.end();it++)
	{
		cout << (*it) << endl;
	}
}

class myCompareInt
{
public:
	bool operator()(int v1 , int v2)
	{
		return v1 > v2;
	}
};

void test05()
{
	//set容器的排序规则要在插入之前指定
	set<int, myCompareInt >s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);

	//printSet(s);
	for (set<int, myCompareInt>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << endl;
	}
}

//对于自定义数据类型
class Hero
{
public:
	Hero(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
	string m_Name;
	int m_Age;
};

class myCompareHero
{
public:
	bool operator()( const Hero & p1 , const Hero & p2)
	{
		//按照年龄升序 从小到大
		return p1.m_Age < p2.m_Age;
	}
};

void test06()
{
	//利用仿函数指定出自定义数据类型的排序规则
	set<Hero,myCompareHero> s;

	Hero p1("aaa", 10);
	Hero p2("bbb", 40);
	Hero p3("ccc", 20);
	Hero p4("ddd", 30);
	Hero p5("eee", 50);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Hero, myCompareHero>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << (*it).m_Age << endl;
	}
}

int main(){
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	
	system("pause");
	return EXIT_SUCCESS;
}
