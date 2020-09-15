#pragma once

#include <iostream>
using namespace std;

#include"Map.h"
#include "MapNode.h"

template<class K, class V>
class LinkedListMap : public Map<K, V>
{
public:
	LinkedListMap();
	void add(K key, V value);
	V remove(K key);
	void set(K key, V value);
	bool contains(K key);
	V get(K key);
	int size();
	bool isEmpty();
private:
	MapNode<K, V> head;
	int m_size;
};

template<class K, class V>
inline LinkedListMap<K, V>::LinkedListMap()
{
	head.key = NULL;
	head.value = NULL;
	head.next = NULL;
	m_size = 0;
}

template<class K, class V>
inline void LinkedListMap<K, V>::add(K key, V value)
{
	if (!contains(key))
	{
		MapNode<K, V> *p = new MapNode<K, V>(key, value, head.next);
		head.next = p;
		m_size++;
	}
}

template<class K, class V>
inline V LinkedListMap<K, V>::remove(K key)
{
	MapNode<K, V> *pre = &head;
	MapNode<K, V> *node = pre->next;
	while (node)
	{
		if (key == node->key)
		{
			pre->next = node->next;
			V res = node->value;
			delete node;
			m_size--;
			return res;
		}
		pre = node;
		node = node->next;
	}
	cout << "Not included in the Map: " << key << endl;
	return NULL;
}

template<class K, class V>
inline void LinkedListMap<K, V>::set(K key, V value)
{
	MapNode<K, V> *node = head.next;
	while (node)
	{
		if (key == node->key)
		{
			node->value = value;
			return;
		}
		node = node->next;
	}
	cout << "Not included in the Map: " << key << endl;
}

template<class K, class V>
inline bool LinkedListMap<K, V>::contains(K key)
{
	MapNode<K, V> *node = head.next;
	while (node)
	{
		if (key == node->key)
			return true;
		else
			node = node->next;
	}
	return false;
}

template<class K, class V>
inline V LinkedListMap<K, V>::get(K key)
{
	MapNode<K, V> *node = head.next;
	while (node)
	{
		if (key == node->key)
			return node->value;
		else
			node = node->next;
	}
	cout << "Not included in the Map: " << key << endl;
	return NULL;
}

template<class K, class V>
inline int LinkedListMap<K, V>::size()
{
	return m_size;
}

template<class K, class V>
inline bool LinkedListMap<K, V>::isEmpty()
{
	return m_size == 0;
}
