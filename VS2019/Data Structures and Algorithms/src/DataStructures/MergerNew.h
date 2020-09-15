#pragma once

#include "Merger.h"

//Customize the relationship between the parent node and the left and right child nodes.
template<class T>
class MergerNew : public Merger<T>
{
public:
	T merger(T a, T b)
	{
		return a + b;
	}

};
