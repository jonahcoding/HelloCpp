#pragma once
template<class T>
class Stack
{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	virtual void push(T num) = 0;
	virtual void pop() = 0;
	virtual T peek() = 0;
};
