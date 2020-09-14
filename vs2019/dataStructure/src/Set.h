#pragma once

template<class T>
class Set
{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void add(T num) = 0;
	virtual void remove(T num) = 0;
	virtual bool contains(T num) = 0;
};
