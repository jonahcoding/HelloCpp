#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
��ģ���г�Ա�����Ĵ���ʱ����
	���н׶�ȷ��T�����ͺ��ٴ�����Ա������

--------------------------------------------------
*/

class Hero1
{
public:
	void showHero()
	{
		cout << "I'm Hero1." << endl;
	}

};

class Hero2
{
public:
	void showHero()
	{
		cout << "I'm Hero2." << endl;
	}

};

template<class T>
class Hero
{
public:
	void func()
	{
		obj.showHero();
	}

	T obj;
};

void test()
{
	Hero <Hero1> h1;
	h1.func();

}

int main()
{
	test();

	system("pause");
	return 0;
}