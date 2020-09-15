#pragma once

#include "Queue.h"
#include "LinkedList.h"

template<class T>
class LinkedListPriorityQueue : public Queue<T>
{
public:
	int size() { return llist.size(); }
	bool isEmpty() { return llist.isEmpty(); }
	void enqueue(T num) { llist.addLast(num); }
	void dequeue()
	{
		if (llist.isEmpty())
		{
			cout << "Failed to dequeue!" << endl;
			return;
		}
		llist.remove(findMax());
	}
	T front() { return llist.get(findMax()); }
	void print()
	{
		if (llist.isEmpty())
			return;
		cout << "[Array Priority Queue] :  ";
		cout << "Size = " << llist.size() << endl;
		cout << "front [";
		cout << llist.get(findMax()) << "...";
		cout << "] rear" << endl;
	}

private:
	int findMax()
	{
		int index = 0;
		for (int i = 0; i < llist.size(); i++)
			if (llist.get(i) > llist.get(index))
				index = i;
		return index;
	}

private:
	LinkedList<T> llist;

};
