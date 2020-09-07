#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
--------------------------------------------------
STL(Standard Template Library,标准模板库)：
	惠普实验室开发的一系列软件的统称。
	
STL广义分类: 
	1.容器(container) 
	2.算法(algorithm) 
	3.迭代器(iterator)
	容器和算法之间通过迭代器进行无缝连接。

STL六组件：
	1.容器：各种数据结构，如vector、list、deque、set、map。
	2.算法：各种常用的算法，如sort、find、copy、for_each。
	3.迭代器：将指针相关操作（operator）予以重载。
	4.仿函数：行为类似函数，作为算法的某种策略。
	5.适配器（配接器）：修饰容器或者仿函数或迭代器接口。
	6.空间配置器：负责空间的配置与管理。
　　
STL组件交互关系：
	容器通过空间配置器取得数据存储空间。
	算法通过迭代器存储容器中的内容。
	仿函数可以协助算法完成不同的策略的变化。
	适配器可以修饰仿函数。
	
STL特点：
	1.高可重用性（模板实现）。
	2.高效性（例如map通过红黑树实现）。
	3.高移植性。
	
《STL三大组件》

【容器】
常用的数据结构：
	数组(array),链表(list),tree(树)，栈(stack),队列
	(queue),集合(set),映射表(map)。根据数据在容器中
	的排列特性，这些数据分为序列式容器和关联式容器两种。
分类：
	序列式容器：
		线性，强调值的排序。
	关联式容器：
		非线性，二叉树结构。
		
【算法】
分类：
	质变算法：
		运算过程中会更改区间内的元素的内容。
		例如拷贝，替换，删除等等。
	非质变算法：
		指运算过程中不会更改区间内的元素内容。
		例如查找、计数、遍历、寻找极值等等

【迭代器】
	依序寻访某个容器所含的各个元素，
	且无需暴露该容器的内部表示方式。
	
	输入迭代器；
	输出迭代器：
	前向迭代期：
	双向迭代器：
	随机访问迭代器：

--------------------------------------------------
*/

//基本数据类型
void test01(){
	//STL标准容器之一 ：动态数组
	vector<int> v; 
	//vector容器插入数据
	v.push_back(1); 
	v.push_back(5);
	v.push_back(3);
	v.push_back(7);
	//迭代器
	//begin()返回指向第一个元素的迭代器。
	vector<int>::iterator pStart = v.begin(); 
	//end()方法返回指向最后一个元素下一个位置的迭代器
	vector<int>::iterator pEnd = v.end(); 
	//通过迭代器遍历
	while (pStart != pEnd){
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;
}

//自定义类型
class Teacher
{
public:
	Teacher(int age) :age(age){};
	~Teacher(){};
public:
	int age;
};
void test02(){
	vector<Teacher> v; 
	Teacher t1(10), t2(20), t3(30);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	vector<Teacher>::iterator pStart = v.begin();
	vector<Teacher>::iterator pEnd = v.end();
	//通过迭代器遍历
	while (pStart != pEnd){
		cout << pStart->age << " ";
		pStart++;
	}
	cout << endl;
}

//存储 Teacher 类型指针
void test03(){
	vector<Teacher*> v; //存储 Teacher 类型指针
	Teacher* t1 = new Teacher(10);
	Teacher* t2 = new Teacher(20);
	Teacher* t3 = new Teacher(30);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	//拿到容器迭代器
	vector<Teacher*>::iterator pStart = v.begin();
	vector<Teacher*>::iterator pEnd = v.end();
	//通过迭代器遍历
	while (pStart != pEnd){
		cout << (*pStart)->age << " ";
		pStart++;
	}
	cout << endl;
}
//容器嵌套容器 难点(不理解，可以跳过)
void test04()
{
	vector< vector<int> > v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 5;i++)
	{
		v1.push_back(i);
		v2.push_back(i * 10);
		v3.push_back(i * 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector< vector<int> >::iterator it = v.begin(); it != v.end();it++)
	{
		for (vector<int>::iterator subIt = (*it).begin(); subIt != (*it).end(); subIt ++)
		{
			cout << *subIt << " ";
		}
		cout << endl;
	}
} 


int main(){
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
