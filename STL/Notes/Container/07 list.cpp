#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

/*
--------------------------------------------------
list（链表）：
	链表是一种物理存储单元上非连续、非顺序的存储结构，
	数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
	链表由一系列结点（链表中每一个元素称为结点）组成，
	结点可以在运行时动态生成。每个结点包括两个部分：
	一个是存储数据元素的数据域，另一个是存储下一个结点
	地址的指针域。
	每次插入或删除一个元素即配置或释放一个元素的空间。

list特点：
	1、动态内存分配，不会浪费空间或溢出。
	2、插入删除只需修改指针，不移动元素。
	3、操作灵活，但空间和时间耗费较大。

list的迭代器：
	list是双向的，其迭代器是双向迭代器（前移、后移）。
	插入、删除不会造成原有迭代器失效。

list的数据结构：
	循环的双向链表。

【常用API操作】
构造函数：
	list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
	list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	list(n,elem);//构造函数将n个elem拷贝给本身。
	list(const list &lst);//拷贝构造函数。

赋值操作：
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	list& operator=(const list &lst);//重载等号操作符
	swap(lst);//将lst与本身的元素互换。

大小操作：
	size();//返回容器中元素的个数
	empty();//判断容器是否为空
	resize(num);//重新指定容器的长度为num，
	若容器变长，则以默认值填充新位置。
	如果容器变短，则末尾超出容器长度的元素被删除。
	resize(num, elem);//重新指定容器的长度为num，

数据存取、插入、删除：
	front();//返回第一个元素。
	back();//返回最后一个元素。
	push_back(elem);//在容器尾部加入一个元素
	pop_back();//删除容器中最后一个元素
	push_front(elem);//在容器开头插入一个元素
	pop_front();//从容器开头移除第一个元素
	insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
	insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	clear();//移除容器的所有数据
	erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	erase(pos);//删除pos位置的数据，返回下一个数据的位置。
	remove(elem);//删除容器中所有与elem值匹配的元素。

反转与排序：
	reverse();//反转链表。
	sort(); //list排序。

--------------------------------------------------
*/

void printList(const list<int> & L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//正序遍历
	//for (list<int>::iterator it = L1.begin(); it != L1.end();it++)
	//{
	//	cout << *it << endl;
	//}
	//逆序遍历
	for (list<int>::reverse_iterator it = L1.rbegin(); it != L1.rend(); it++)
	{
		cout << *it << endl;
	}

	//list迭代器是不是支持随机访问 ,答案：不支持，是一个双向迭代器。
	list<int>::iterator itBegin = L1.begin();
	//itBegin = itBegin + 1;
}


void test02()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	L.pop_back(); //尾删
	L.pop_front(); //头删
				   // 200 100 10 20
	printList(L);

	//插入
	L.insert(L.begin(), 10000);
	// 10000 200 100 10 20
	printList(L);

	L.erase(L.begin());
	// 200 100 10 20 
	printList(L);

	//remove 删除容器中所有与elem值匹配的元素。
	L.push_back(100);
	L.push_back(100);
	L.remove(100);
	printList(L);
}

void test03()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	list<int>L2;
	L2.assign(10, 100);
	L.swap(L2);
	printList(L);
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	//反转
	L.reverse();
	printList(L);

	//排序  
	//如果容器的迭代器支持随机访问，可以使用系统提供的标志算法
	//不支持随机访问的迭代器的容器，内部会提供对应的算法接口
	//sort(L.begin(), L.end());
	/*L.sort(myCompare);
	printList(L);*/
}

class Hero
{
public:
	Hero(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	bool operator==(const Hero & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

bool myCompareHero(Hero &p1, Hero &p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height < p2.m_Height;
	}

	return  p1.m_Age > p2.m_Age;
}

void test05()
{
	list<Hero> L;
	Hero p1("Teemo", 7, 60);
	Hero p2("Yasuo", 27, 175);
	Hero p3("Ari", 19, 165);
	Hero p4("Liqing", 6, 175);
	Hero p5("ZOE", 9999, 120);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	//按照年龄进行降序   从大到下 , 如果年龄相等，按照身高进行升序 
	//对于自定义数据类型，必须要指定排序规则
	L.sort(myCompareHero);
	for (list<Hero>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
	}
	//删除盲僧
	L.remove(p4);

	cout << "删除盲僧后：" << endl;
	for (list<Hero>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
	}
}

int main() {

	test01();
	test02();
	test03();
	test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}