#pragma once
#include "array.h"

void test_Array()
{
	int init_size = 5;

	cout << "==========================" << endl;
	cout << "=======Array1D Test=======" << endl;
	cout << "==========================" << endl;

	cout << "==>Parameterized constructor" << endl;
	cout << "==>Expression: a1(5)" << endl;
	Array1D<int> a1(init_size);
	for (int i = 0; i < init_size; i++)
	{
		a1[i] = i;
	}
	cout << endl;

	cout << "==>Copy constructor" << endl;
	cout << "==>Expression: a2(a1)" << endl;
	Array1D<int> a2(a1);
	cout << endl;

	cout << "==>Unary operator[] overload" << endl;
	cout << "==>Expression: print a2[]" << endl;
	a2.PrintArray1D();

	cout << "==>unary +operator overload" << endl;
	cout << "==>expression: a3 = +a2" << endl;
	Array1D<int> a3 = +a2;
	a3.PrintArray1D();

	cout << "==>unary -operator overload" << endl;
	cout << "==>expression: a4 = -a3" << endl;
	Array1D<int> a4 = -a3;
	a4.PrintArray1D();

	cout << "==>unary operator+ overload" << endl;
	cout << "==>expression: a5 = a3 + a4" << endl;
	Array1D<int> a5 = a3 + a4;
	a5.PrintArray1D();

	cout << "==>unary operator- overload" << endl;
	cout << "==>expression: a6 = a3 - a4" << endl;
	Array1D<int> a6 = a3 - a4;
	a6.PrintArray1D();

	cout << "==>unary operator= overload" << endl;
	cout << "==>expression: a7 = a6" << endl;
	Array1D<int> a7 = a6;
	a7.PrintArray1D();

	cout << "==>unary operator* overload" << endl;
	cout << "==>expression: a8 = a3 * a4" << endl;
	Array1D<int> a8 = a3 * a4;
	a8.PrintArray1D();

	cout << "==>unary operator+= overload" << endl;
	cout << "==>expression: a8 += 5" << endl;
	a8 += 5;
	a8.PrintArray1D();
	cout << "size: " << a8.GetSize() << endl;
}
