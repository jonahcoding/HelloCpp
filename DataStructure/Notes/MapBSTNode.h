#pragma once

template<class K, class V>
class MapBSTNode
{
public:
	MapBSTNode(K key, V value, MapBSTNode<K, V>* left = NULL, MapBSTNode<K, V>* right = NULL)
	{
		m_key = key;
		m_value = value;
		this->left = left;
		this->right = right;
	}

	K m_key;
	V m_value;
	MapBSTNode<K, V>* left;
	MapBSTNode<K, V>* right;
};
