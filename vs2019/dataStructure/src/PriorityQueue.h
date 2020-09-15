#pragma once

#include "Queue"
#include "MaxHeap.h"

template<class T>
class PriorityQueue : public Queue<T>
{
public:
	int size() { return heap.size(); }
	bool isEmpty() { return heap.isEmpty(); }
	void enqueue(T num) { heap.add(num); }
	void dequeue() { heap.extractMax(); }
	T front() { return heap.findMax(); }
	void print()
	{
		if (heap.isEmpty())
			return;
		cout << "[Priority Queue] :  ";
		cout << "Size = " << heap.size() << endl;
		cout << "front [";
		cout << heap.findMax() << "...";
		cout << "] rear" << endl;
	}

private:
	MaxHeap<T> heap;
};

