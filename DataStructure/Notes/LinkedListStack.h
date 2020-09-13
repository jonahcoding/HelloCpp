#pragma once

#include "Stack.h"
#include "LinkedList.h"

template<class T>
class LinkedListStack : public Stack<T>
{
private:
	LinkedList<T> list;
public:
	 LinkedListStack();
	 void push(T num);
	 void pop();
	 T peek();
	 int size();
	 void print();
	 bool isEmpty();
};

template<class T>
inline LinkedListStack<T>::LinkedListStack() {}

template<class T>
inline void LinkedListStack<T>::push(T num)
{
	list.addFirst(num);
}

template<class T>
inline void LinkedListStack<T>::pop()
{
	list.removeFirst();
}

template<class T>
inline T LinkedListStack<T>::peek()
{
	return list.get(0);
}

template<class T>
inline int LinkedListStack<T>::size()
{
	return list.size();
}

template<class T>
inline void LinkedListStack<T>::print()
{
	cout << "[LinkedListStack]    ";
	cout << "Size: " << list.size() << endl;
	cout << "top[";
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.get(i) << "->";
	}
	cout << "NULL" << endl;
}

template<class T>
inline bool LinkedListStack<T>::isEmpty()
{
	return list.size() == 0;
}


