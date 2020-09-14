#pragma once

#include "BSTSet.h"
#include "GetRandomNumbers.h"


class BSTSetTest
{
public:
	BSTSetTest()
	{
		GetRandomNumbers grn(1, 15, 15, false, false, false);
		vector<int> vGRN = grn.getGRN();

		cout << "====================" << endl;
		cout << "BST Set Test!" << endl;
		cout << "--------------------" << endl;
		BSTSet<int> bstSet;
		cout << "Is this Set empty? " << bstSet.isEmpty() << endl;

		for (vector<int>::iterator it = vGRN.begin(); it != vGRN.end(); it++)
		{
			bstSet.add(*it);
		}
		cout << "The size of Set is " << bstSet.size() << endl;
		cout << "Does it contain 10? " << bstSet.contains(10) << endl;
		bstSet.remove(10);
		cout << "The size of Set is " << bstSet.size() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};
