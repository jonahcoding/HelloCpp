#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Person
{
public:
	static int m_A;
	static void func()
	{
		m_A = 100;//静态成员方法只能访问静态成员变量。
		std::cout << m_A << std::endl;
	}
};

int Person::m_A = 0;

void test_Static()
{
	//1.通过对象调用
	Person p1;
	std::cout << p1.m_A << std::endl;
	p1.func();

	//2.通过类名调用
	std::cout << Person::m_A << std::endl;
	Person::func();
}

int main()
{
	test_Static();

	system("pause");
	return 0;
}