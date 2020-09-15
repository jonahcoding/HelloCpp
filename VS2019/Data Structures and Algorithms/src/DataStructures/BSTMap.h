#pragma once

#include "Map.h"
#include "MapBST.h"

template<class K, class V>
class BSTMap : public Map<K, V>
{
public:
	void add(K key, V value) { bst.add(key, value); }
	V remove(K key) { return bst.remove(key); }
	void set(K key, V value) { bst.set(key, value); }
	V get(K key) { return bst.get(key); }
	int size() { return bst.size(); }
	bool isEmpty() { return bst.isEmpty(); }
	bool contains(K key) { return bst.contains(key); }
private:
	MapBST<K, V> bst;
};

