#pragma once

template<class K, class V>
class MapNode
{
public:
	MapNode(K key = NULL, V value = NULL, MapNode<K, V> *next = NULL)
	{
		this->key = key;
		this->value = value;
		this->next = next;
	}

public:
	K key;
	V value;
	MapNode<K, V> *next;
};
