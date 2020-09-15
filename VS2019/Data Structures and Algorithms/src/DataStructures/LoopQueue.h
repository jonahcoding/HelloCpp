#pragma once
#include "Queue.h"

#include <iostream>
using namespace std;

template<class T>
class LoopQueue : public Queue<T>
{
private:
	T* m_data;
	int m_capacity;
	int m_size;
	int m_front;
	int m_rear;
public:
	LoopQueue(int len = initialLen);
	void resize(int len);
	void enqueue(T num);
	void dequeue();
	T front();

	int size();
	bool isEmpty();
	void print();
};

template<class T>
inline LoopQueue<T>::LoopQueue(int len)
{
	T* p = new T[len];
	m_data = p;
	m_capacity = len;
	m_size = m_front = m_rear = 0;
}

template<class T>
inline void LoopQueue<T>::resize(int len)
{
	T* p = new T[len];
	if (m_size == 0) {}
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			p[i] = m_data[(i + m_front) % m_capacity];
		}
	}
	delete[] m_data;
	m_data = p;
	m_capacity = len;
	m_front = 0;
	m_rear = m_size;
}

template<class T>
inline void LoopQueue<T>::enqueue(T num)
{
	if (m_size >= m_capacity)
	{
		resize(m_capacity * 2);
	}
	m_data[m_rear] = num;
	m_size++;
	m_rear = (m_rear + 1) % m_capacity;
}

template<class T>
inline void LoopQueue<T>::dequeue()
{
	if (m_size == 0)
	{
		cout << "Õ»Îª¿Õ£¡" << endl;
		throw 0;
	}
	if (m_size <= m_capacity / 4)
	{
		resize(m_capacity / 2);
	}
	m_size--;
	m_front = (m_front + 1) % m_capacity;
}

template<class T>
inline T LoopQueue<T>::front()
{
	return m_data[m_front];
}

template<class T>
inline int LoopQueue<T>::size()
{
	return m_size;
}

template<class T>
inline bool LoopQueue<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
inline void LoopQueue<T>::print()
{
	cout << "[LoopQueue]    ";
	cout << "Capacity: " << m_capacity << "    Size: " << m_size << endl;
	cout << "front[";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[(i + m_front) % m_capacity];
		if (i != m_size - 1)
		{
			cout << ",";
		}
	}
	cout << "]rear" << endl;
}
