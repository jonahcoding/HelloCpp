/* 
	普通成员函数如何区分调用对象。
	this指针：指向被调用的成员函数所属的对象。（隐式的加在每个成员函数中）
	this类型：Person *
	作用：
		1.解决名称冲突。
		2.
*/

// 两者的区别：
// 1、A.B则A为对象或者结构体；
// 2、A->B则A为指针，->是成员提取，A->B是提取A中的成员B，A只能是指向类、结构、联合的指针；

class Person
{
public:
	Person(int age)
	{
		//用途1：解决名称冲突。
		//age = age;//如何区分形参与类成员。
		this->age = age;
	}

	bool Compare(Person& p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		return false;
	}

	Person& personAddPerson(Person&)
	{
		this->age += age;
		return *this;//*this是本体。（解引用）
	}

	int age;
};

void test()
{
	Person p1(10);
	Person p2(20);

	bool ret = p1.Compare(p2);
	if (ret)
	{
		cout << "相等" << endl;
	}

}
