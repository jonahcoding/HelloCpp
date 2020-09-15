#pragma once

#include "MapBSTNode.h"

template<class K, class V>
class MapBST
{
public:
	MapBST() { root = NULL; }

	int size() { return m_size; }

	bool isEmpty() { return m_size == NULL; }

	void add(K key, V value) { root = add(root, key, value); }

	V remove(K key)
	{
		V res = get(key);
		root = remove(root, key);
		return res;
	}

	void set(K key, V value)
	{
		MapBSTNode<K, V>* node = root;
		while (node)
		{
			if (key == node->m_key)
			{
				node->m_value = value;
				return;
			}
			else if (key < node->m_key)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
		}
		cout << "Not Exist : " << key << endl;
		return;
	}

	V get(K key)
	{
		MapBSTNode<K, V>* node = root;
		while (node)
		{
			if (key == node->m_key)
			{
				return node->m_value;
			}
			else if (key < node->m_key)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
		}
		cout << "Not Exist : " << key << endl;
		return NULL;
	}

	bool contains(K key)
	{
		return contains(root, key);
	}

private:
	MapBSTNode<K, V> *root;
	int m_size;

	MapBSTNode<K, V>* add(MapBSTNode<K, V>* node, K key, V value)
	{
		if (node == NULL)
		{
			m_size++;
			return new MapBSTNode<K, V>(key, value);
		}
		else if (key < node->m_key)
		{
			node->left = add(node->left, key, value);
		}
		else if (key > node->m_key)
		{
			node->right = add(node->right, key, value);
		}
		return node;
	}

	MapBSTNode<K, V>* remove(MapBSTNode<K, V>* node, K key)
	{
		if (node == NULL)
		{
			return node;
		}
		if (key < node->m_key)
		{
			node->left = remove(node->left, key);
		}
		else if (key > node->m_key)
		{
			node->right = remove(node->right, key);
		}
		else if (key == node->m_key)
		{
			if (node->left == NULL)
			{
				MapBSTNode<K, V>* rightNode = node->right;
				delete node;
				m_size--;
				return rightNode;
			}
			else if (node->right == NULL)
			{
				MapBSTNode<K, V>* leftNode = node->left;
				delete node;
				m_size--;
				return leftNode;
			}
			else
			{
				MapBSTNode<K, V>* minNode = node->right;
				for (; minNode->left; minNode = minNode->left);
				node->m_key = minNode->m_key;
				node->right = remove(node->right, minNode->m_key);
				return node;
			}
		}
		return node;
	}

	bool contains(MapBSTNode<K, V>* node, K key)
	{
		if (node == NULL) 
		{
			return false;
		}
		if (key == node->m_key) 
		{
			return true;
		}
		else if (key < node->m_key) 
		{
			return contains(node->left, key);
		}
		else 
		{
			return contains(node->right, key);
		}
	}
};
