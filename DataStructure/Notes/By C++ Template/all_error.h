#pragma once

#include <iostream>
using namespace std;

class NoMemory
{
public:
	NoMemory()
	{
		cout << "No Memory!" << endl;
		exit(0);
	}

};

void my_new_handler()
{
	throw NoMemory();
}

new_handler Old_Handler_ = set_new_handler(my_new_handler);

class OutOfBounds
{
public:
	OutOfBounds()
	{
		cout << "Out Of Range!" << endl;
		exit(0);
	}
};


