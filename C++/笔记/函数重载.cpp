/*
---------------------------------------------
函数重载条件：
	在同一个作用域。
	函数名称相同。
	函数参数个数、类型、顺序不同。

const 引用可作为重载条件。
函数返回值不能作为函数重载的条件。

避免二义性。

---------------------------------------------
*/

//引用可作为重载条件。
void func(int &a)
{
	cout << "void func(int &a)" << endl;
}

void func(const int &a)
{
	cout << "void func(const int &a)" << endl;
}

int a =10;

func(a);//调用func(int &a)
func(10);//调用func(const int &a)

const int &a = 10;
//想等于：
int temp = 10;
int * const a = &temp;

//此时不能定义 void func(int a){} 
//避免二义性。

//函数重载与默认参数。（存在二义性）
void func(int a, int b = 10);//应取消参数默认值，void func(int a, int b);
void func(int a);


/*
---------------------------------------------
重载实现原理：对函数名称进行修饰
---------------------------------------------
*/