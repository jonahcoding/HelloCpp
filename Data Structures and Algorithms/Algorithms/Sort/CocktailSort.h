#ifndef _COCK_TAIL_SORT_H_
#define _COCK_TAIL_SORT_H_

#include <iostream>
#include <vector>
using namespace std;

/*
--------------------------------------------------
变种：
	鸡尾酒排序：
		1.从左到右排序，再从右到左排序，确定最大值与最小值。
		2.重复以上步骤。
--------------------------------------------------
*/

void CocktailSort(vector<int> &arr)
{
    cout << "[Cocktail Sort]" << endl;
    bool notSorted = true;
    for (int i = 0; i < arr.size()-1 && notSorted; i++)
    {
        notSorted = false;
        for (int j = i; j < arr.size()-1-i; j++)
        {
            if (arr[j] > arr[j + 1])      //升序
            // if (arr[j] < arr[j + 1])      //降序
            {
                swap(arr[j], arr[j+1]);
                notSorted = true;
            }
        }

        for (int j = arr.size()-1-i; j > i; j--)
        {
            if (arr[j-1] > arr[j])    //升序
            // if (arr[j-1] < arr[j])    //降序
            {
                swap(arr[j-1], arr[j]);
                notSorted = true;
            }
        }
    }
}

#endif