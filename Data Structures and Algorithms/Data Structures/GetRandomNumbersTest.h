#pragma once

#include "GetRandomNumbers.h"

class GetRandomNumbersTest
{
public:
	GetRandomNumbersTest()
	{
		vector<int> vGRN;
		bool GRN_REPEAT = false;
		bool GRN_ORDER = true;
		bool GRN_DESCEND = false;
		GetRandomNumbers grn(0, 10, 20, GRN_REPEAT, GRN_ORDER, GRN_DESCEND);
		vGRN = grn.getGRN();

		cout << "====================" << endl;
		cout << "Get Random Numbers Test!" << endl;
		cout << "--------------------" << endl;
		cout << "Count: " << grn.getGRNSize() << endl;
		cout << "Repeat(bool): " << GRN_REPEAT << endl;
		cout << "Sequence(bool): " << GRN_ORDER << endl;
		cout << "Descend(bool): " << GRN_DESCEND << endl;
		cout << "--------------------" << endl;

		for (vector<int>::iterator it = vGRN.begin(); it != vGRN.end(); it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}
};