#pragma once

template<class T>
class Queue
{
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;

	virtual void enqueue(T num) = 0;
	virtual void dequeue() = 0;
	virtual T front() = 0;
};

