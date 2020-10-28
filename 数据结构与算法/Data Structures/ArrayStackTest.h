#pragma once
#include "ArrayStack.h"
using namespace std;

class ArrayStackTest
{
public:
	ArrayStackTest()
	{
		cout << "====================" << endl;
		cout << "Array Stack Test!" << endl;
		cout << "--------------------" << endl;

		ArrayStack<int > arr_s(10);

		for (int i = 0; i < 14; i++)
		{
			arr_s.push(i);
		}
		arr_s.print();

		for (int i = 0; i < 4; i++)
		{
			arr_s.pop();
		}

		arr_s.print();
		cout << "Stack �Ƿ�Ϊ�գ�" << arr_s.isEmpty() << endl;
		cout << "��ǰջ��Ԫ���ǣ�" << arr_s.peek() << endl;

		cout << "====================" << endl;
		cout << endl;
	}
};

//��¼������ʵ�ֱ�����ʾ "ArrayStack�ض���"