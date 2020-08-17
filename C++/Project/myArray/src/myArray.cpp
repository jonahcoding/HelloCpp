#include "myArray.h"

myArray::myArray()
{
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
	cout << "Ĭ�Ϲ��캯����" << endl;
}

myArray::myArray(int capacity)
{
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
	cout << "�вι��캯����" << endl;
}

myArray::myArray(const myArray& arr)
{
	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->pAddress = new int[arr.m_Capacity];//���

	for (int i = 0; i < arr.m_Capacity; i++)
	{
		this->pAddress[i] = arr.pAddress[i];
	}
	cout << "�������캯����" << endl;
}

void myArray::pushback(int val)
{
	this->pAddress[this->m_Size] = val;
	this->m_Size++;
}

void myArray::setData(int pos, int val)
{
	this->pAddress[pos] = val;
	this->m_Size++;
}

int myArray::getData(int pos)
{
	return this->pAddress[pos];
}

int myArray::getCapacity()
{
	return this->m_Capacity;
}

int myArray::getSize()
{
	return this->m_Size;
}

myArray::~myArray()
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
		cout << "����������" << endl;
	}
}