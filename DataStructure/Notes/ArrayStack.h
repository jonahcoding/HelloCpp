#pragma once

#include "Stack.h"
#include "Array.h"
using namespace std;

template<class T>
class ArrayStack : public Stack<T>
{
private:
	Array<T> *arr;
public:
	ArrayStack(int len = initialLen);
	void push(T num);
	void pop();
	T peek();
	int size();
	bool isEmpty();
	void print();
};

template<class T>
inline ArrayStack<T>::ArrayStack(int len)
{
	Array<T>* p = new Array<T>(len);
	arr = p;
}

template<class T>
inline void ArrayStack<T>::push(T num)
{
	arr->addLast(num);
}

template<class T>
inline void ArrayStack<T>::pop()
{
	arr->removeLast();
}

template<class T>
inline T ArrayStack<T>::peek()
{
	return arr->get(arr->size() - 1);
}

template<class T>
inline int ArrayStack<T>::size()
{
	return arr->size();
}

template<class T>
inline bool ArrayStack<T>::isEmpty()
{
	return arr->size() == 0;
}

template<class T>
inline void ArrayStack<T>::print()
{
	cout << "[ArrayStack]    ";
	cout << "Size: " << arr->size() << endl;
	cout << "[";
	for (int i = 0; i < arr->size(); i++)
	{
		cout << arr->get(i);
		if (i != arr->size() -1)
		{
			cout << ',';
		}
	}
	cout << "]top" << endl;
}
