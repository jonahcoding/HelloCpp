#pragma once

#include "Queue.h"
#include "Array.h"

template<class T>
class ArrayPriorityQueue : public Queue<T>
{
public:
	int size() { return arr.size(); }
	bool isEmpty() { return arr.isEmpty(); }
	void enqueue(T num) { arr.addLast(num); }
	void dequeue() 
	{
		if (arr.isEmpty())
		{
			cout << "Failed to dequeue!" << endl;
			return;
		}
		arr.remove(findMax());
	}
	T front() { return arr.get(findMax()); }
	void print()
	{
		if (arr.isEmpty())
			return;
		cout << "[Array Priority Queue] :  ";
		cout << "Size = " << arr.size() << endl;
		cout << "front [";
		cout << arr.get(findMax()) << "...";
		cout << "] rear" << endl;
	}


private:
	int findMax()
	{
		int index = 0;
		for (int i = 0; i < arr.size(); i++)
			if (arr.get(i) > arr.get(index))
				index = i;
		return index;
	}

private:
	Array<T> arr;

};
