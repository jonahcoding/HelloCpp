#pragma once

#include <iostream>
using namespace std;

const int initialLen = 10;


template<class T>
class Array
{
private:
	T *m_data;		//数组数据
	int m_size;		//数组大小
	int m_capacity; //数组容量

public:
	Array(int len = initialLen);

	void resize(int len);		//动态容量

	void add(int index, T num); //添加元素

	void addFirst(T num);		//添加至头部

	void addLast(T num);		//添加至尾部

	T remove(int index);		//移除元素

	T removeFirst();			//移除首元素

	T removeLast();				//移除尾元素

	void removeElement(T num);	//移除第一个指定数据

	void set(int index, T num);	//设置数据

	T get(int index);			//获取数据

	int find(T num);			//获取数据索引

	bool contains(T num);		//是否包含指定数据

	int capacity();

	int size();

	bool isEmpty();

	void print();
};

template<class T>
inline Array<T>::Array(int len)
{
	T* p = new T[len];
	m_data = p;
	m_capacity = len;
	m_size = 0;
}

template<class T>
inline void Array<T>::resize(int len)
{
	T* p = new T[len];
	for (int i = 0; i < m_size; i++)
	{
		p[i] = m_data[i];
	}
	delete[] m_data;
	m_data = p;
	m_capacity = len;
}

template<class T>
inline void Array<T>::add(int index, T num)
{
	if (index < 0 || index > m_size)
	{
		cout << "添加位置非法" << endl;
		throw 0;
	}
	if (m_size >= m_capacity)
	{
		resize(m_capacity * 2);
	}
	for (int i = m_size; i > index; i--)
	{
		m_data[i] = m_data[i - 1];
	}
	m_data[index] = num;
	m_size++;
}

template<class T>
inline void Array<T>::addFirst(T num)
{
	add(0, num);
}

template<class T>
inline void Array<T>::addLast(T num)
{
	if (m_size >= m_capacity)
	{
		resize(m_capacity * 2);
	}
	m_data[m_size] = num;
	m_size++;
}

template<class T>
inline T Array<T>::remove(int index)
{
	if (index < 0 || index >= m_size)
	{
		cout << "删除位置非法！" << endl;
		throw 0;
	}
	T res = m_data[index];
	m_size--;
	for (int i = index; i < m_size; i++)
	{
		m_data[i] = m_data[i + 1];
	}
	if (m_size < m_capacity / 4)
	{
		resize(m_capacity / 2);
	}
	return res;
}

template<class T>
inline T Array<T>::removeFirst()
{
	T res = m_data[0];
	remove(0);
	return res;
}

template<class T>
inline T Array<T>::removeLast()
{
	if (m_size == 0)
	{
		cout << "删除位置非法！" << endl;
		throw 0;
	}
	m_size--;
	if (m_size < m_capacity / 4)
	{
		resize(m_capacity / 2);
	}
	return m_data[m_size];
}

template<class T>
inline void Array<T>::removeElement(T num)
{
	int flag = find(num);
	if (flag != -1)
	{
		remove(flag);
	}
}

template<class T>
inline void Array<T>::set(int index, T num)
{
	if (index < 0 || index >= m_size)
	{
		cout << "修改位置非法！" << endl;
		throw 0;
	}
	m_data[index] = num;
}

template<class T>
inline T Array<T>::get(int index)
{
	if (index < 0 || index >= m_size)
	{
		cout << "越界访问！" << endl;
		throw 0;
	}

	return m_data[index];
}

template<class T>
inline int Array<T>::find(T num)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == num)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
inline bool Array<T>::contains(T num)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == num)
		{
			return true;
		}
	}
	return false;
}

template<class T>
inline int Array<T>::capacity()
{
	return m_capacity;
}

template<class T>
inline int Array<T>::size()
{
	return m_size;
}

template<class T>
inline bool Array<T>::isEmpty()
{
	return m_size == 0;
}

template<class T>
inline void Array<T>::print()
{
	cout << "[Array]    ";
	cout << "Capacity = " << m_capacity << "    Size = " << m_size << endl;
	cout << "[";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i];
		if (i != m_size - 1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}
