#pragma once

#include "MaxHeap.h"
#include "../Generic/GetRandomNumbers.h"

class MaxHeapTest
{
public:
	MaxHeapTest()
	{
		GetRandomNumbers grn_Value(1, 50, 20, false, false, false);
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "Max Heap Test!" << endl;
		cout << "--------------------" << endl;
		MaxHeap<int> maxHeap;
		cout << "Is this MaxHeap empty? " << maxHeap.isEmpty() << endl;

		for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
		{
			maxHeap.add(*it_Value);
			//cout << *it_Value << " ";
		}
		//cout << endl;

		cout << "The size of MaxHeap is " << maxHeap.size() << endl;
		cout << "The max value of MaxHeap is " << maxHeap.findMax() << endl;

		maxHeap.extractMax();
		cout << "The size of MaxHeap is " << maxHeap.size() << endl;
		cout << "The max value of MaxHeap is " << maxHeap.findMax() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};
