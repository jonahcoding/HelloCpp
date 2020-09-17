#pragma once

#include "PriorityQueue.h"
#include "../Generic/GetRandomNumbers.h"

class PriorityQueueTest
{
public:
	PriorityQueueTest()
	{
		GetRandomNumbers grn_Value(1, 15, 15, false, false, false);
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "Priority Queue Test!" << endl;
		cout << "--------------------" << endl;
		PriorityQueue<int> priorityQueue;
		cout << "Is this Queue empty? " << priorityQueue.isEmpty() << endl;

		for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
			priorityQueue.enqueue(*it_Value);

		cout << "The size of Priority Queue is " << priorityQueue.size() << endl;
		priorityQueue.print();
		cout << endl;
		priorityQueue.dequeue();
		cout << "The size of Priority Queue is " << priorityQueue.size() << endl;
		priorityQueue.print();

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}
};
