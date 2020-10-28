#pragma once

#include "LinkedListQueue.h"

class LinkedListQueueTest
{
public:
	LinkedListQueueTest()
	{
		cout << "====================" << endl;
		cout << "Linked List Queue Test!" << endl;
		cout << "--------------------" << endl;

		LinkedListQueue<int > llist_queue;
		cout << "Queue �Ƿ�Ϊ�գ�" << llist_queue.isEmpty() << endl;
		for (int i = 0; i <= 9; i++)
		{
			llist_queue.enqueue(i);
		}
		llist_queue.print();
		cout << "��ǰ�����ǣ�" << llist_queue.front() << endl;

		for (int i = 0; i < 4; i++)
		{
			llist_queue.dequeue();
		}
		llist_queue.print();

		for (int i = 0; i <= 9; i++)
		{
			llist_queue.enqueue(i + 10);
		}
		llist_queue.print();

		cout << "Queue �Ƿ�Ϊ�գ�" << llist_queue.isEmpty() << endl;
		cout << "��ǰ�����ǣ�" << llist_queue.front() << endl;

		cout << "====================" << endl;
		cout << endl;
	}

};
