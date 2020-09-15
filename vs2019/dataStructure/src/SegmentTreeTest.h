#pragma once

#include "SegmentTree.h"
#include "GetRandomNumbers.h"

class SegmentTreeTest
{
public:
	SegmentTreeTest()
	{
		cout << "====================" << endl;
		cout << "Segment Tree Test!" << endl;
		cout << "--------------------" << endl;

		int arrLen = 20;
		int* pArr = new int[arrLen];
		
		GetRandomNumbers grn(1, 100, 20, false, false, false);
		vector<int> vGRN = grn.getGRN();
		for (vector<int>::iterator it = vGRN.begin(); it != vGRN.end(); it++)
			for (int i = 0; i < arrLen; i++)
				pArr[i] = *it;

		SegmentTree<int> sTree(pArr, arrLen);
		cout << "Is this Tree empty? " << sTree.isEmpty() << endl;
		cout << "The size of Segment Tree is " << sTree.size() << endl;
		sTree.print();
		cout << endl;
		cout << "The fifth element is " << sTree.get(5) << endl;
		cout << endl;
		sTree.query(0, 8);
		cout << "The fifth element is " << sTree.get(5) << endl;
		cout << endl;
		cout << "====================" << endl;
		cout << endl;

	}

};