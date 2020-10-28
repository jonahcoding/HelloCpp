#ifndef _BINARY_INSERT_SORT_H_
#define _BINARY_INSERT_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
InsertSort（二分插入排序法）：
	1.序列第n元素为已排序序列，其余len-n个元素为未排序序列。
	2.第n个元素与第n+1个元素大小，二分插入到指定位置。

二分查找排序法时间复杂度： O(N^2)

二分查找时间复杂度：O(nlog) < O(n) 顺序查找

--------------------------------------------------
*/

void BinaryInsertSort(vector<int> &arr) 
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