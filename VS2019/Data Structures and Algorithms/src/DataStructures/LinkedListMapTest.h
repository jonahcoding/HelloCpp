#pragma

#include "LinkedListMap.h"
#include "../Generic/GetRandomNumbers.h"

class LinkedListMapTest
{
public:
	LinkedListMapTest()
	{
		GetRandomNumbers grn_Key(1, 15, 15, false, false, false);
		GetRandomNumbers grn_Value(1, 15, 15, true, false, false);
		vector<int> vGRN_Key = grn_Key.getGRN();
		vector<int> vGRN_Value = grn_Value.getGRN();

		cout << "====================" << endl;
		cout << "Linked List MAP Test!" << endl;
		cout << "--------------------" << endl;
		LinkedListMap<int, int> llistMap;
		cout << "Is this Map empty? " << llistMap.isEmpty() << endl;

		for (vector<int>::iterator it_Key = vGRN_Key.begin(); it_Key != vGRN_Key.end(); it_Key++)
			for (vector<int>::iterator it_Value = vGRN_Value.begin(); it_Value != vGRN_Value.end(); it_Value++)
				llistMap.add(*it_Key, *it_Value);
		cout << "The size of Map is " << llistMap.size() << endl;
		cout << "Does it contain 10? " << llistMap.contains(10) << endl;
		cout << "The value for key 10 is " << llistMap.get(10) << endl;
		llistMap.set(10, 1000);
		cout << "The value for key 10 is " << llistMap.get(10) << endl;
		llistMap.remove(10);
		cout << "Does it contain 10? " << llistMap.contains(10) << endl;
		cout << "The size of Map is " << llistMap.size() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}
};