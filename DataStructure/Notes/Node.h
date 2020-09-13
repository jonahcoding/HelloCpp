#pragma once

#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T m_data;
	Node* next;

	Node(T num = NULL, Node* next = NULL)
	{
		m_data = num;
		this->next = next;
	}
};

