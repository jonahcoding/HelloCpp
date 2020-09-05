#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
��ģ������Ԫ������
	1.��ģ����ʵ�֡�
	2.��ģ����ʵ�֣���󣩡�
	3.��ģ���ʵ�֣���ǰ����

--------------------------------------------------
*/

//��ģ������
template<class T1,class T2>
class Hero;

//������Ԫ������������������ģ��Hero��
template<class T1,class T2>
void printHero2(Hero<T1, T2> &p);

//��Ԫ����������ʵ�֣�������������ģ��Hero��
template<class T1,class T2>
void printHero3(Hero<T1, T2>&p)
{
	cout << "����ʵ�֣���ǰ�� --- Name�� " << p.m_Name << " Age�� " << p.m_Age << endl;
}

template<class T1, class T2>
class Hero
{
	//1.��ģ����ʵ�֡�
	friend void printHero(Hero<T1, T2> &p)
	{
		cout << "����ʵ�� --- Name�� " << p.m_Name << " Age�� " << p.m_Age << endl;
	}

	//2.��ģ����ʵ�֣���󣩡�
	friend void printHero2<>(Hero<T1, T2> &p);

	//3.��ģ���ʵ�֣���ǰ����
	friend void printHero3<>(Hero<T1, T2> &p);
public:
	Hero(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
void printHero2(Hero<T1, T2> &p)
{
	cout << "����ʵ�֣���� --- Name�� " << p.m_Name << " Age�� " << p.m_Age << endl;
}

void test()
{
	Hero <string, int> p("Teemo", 7);
	printHero(p);
	printHero2(p);
	printHero3(p);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}