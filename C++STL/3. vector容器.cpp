#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>

using namespace std;

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



int main(){

	vector<int> v;
	for (int i = 0; i < 10;i ++){
		v.push_back(i);
		// v.capacity()容器的容量
		cout << v.capacity() << endl;  
	}

	system("pause");
	return EXIT_SUCCESS;
}
