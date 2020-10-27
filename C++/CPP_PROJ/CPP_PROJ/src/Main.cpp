#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person1
{
public:
	int mAge;
	char* pName;

	Person1()
	{
		mAge = 20;

		pName = (char*)malloc(strlen("Jonah") + 1);
		if (pName != NULL)
		{
			strcpy(pName, "Jonah");
			cout << "malloc" << endl;
		}
		else
		{
			cout << "ÉêÇëÄÚ´æÊ§°Ü£¡";
		}
	}
};

void test_malloc()
{
	//·ÖÅäÄÚ´æ
	Person1* person = (Person1*)malloc(sizeof(Person1));
	if (person == NULL) {}
	else {}
}







int main()
{
	test_malloc();

	system("pause");
	return 0;
}

