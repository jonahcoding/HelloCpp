#pragma once

#include <iostream>
using namespace std;

const int initialLen = 10;


template<class T>
class Array
{
private:
	T *m_data;		//��������
	int m_size;		//�����С
	int m_capacity; //��������

public:
	Array(int len = initialLen);

	void resize(int len);		//��̬����

	void add(int index, T num); //���Ԫ��

	void addFirst(T num);		//�����ͷ��

	void addLast(T num);		//�����β��

	T remove(int index);		//�Ƴ�Ԫ��

	T removeFirst();			//�Ƴ���Ԫ��

	T removeLast();				//�Ƴ�βԪ��

	void removeElement(T num);	//�Ƴ���һ��ָ������

	void set(int index, T num);	//��������

	T get(int index);			//��ȡ����

	int find(T num);			//��ȡ��������

	bool contains(T num);		//�Ƿ����ָ������

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
		cout << "���λ�÷Ƿ�" << endl;
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
		cout << "ɾ��λ�÷Ƿ���" << endl;
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
		cout << "ɾ��λ�÷Ƿ���" << endl;
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
		cout << "�޸�λ�÷Ƿ���" << endl;
		throw 0;
	}
	m_data[index] = num;
}

template<class T>
inline T Array<T>::get(int index)
{
	if (index < 0 || index >= m_size)
	{
		cout << "Խ����ʣ�" << endl;
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
