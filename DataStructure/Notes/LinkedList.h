#pragma once

#include "Node.h"

template<class T>
class LinkedList
{
private:
	Node<T> head;
	int m_size;
public:
	LinkedList();
	void add(int index, T num);
	void addFirst(T num);
	void addLast(T num);
	T remove(int index);
	T removeFirst();
	T removeLast();
	void removeElement(T num);
	void set(int index, T num);
	T get(int index);
	T getFirst();
	T getLast();
	bool contains(T num);
	int size();
	bool isEmpty();
	void print();
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	head.m_data = NULL;
	head.next = NULL;
	m_size = 0;
}

template<class T>
inline void LinkedList<T>::add(int index, T num)
{
	if (index < 0 || index > m_size)
	{
		cout << "非法位置！" << endl;
		throw 0;
	}
	Node<T> * node = &head;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	node->next = new Node<T>(num, node->next);
	m_size++;
}

template<class T>
inline void LinkedList<T>::addFirst(T num)
{
	add(0, num);
}

template<class T>
inline void LinkedList<T>::addLast(T num)
{
	add(m_size, num);
}

template<class T>
inline T LinkedList<T>::remove(int index)
{
	if (index < 0 || index > m_size)
	{
		cout << "非法位置！" << endl;
		throw 0;
	}
	Node<T>* node = &head;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	Node<T>* p = node->next;
	T res = node->m_data;
	node->next = p->next;
	delete p;
	m_size--;
	return res;
}

template<class T>
inline T LinkedList<T>::removeFirst()
{
	return remove(0);
}

template<class T>
inline T LinkedList<T>::removeLast()
{
	return remove(m_size - 1);
}

template<class T>
inline void LinkedList<T>::removeElement(T num)
{
	if (!head.next)
	{
		throw 0;
	}
	Node<T>* node = &head;
	Node<T>* p;
	while (node)
	{
		p = node->next;
		if (p->m_data ==  num)
		{
			node->next = p->next;
			delete p;
			m_size--;
			return;
		}
		node = p;
	}
}

template<class T>
inline void LinkedList<T>::set(int index, T num)
{
	if (index < 0 || index >= m_size) {
		cout << "访问位置非法！" << endl;
		return;
	}
	Node<T>* node = head.next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	node->m_data = num;
}

template<class T>
inline T LinkedList<T>::get(int index)
{
	if (index < 0 || index >= m_size) {
		cout << "访问位置非法！" << endl;
		return NULL;
	}
	Node<T>* node = head.next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	return node->m_data;
}

template<class T>
inline T LinkedList<T>::getFirst()
{
	return get(0);
}

template<class T>
inline T LinkedList<T>::getLast()
{

	return get(m_size - 1);
}

template<class T>
inline bool LinkedList<T>::contains(T num)
{
	Node<T>* node = head->next;
	while (node)
	{
		if (node->m_data == num)
		{
			return true;
		}
		node = node->next;
	}
	return false;
}

template<class T>
inline int LinkedList<T>::size()
{
	return m_size;
}

template<class T>
inline bool LinkedList<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
inline void LinkedList<T>::print()
{
	cout << "[LinkedList]    ";
	cout << "Size: " << m_size << endl;
	Node<T>* node = head.next;
	while (node)
	{
		cout << node->m_data << " -> ";
		node = node->next;
	}
	cout << "NULL" << endl;
}
