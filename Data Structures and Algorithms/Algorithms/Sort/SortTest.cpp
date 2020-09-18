#include <iostream>
#include <vector>
using namespace std;

#include "GenerateRandomArray.h"
#include "BubbleSort.h"
#include "CocktailSort.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "BinaryInsertSort.h"


//Print Array
void printArr(vector<int> arr)
{
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) { cout << *it << " "; } 
    cout << endl; 
    cout << endl; 
}

//Test Sorting Algorithm
void test()
{
    // vector<int> arr = GenerateRandomArray(0, 20, 10); //无序
    vector<int> arr = GenerateRandomArray(0, 20, 10, true); //无序，重复
    // vector<int> arr = GenerateRandomArray(0, 20, 10, false, true); //有序，不重复
    // vector<int> arr = GenerateRandomArray(0, 20, 10, true, true); //有序，重复
    cout << "The random array generated is: " << endl;
    printArr(arr);

    // BubbleSort(arr);
    // CocktailSort(arr);
    // QuickSort(arr);
    //InsertSort(arr);
    BinaryInsertSort(arr);


    printArr(arr);

}

int main()
{
    test();

    system("pause");
    return 0;
}
