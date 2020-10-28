#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
QuickSort（快速排序法）：
	1.取左边第一个元素为基准。
	2.从右至左查找小于基准的元素（升序），赋值给左索引位，同时左索引自加。
	3.从左至右查找大于基准的元素（升序），赋值给右索引位，同时右索引自加。
    4.左右索引相等时，将基准元素赋值给左索引。
    5.基准中数组中间元素交换。
    6.分治递归。

最好时间复杂度：O(n*log(n))	
最坏时间复杂度：O(N^2) 待排序列为正序或逆序，且每次划分为得到比上次划分少一个元素的子序列（另一序列为空）
平均时间复杂度：O(n*log(n))

稳定，原地排序。

改进：
	1.基准取左中右三值得中间值。
    2.序列较小时使用插入排序法。
    3.重复元素较多时使用三分区法。
--------------------------------------------------
*/

void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int low = left, high = right, mid = (left+right)/2, datum;
        if (arr[mid] > arr[high]) { swap(arr[mid], arr[high]); }
        if (arr[low] > arr[high]) { swap(arr[low], arr[high]); }
        if (arr[mid] > arr[low]) { swap(arr[mid], arr[low]); }    
        datum = arr[low];
        while (low < high)
        {
            while (low < high && arr[high] >= datum) //升序
                high--;
            if (low < high)
                arr[low++] = arr[high];
            while (low < high && arr[low] <= datum)  //升序
                low++;
            if (low < high)
                arr[high--] = arr[low];
        }
        arr[low] = datum;
        quickSort(arr, left, low-1);
        quickSort(arr, low+1, right);
    }
}

void QuickSort(vector<int> &arr)
{
    cout << "[Quick Sort]" << endl;
    if (arr.size() > 0)
        quickSort(arr, 0, arr.size()-1);
}

#endif