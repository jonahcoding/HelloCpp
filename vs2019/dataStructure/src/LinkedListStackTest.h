#pragma once

#include "LinkedListStack.h"

class LinkedListStackTest
{
public:
	LinkedListStackTest()
	{
		cout << "====================" << endl;
		cout << "Linked List Stack Test!" << endl;
		cout << "--------------------" << endl;

		LinkedListStack<int > llist_stack;
		cout << "Stack �Ƿ�Ϊ�գ�" << llist_stack.isEmpty() << endl;
		for (int i = 0; i < 10; i++)
		{
			llist_stack.push(i);
		}
		llist_stack.print();
		cout << "��ǰջ��Ԫ���ǣ�" << llist_stack.peek() << endl;

		for (int i = 0; i < 5; i++)
		{
			llist_stack.pop();
		}
		llist_stack.print();
		cout << "��ǰջ��Ԫ���ǣ�" << llist_stack.peek() << endl;

		cout << "====================" << endl;
		cout << endl;
	}

};
