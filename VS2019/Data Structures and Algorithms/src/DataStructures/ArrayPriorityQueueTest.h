#pragma once

#include "ArrayPriorityQueue.h"
#include "GetRandomNumbers.h"

class ArrayPriorityQueueTest
{
public:
	ArrayPriorityQueueTest()
	{
		GetRandomNumbers grn_Value(1, 15, 15, false, false, false);
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "Array Priority Queue Test!" << endl;
		cout << "--------------------" << endl;
		ArrayPriorityQueue<int> arr_priorityQueue;
		cout << "Is this Queue empty? " << arr_priorityQueue.isEmpty() << endl;

		for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
			arr_priorityQueue.enqueue(*it_Value);

		cout << "The size of Priority Queue is " << arr_priorityQueue.size() << endl;
		arr_priorityQueue.print();
		cout << endl;
		arr_priorityQueue.dequeue();
		cout << "The size of Priority Queue is " << arr_priorityQueue.size() << endl;
		arr_priorityQueue.print();

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};