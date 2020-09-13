#include "LinkedList.h"


class LinkedListTest
{
public:
	LinkedListTest()
	{
		cout << "====================" << endl;
		cout << "Linked List Test!" << endl;
		cout << "--------------------" << endl;

		LinkedList<int > linked_list;
		cout << "LinkedList 是否为空：" << linked_list.isEmpty() << endl;

		for (int i = 0; i < 10; i++)
		{
			linked_list.addLast(i + 11);
		}
		linked_list.print();
		cout << "当前首元素是：" << linked_list.getFirst() << endl;
		cout << "当前尾元素是：" << linked_list.getLast() << endl;

		for (int i = 9; i >= 0; i--)
		{
			linked_list.addFirst(i);
		}
		linked_list.print();
		cout << "当前首元素是：" << linked_list.getFirst() << endl;
		cout << "当前尾元素是：" << linked_list.getLast() << endl;
		cout << "第10个元素是：" << linked_list.get(10) << endl;

		linked_list.add(10, 10);
		linked_list.print();
		cout << "第10个元素是：" << linked_list.get(10) << endl;

		for (int i = 0; i < 5; i++)
		{
			linked_list.removeLast();
		}
		linked_list.print();

		for (int i = 0; i < 5; i++)
		{
			linked_list.removeFirst();
		}
		linked_list.print();
		linked_list.set(5, 1000);
		linked_list.print();
		linked_list.removeElement(1000);
		linked_list.print();
		linked_list.remove(5);
		linked_list.print();



		cout << "====================" << endl;
		cout << endl;
	}
};