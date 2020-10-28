#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
InsertSort（插入排序法）：
	1.序列第n元素为已排序序列，其余len-n个元素为未排序序列。
	2.第n个元素与第n+1个元素大小，冒泡插入到指定位置。

最好时间复杂度：O(N) 原数组正序。	
最坏时间复杂度：O(N^2) 原数组逆序。
平均时间复杂度：O(N^2) 

改进：
	1.已排序序列中使用二分法插入。

--------------------------------------------------
*/

void InsertSort(vector<int> &arr) 
{
    for (int i = 1; i < arr.size(); i++)
        for (int j = i -1; j >= 0 && arr[j] > arr[j+1]; j--)//  正序
            swap(arr[j], arr[j+1]);   
}

#endif
