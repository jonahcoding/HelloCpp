#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
--------------------------------------------------
myArray类的实现：
	1. 默认构造。
	2. 有参构造。
	3. 拷贝构造。
	4. 数组尾插。
	5. 按位置设置数据。
	6. 按位置获取数据。
	7. 获取数组容量。
	8. 获取数组大小。
	9.
--------------------------------------------------
*/



class myArray
{
public:
	myArray();//默认100容量
	myArray(int capacity);//有参构造
	myArray(const myArray &arr);//拷贝构造

	void pushback(int val);//尾插法
	void setData(int pos, int val);//按位置设置数据
	int getData(int pos);//按位置获取数据
	int getCapacity();//获取数组容量
	int getSize();//获取数组大小

	~myArray();

private:
	int m_Capacity;//数组容量
	int m_Size;//数组大小
	int* pAddress;//在堆区开辟的数组的指针

};