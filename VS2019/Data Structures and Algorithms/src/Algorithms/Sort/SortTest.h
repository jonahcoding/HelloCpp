#pragma once

#include <iostream>
using namespace std;
#include "BubbleSort.h"

class SortTest
{
public:
	SortTest()
	{
		vector<int> test = { 2,5,1,5,3,7,5,7,5,6 };
		BubbleSort bubbleSort(test);
		for (int i = 0; i < 10; i++) {
			cout << test[i] << " ";
		}


	}

private:

};
