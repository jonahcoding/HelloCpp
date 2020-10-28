#pragma once

#include <iostream>
using namespace std;

template<class T>
class BTNode
{
public:
	T m_data;
	BTNode<T> *left;
	BTNode<T> *right;

	BTNode(T num, BTNode<T> *left = NULL, BTNode<T> *right = NULL)
	{
		m_data = num;
		this->left = left;
		this->right = right;
	}
};