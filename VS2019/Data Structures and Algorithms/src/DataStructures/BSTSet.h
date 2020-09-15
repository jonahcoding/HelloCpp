#pragma once

#include "Set.h"
#include "BST.h"

template<class T>
class BSTSet : public Set<T>
{
public:
	int size() { return bst.size(); }
	bool isEmpty() { return bst.isEmpty(); }
	void add(T num) { bst.add(num); }
	void remove(T num) { bst.remove(num); }
	bool contains(T num) { return bst.contains(num); }

private:
	BST<T> bst;
};

