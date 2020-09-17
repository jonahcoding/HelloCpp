#pragma once

#include <iostream>
#include <vector>
using namespace std;

class QuickSort
{
public:
	static void quickSort(int left, int right, vector<int> &arr)
	{
		if (left >= right)
			return;
		int low, high, mid, pivot;
		low = left, high = right;
		mid = (low + high) / 2;
		if (arr[mid] > arr[high]) { swap(arr[mid], arr[high]); }
		if (arr[low] > arr[high]) { swap(arr[low], arr[high]); }
		if (arr[mid] > arr[low]) { swap(arr[mid], arr[low]); }

		pivot = arr[low];
		while (low < high)
		{
			while (arr[high] >= pivot && low < high)
				high--;
			while (arr[low] <= pivot && low < high)
				low++;
			if (low < high)
			{
				swap(arr[low], arr[high]);
			}
		}
		swap(arr[left], arr[low]);
		quickSort(left, low - 1, arr);
		quickSort(low + 1, right, arr);
	}

	static vector<int> Sort(vector<int> arr)
	{
		if (arr.size() > 0)
			quickSort(0, arr.size() - 1, arr);
			return arr; 
	}
};
