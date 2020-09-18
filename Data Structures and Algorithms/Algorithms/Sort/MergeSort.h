#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
MergeSort（归并排序法）：
    分治法的典型应用。

自顶向下：
    每次对左右两边进行归并排序，直至两两分组。
自底向上：
    相邻两两分组，四四分组...

归并排序法最好时间复杂度： O(N)
归并排序法最坏时间复杂度： O(nlogn)
归并排序法平均时间复杂度： O(nlogn)

--------------------------------------------------
*/

void MergeSort(vector<int> &arr) 
{
    for (int i = 1; i < arr.size(); i++)
    {
        int left = 0, right = i - 1, tmp = arr[i];
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(arr[mid] > tmp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i-1; j >= left; j--)
            arr[j+1] = arr[j];
        arr[left] = tmp;
    }
}

#endif