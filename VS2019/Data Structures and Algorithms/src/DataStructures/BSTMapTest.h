#pragma once

#include "BSTMap.h"
#include "../Generic/GetRandomNumbers.h"

class BSTMapTest
{
public:
	BSTMapTest()
	{
		GetRandomNumbers grn_Key(1, 15, 15, false, false, false);
		GetRandomNumbers grn_Value(1, 15, 15, true, false, false);
		vector<int> vGRN_Key = grn_Key.getGRN();
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "BST MAP Test!" << endl;
		cout << "--------------------" << endl;
		BSTMap<int,int> bstMap;
		cout << "Is this Map empty? " << bstMap.isEmpty() << endl;

		for (vector<int>::iterator it_Key = vGRN_Key.begin(); it_Key != vGRN_Key.end(); it_Key++)
			for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
				bstMap.add(*it_Key, *it_Value);
		cout << "The size of Map is " << bstMap.size() << endl;
		cout << "Does it contain 10? " << bstMap.contains(10) << endl;
		bstMap.remove(10);
		cout << "The size of Map is " << bstMap.size() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};
