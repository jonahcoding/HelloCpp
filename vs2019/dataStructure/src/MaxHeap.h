#pragma once

#include "Array.h"

template<class T>
class MaxHeap
{
public:
	int size() { return arr.size(); }
	bool isEmpty() { return arr.isEmpty(); }

	//Add data to the end of the array, 
	//and then adjust the position according to the value of the data.
	void add(T num)
	{
		arr.addLast(num);
		siftUp(arr.size() - 1);
	}

	//Binary heap does not support search.
	//Exchange and delete the root node and the end element of the array, 
	//and then adjust the root node
	T extractMax()
	{
		T res = findMax();
		swap(0, arr.size() - 1);
		arr.removeLast();
		siftDown(0);
		return res;
	}

	T findMax()
	{
		if (arr.size() == 0)
		{
			cout << "Binary heap is empty!" << endl;
			return NULL;
		}
		return arr.get(0);
	}

private:
	Array<T> arr;
private:
	//Return the index of the parent node.
	int parent(int index)
	{
		if (index <= 0 || index >= arr.size())
		{
			return NULL;
		}
		return (index - 1) / 2;
	}
	//Returns the index of the left child node.
	int leftChild(int index)
	{
		return (index * 2) + 1;
	}
	//Returns the index of the right child node.
	int rightChild(int index)
	{
		return (index + 1) * 2;
	}

	void siftUp(int index)
	{
		while (index && arr.get(index) > arr.get(parent(index)))
		{
			swap(index, parent(index));
			index = parent(index);
		}
	}

	void swap(int i, int j)
	{
		if (i < 0 || i >= arr.size() || j < 0 || j >= arr.size())
		{
			return;
		}
		T t = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, t);
	}

	void siftDown(int index)
	{
		while (leftChild(index) < arr.size())
		{
			int left = leftChild(index);
			if (left + 1 < arr.size() && arr.get(left + 1) > arr.get(left))
			{
				left++;
			}
			if (arr.get(left) <= arr.get(index))
			{
				break;
			}
			swap(index, left);
			index = left;
		}
	}
};
