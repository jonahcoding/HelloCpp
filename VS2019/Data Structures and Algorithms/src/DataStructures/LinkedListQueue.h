#pragma once

#include "Queue.h"
#include "Node.h"
#include "LinkedList.h"


template<class T>
class LinkedListQueue : public Queue<T>
{
private:
	Node<T>* head;
	Node<T>* tail;
	int m_size;
public:
	LinkedListQueue();
	void enqueue(T num);
	void dequeue();
	T front();

	int size();
	bool isEmpty();
	void print();
};

template<class T>
inline LinkedListQueue<T>::LinkedListQueue()
{
	head = NULL;
	tail = NULL;
	m_size = 0;
}

template<class T>
inline void LinkedListQueue<T>::enqueue(T num)
{
	if (head == NULL)
	{
		head = new Node<T>(num, NULL);
		tail = head;
	}
	else
	{
		tail->next = new Node<T>(num, NULL);
		tail = tail->next;
	}
	m_size++;
}

template<class T>
inline void LinkedListQueue<T>::dequeue()
{
	if (m_size == 0)
	{
		cout << "出队失败！队列为空！" << endl;
		throw 0;
	}
	Node<T>* node = head->next;
	delete head;
	head = node;
	m_size--;
}

template<class T>
inline T LinkedListQueue<T>::front()
{
	if (m_size == 0)
	{
		cout << "出队失败！队列为空！" << endl;
		return NULL;
	}
	return head->m_data;
}

template<class T>
inline int LinkedListQueue<T>::size()
{
	return m_size;
}

template<class T>
inline bool LinkedListQueue<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
inline void LinkedListQueue<T>::print()
{
	Node<T>* node = head;
	cout << "[LinkedListQueue]    ";
	cout << "Size: " << size() << endl;
	cout << "front ";
	while (node)
	{
		cout << node->m_data << " -> ";
		node = node->next;
	}
	cout << "NULL rear" << endl;
}

