#pragma once

#include <iostream>
#include "all_error.h"

using namespace std;

template<class T>
class Stack
{
private:
	int size;//栈元素个数
	int top;//栈顶
	int MaxTop;//最大的栈顶值
	T *stack;//堆栈元素数组
public:
	Stack(int MaxStackSize = 5);//有参构造
	~Stack() { delete[] stack; }//析构函数
	bool IsEmpty() const { return top == -1; }//判断栈空
	bool IsFull() const { return top == MaxTop; }//判断栈满
	int Length() { return top + 1; }//获取长度
	T Top() const;//获取栈顶数据
	void Push(const T& x);//入栈
	T Pop();//出栈
};

template<class T>
inline Stack<T>::Stack(int MaxStackSize)
{
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}

template<class T>
inline T Stack<T>::Top() const
{
	if (IsEmpty())
	{
		throw OutOfBounds();
	}
	return stack[top];
}

template<class T>
inline void Stack<T>::Push(const T & x)
{
	if (IsFull())
	{
		throw NoMemory();
	}
	stack[++top] = x;
}

template<class T>
inline T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		throw OutOfBounds();
	}
	return stack[top--];
}
