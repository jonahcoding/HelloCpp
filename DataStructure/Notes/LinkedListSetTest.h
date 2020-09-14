#pragma once

#include "LinkedListSet.h"

class LinkedListSetTest
{
public:
	LinkedListSetTest()
	{
		GetRandomNumbers grn(1, 15, 15, false, false, false);
		vector<int> vGRN = grn.getGRN();

		cout << "====================" << endl;
		cout << "Linked List Set Test!" << endl;
		cout << "--------------------" << endl;
		LinkedListSet<int> llistSet;
		cout << "Is this Set empty? " << llistSet.isEmpty() << endl;

		for (vector<int>::iterator it = vGRN.begin(); it != vGRN.end(); it++)
		{
			llistSet.add(*it);
		}
		cout << "The size of Set is " << llistSet.size() << endl;
		cout << "Does it contain 10? " << llistSet.contains(10) << endl;
		llistSet.remove(10);
		cout << "The size of Set is " << llistSet.size() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};
