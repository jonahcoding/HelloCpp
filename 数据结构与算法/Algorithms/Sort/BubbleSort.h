#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
BubbleSort（冒泡排序法）：
	1.比较相邻元素，前者比后者大（小）则交换。
	2.开始第一对至末尾，一次操作后末尾为最大值。
	3.重复以上步骤直至全部有序。

稳定排序：元素大小相同不改变位置。

最好时间复杂度：O(N)	所有元素正序
最坏时间复杂度：O(N^2)	所有元素反序
平均时间复杂度：O(N^2)	

改进：
	设置标志位，若某次遍历排序未发生交换说明已经有序。

变种：
	鸡尾酒排序：
		1.从左到右排序，再从右到左排序，确定最大值与最小值。
		2.重复以上步骤。
--------------------------------------------------
*/

void BubbleSort(vector<int> &arr)
{
    cout << "[Bubble Sort]" << endl;
    bool notSorted = true;
    for (int i = 0; i < arr.size()-1 && notSorted; i++)
    {
        notSorted = false;
        for (int j = 0; j < arr.size()-1-i; j++)
        {
            if (arr[j] > arr[j+1])  //升序
            // if (arr[j] < arr[j+1])   //降序
            {
                swap(arr[j], arr[j+1]);
                notSorted = true;
            }
        }
    }
}

#endif