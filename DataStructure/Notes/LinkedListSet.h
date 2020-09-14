#pragma once

#include "Set.h"
#include "LinkedList.h"

template<class T>
class LinkedListSet : public Set<T>
{
public:
	int size() { return llist.size(); }
	bool isEmpty() { return llist.isEmpty(); }
	void add(T num) 
	{
		if (!llist.contains(num))
		{
			llist.addFirst(num);
		}
	}
	void remove(T num) 
	{
		while (llist.contains(num))
		{
			llist.removeElement(num);
		}
	}
	bool contains(T num) { return llist.contains(num); }

private:
	LinkedList<int> llist;
};
