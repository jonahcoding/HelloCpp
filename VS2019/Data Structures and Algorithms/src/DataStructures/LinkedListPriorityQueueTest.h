#pragma once

#include "LinkedListPriorityQueue.h"
#include "GetRandomNumbers.h"

class LinkedListPriorityQueueTest
{
public:
	LinkedListPriorityQueueTest()
	{
		GetRandomNumbers grn_Value(1, 15, 15, false, false, false);
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "Linked List Priority Queue Test!" << endl;
		cout << "--------------------" << endl;
		LinkedListPriorityQueue<int> llist_priorityQueue;
		cout << "Is this Queue empty? " << llist_priorityQueue.isEmpty() << endl;

		for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
			llist_priorityQueue.enqueue(*it_Value);

		cout << "The size of Priority Queue is " << llist_priorityQueue.size() << endl;
		llist_priorityQueue.print();
		cout << endl;
		llist_priorityQueue.dequeue();
		cout << "The size of Priority Queue is " << llist_priorityQueue.size() << endl;
		llist_priorityQueue.print();

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};