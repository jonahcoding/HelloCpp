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
		cout << "Queue 是否为空：" << llist_queue.isEmpty() << endl;
		for (int i = 0; i <= 9; i++)
		{
			llist_queue.enqueue(i);
		}
		llist_queue.print();
		cout << "当前队首是：" << llist_queue.front() << endl;

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

		cout << "Queue 是否为空：" << llist_queue.isEmpty() << endl;
		cout << "当前队首是：" << llist_queue.front() << endl;

		cout << "====================" << endl;
		cout << endl;
	}

};
