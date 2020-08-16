/* 
【静态成员变量、函数】仅一份。
*/

class Person
{
public:
	//静态成员变量，编译阶段就分配了内存。
	//类内声明，类外初始化。
	//所有对象共享一份数据。
	static int m_A;

	//所有对象共享一份
	static void func() // 静态成员函数只能调用静态成员变量。非静态成员变量无法区分属于哪个对象。
	{
		m_A = 100;
		cout << m_A << endl;
	}

}

int Person::m_A = 0;

void test()
{
	//1.使用对象访问。
	Person p1;
	cout << p1.m_A << endl;

	p1.func();


	//2.通过类名访问。
	cout << Person::m_A <<endl;
	Person::func();
	//静态成员变量\函数 有访问权限，私有权限无法被访问。
}


