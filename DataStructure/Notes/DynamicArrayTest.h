#pragma once
#include "DynamicArray.h"
using namespace std;

class DynamicArrayTest
{
public:
	DynamicArrayTest();
};

DynamicArrayTest::DynamicArrayTest()
{
	DynamicArray<int > arr(15);
	for (int i = 0; i < 14; i++)
	{
		arr.add(0, i);
	}

	arr.addFirst(-1);
	arr.addLast(10);
	arr.print();
	arr.removeFirst();
	arr.removeLast();
	arr.remove(5);
	arr.print();
	arr.removeElement(7);
	arr.print();
	arr.set(1, 7);
	arr.print();

	for (int i = 0; i < 7; i++)
	{
		arr.removeFirst();
	}
	arr.print();
	cout << "下标为3的元素是：" <<arr.get(3) << endl;
	cout << "元素1的下标索引是：" << arr.find(1) << endl;
	cout << "是否包含元素9：bool = " << arr.contains(9) << endl;
}
