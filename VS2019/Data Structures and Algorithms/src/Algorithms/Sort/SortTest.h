#pragma once

#include <iostream>
#include <chrono>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "../../Generic/GetRandomNumbers.h"

using namespace std;

class SortTest
{
public:
	SortTest()
	{
		GetRandomNumbers grn(0, 5000, 1000);
		vector<int> vGRN = grn.getGRN();

		vector<int> vecBubbleSort = BubbleSort::Sort(vGRN);
		vector<int> vecBubbleSortPro = BubbleSort::Sort_Pro(vGRN);
		vector<int> vecBubbleSortCocktail = BubbleSort::Sort_Cocktail(vGRN);
		vector<int> vecQuickSort = QuickSort::Sort(vGRN);

		printResult(vecBubbleSort);
		printResult(vecBubbleSortPro);
		printResult(vecBubbleSortCocktail);
		printResult(vecQuickSort);
	}

	void printResult(vector<int> array)
	{
		for (int i = 0; i < array.size(); i++) 
			cout << array[i] << " ";
		cout << "\n==========\n" << endl;
	}
};
