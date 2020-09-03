#include "myArray.h"

void test_myArray()
{
	myArray arr1;

	for (int i = 0; i < 10; i++)
	{
		arr1.pushback(i);
	}

	for (int i = 0; i < arr1.getSize(); i++)
	{
		cout << arr1.getData(i) << " ";
	}
	cout << endl;

	myArray arr2(15);

	for (int i = 0; i < arr2.getCapacity(); i++)
	{
		arr2.setData(i, i);
		cout << arr2.getData(i) << " ";
	}
	cout << endl;

	myArray arr3(arr2);

	for (int i = 0; i < arr3.getCapacity(); i++)
	{
		cout << arr2.getData(i) << " ";
	}
	cout << endl;

	arr3.setData(0, 1000);
	cout << "setData(0, 1000)£º" << arr3.getData(0) << endl;

	arr3[1] = 100;
	cout << "arr3[1] = " << arr3[1] << endl;

}

int main()
{
	test_myArray();

	system("pause");
	return 0;
}