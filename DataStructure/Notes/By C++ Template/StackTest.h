#pragma once

#include "Stack.h"

void test_Stack()
{
	Stack<int> s1(10);
	cout << "Push(6/10)： " << endl;
	for (int i = 0; i < 6; i++)
	{
		s1.Push(i);
		cout << s1.Top() << "  ";
	}

	cout << "\nPop(4/6)： " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << s1.Pop() << "  ";
	}

	cout << "\nTop： " << endl;

	cout << s1.Top() << endl;
}