/* 
只有非静态成员变量，处于类对象。

vs查看对其：
	#pragma pack(show)
*/

class Person1{};

void test1()
{
	Person1 p1;
	cout << sizeof(p1) << endl;//分配1个字节，区分空对象在内存上独一无二的地址。
}


class Person2
{
	int m_Age;
};

void test2()
{
	Person2 p2;
	cout << sizeof(p2) << endl;//分配4个字节。
}


class Person3
{
	int m_Age;
	void func(){}
	static int m_B;
};

void test3()
{
	Person3 p3;
	cout << sizeof(p3) << endl;//分配4个字节。 函数及静态变量均不在其中。
}