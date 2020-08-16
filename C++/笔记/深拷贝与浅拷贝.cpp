/*
---------------------------------------------
默认拷贝构造为：浅拷贝，属性开辟在堆区，释放时发生错误（重复释放堆区内存）（共用一个地址）
深拷贝：自己提供拷贝构造函数，分别创立两个堆区内存（两个地址，互不影响）
---------------------------------------------
*/


class Person
{
public:
	char * m_Name;
	int m_Age;

	Person(char * name, int age)
	{
		m_Name = (char *)malloc(strlen(name)+1); //堆区
		strcpy(m_Name, name);
		m_Age = age;
	}

	Person(const Person &p)
	{
		m_Name = (char *)malloc(strlen(p.m_Name)+1); //堆区
		strcpy(m_Name, p.m_Name);
		m_Age = p.m_Age;
	}

	~Person()
	{
		if(m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}

} 


void test()
{
	Person p("Teemo", 7);
	cout << "姓名：" << p.m_Name << "， 年龄：" << p.m_Age << endl;

	Person p1(p);
	cout << "姓名：" << p1.m_Name << "， 年龄：" << p1.m_Age << endl;
}