#pragma once

#include "Queue.h"
#include "Array.h"

template<class T>
class ArrayQueue : public Queue<T>
{
private:
	Array<T> *arr;
public:
	ArrayQueue(int len = initialLen);
	void enqueue(T num);
	void dequeue();
	T front();

	int size();
	bool isEmpty();
	void print();
};

template<class T>
inline ArrayQueue<T>::ArrayQueue(int len)
{
	Array<T>* p = new Array<T>(len);
	arr = p;
}

template<class T>
inline void ArrayQueue<T>::enqueue(T num)
{
	arr->addLast(num);
}

template<class T>
inline void ArrayQueue<T>::dequeue()
{
	arr->removeFirst();
}

template<class T>
inline T ArrayQueue<T>::front()
{
	return arr->get(0);
}

template<class T>
inline int ArrayQueue<T>::size()
{
	return arr->size();
}

template<class T>
inline bool ArrayQueue<T>::isEmpty()
{
	return arr->size() == 0;
}

template<class T>
inline void ArrayQueue<T>::print()
{
	cout << "[ArrayQueue]    ";
	cout << "Capacity: " << arr->capacity() << "    Size: " << arr->size() << endl;
	cout << "[";
	for (int i = 0; i < arr->size(); i++)
	{
		cout << arr->get(i);
		if (i != arr->size() -1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}

