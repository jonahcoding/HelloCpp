//【malloc】
class Person
{
public:
	inr mAge;
	char * pName;

	Person()
	{
		mAge = 20;
		pName = (char*)malloc(strlen("Jonah")+1);
		strcpy(pName, "Jonah");
	}

}

//分配内存
Person* person = (Person*)malloc(sizeof(Person));
if(person == NULL)
{
	return 0;
}

/* 
【malloc缺陷】
	1.程序员必须确定对象长度。
	2.malloc返回void*，C++中不允许将void*赋值给其他类型指针，必须强转。
	3.malloc可能申请内存失败，需要通过返回值判断是否申请成功。
	4.用户在使用对象前必须对其初始化，构造函数不能显式调用初始化（用户可能忘记调用初始化函数）。
*/


//【new/delete】
class Person
{
public:

	Person()
	{
		cout << "构造函数" << endl;
	}

	~Person()
	{
		cout << "析构函数" << endl;
	}
}

void test()//手动申请，手动释放
{
	Person *p = new Person;
	delete p;
}


/*
new和malloc区别：
	1.malloc和free属于库函数；new和delete属于运算符。
	2.malloc不会调用构造函数；new会调用构造函数。
	3.malloc返回void*，C++下要强制转换；new返回创建的对象的指针。
*/

/*
注意：
	不要用void*接受new出的对象。
	原因：无法释放（无法调用析构）。
*/

/*
利用new开辟数组：
	int *pInt = new int[10];
	double *pD = new double[10];
*/
Person *p = new Person[10];//堆区开辟数组，一定会调用默认构造函数（确保默认构造函数可用）
delete [] Person;// 释放数组必须加[]：确保释放掉所有，而非第一个

Person pArray[10] = {Person(10), Person(20), Person(30)};//栈上开辟数组，可以没有默认构造函数
