/*
==================================================
数组（一维）：
--------------------------------------------------
功能：
	有参构造
	拷贝构造
	析构函数
	[]运算符重载
	正号运算符重载
	负号运算符重载
	加号运算符重载
	减号运算符重载
	赋值运算符重载
	乘号运算符重载
	+=运算符重载
--------------------------------------------------
==================================================
*/

#pragma
#include <iostream>
#include "all_error.h"
using namespace std;

template<class T>
class Array1D
{
private:
	int size;
	T *element;
public:
	Array1D(int init_size = 0); //有参构造
	Array1D(const Array1D<T> & v); //复制构造函数
	~Array1D() { delete[] element; } //析构函数

	T & operator[] (int i) const; //[]运算符重载
	int GetSize() { return size; }; //获取数组大小
	Array1D<T>  operator +() const;//一元加法
	Array1D<T>  operator -() const;//一元减法
	Array1D<T> operator+(const Array1D<T> & v) const;
	Array1D<T> operator-(const Array1D<T> & v) const;
	Array1D<T> & operator = (const Array1D<T> & v);
	Array1D<T> operator*(const Array1D<T> & v) const;
	Array1D<T> & operator+=(const T & x);

	void PrintArray1D();
};

// 有参构造
template<class T>
Array1D<T>::Array1D(int init_size)
{
	if (init_size <= 0)
	{
		throw OutOfBounds();
	}
	size = init_size;
	element = new T[size];
}

// 拷贝构造
template<class T>
Array1D<T>::Array1D(const Array1D<T> & v)
{
	size = v.size;
	element = new T[size];
	for (int i = 0; i < size; i++)
	{
		element[i] = v.element[i];
	}
}

// []操作符重载
template<class T>
inline T & Array1D<T>::operator[] (int i) const
{
	if (i < 0 || i >= size)
	{
		throw OutOfBounds();
	}
	return element[i];
}

// 一元+运算符重载
template<class T>
inline Array1D<T> Array1D<T>::operator+() const
{
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
	{
		w.element[i] = element[i];
	}
	return w;
}

// 一元-运算符重载
template<class T>
inline Array1D<T> Array1D<T>::operator-() const
{
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
	{
		w.element[i] = -element[i];
	}
	return w;
}

//加号运算符重载
template<class T>
inline Array1D<T> Array1D<T>::operator+(const Array1D<T>& v) const
{
	if (size != v.size)
	{
		throw OutOfBounds();
	}

	Array1D<T> w(size);

	for (int i = 0; i < size; i++)
	{
		w.element[i] = element[i] + v.element[i];
	}

	return w;
}

//减号运算符重载
template<class T>
inline Array1D<T> Array1D<T>::operator-(const Array1D<T>& v) const
{
	if (size != v.size)
	{
		throw OutOfBounds();
	}

	Array1D<T> w(size);

	for (int i = 0; i < size; i++)
	{
		w.element[i] = element[i] - v.element[i];
	}

	return w;
}

//赋值运算符重载
template<class T>
inline Array1D<T>& Array1D<T>::operator=(const Array1D<T>& v)
{
	if (this == &v)
	{
		return *this;
	}
	size = v.size;
	delete[] element;
	element = new T[size];
	for (int i = 0; i < size; i++)
	{
		element[i] = v.element[i];
	}
	return *this;
}

//乘号运算符重载
template<class T>
inline Array1D<T> Array1D<T>::operator*(const Array1D<T>& v) const
{
	if (size != v.size)
	{
		throw OutOfBounds();
	}

	Array1D<T> w(size);

	for (int i = 0; i < size; i++)
	{
		w.element[i] = element[i] * v.element[i];
	}

	return w;
}

//+=运算符重载
template<class T>
inline Array1D<T>& Array1D<T>::operator+=(const T & x)
{
	for (int i = 0; i < size; i++)
	{
		element[i] += x;
	}
	return *this;
}

template<class T>
inline void Array1D<T>::PrintArray1D()
{
	for (int i = 0; i < size; i++)
	{
		cout << element[i] << "\t";
	}
	cout << endl;
}
