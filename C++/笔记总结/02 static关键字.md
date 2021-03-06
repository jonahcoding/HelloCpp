本节内容
 - [x] 静态局部变量
 - [x] 静态全局变量
 - [x] 静态方法
 - [x] 静态成员变量（C++）
 - [x] 静态成员函数（C++）

# 一、static在C语言中的使用

**非多文件共享变量或方法，应声明为静态全局变量或静态方法，避免重名冲突！**

**静态局部变量：解耦合，使程序模块化！**

小贴士：
> C++标准：全局或静态对象首次用到时才进行构造，即初始化。
> C：全局或静态变量在编译时初始化。

## 1.1 静态局部变量

静态局部变量：被static修饰的局部变量。
>作用域：函数体或代码块
>生命周期：离开作用域（函数体或代码块）后仍然驻留在内存中，不会销毁，直至程序结束。

**示例程序**：

```cpp
#include <iostream>

void static_Test()
{
	static int staticLocalVar = 0;	//静态局部变量：staticLocalVar
	std::cout << "staticLocalVar = " << staticLocalVar++ << std::endl;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		static_Test();
	}

	return 0;
}
```

执行结果：

![](./Image/static_01.png)

如图，重新调用函数时，静态局部变量staticLocalVar会保持函数上次运行结束时的值。

## 1.2 静态全局变量

静态全局变量：被static修饰的全局变量，限定作用域为当前文件，同时避免多文件命名冲突。
> 作用域：当前文件。
> 生命周期：首次使用至程序结束。

以下示例将对全局变量与静态全局变量进行对比。

**示例1（全局变量）**：

```cpp
//file static_02.cpp
int globalVar = 10; //全局变量

//file static_01.cpp
#include <iostream>

void static_Test()
{
	extern int globalVar; //使用extern声明全局变量globalVar
	std::cout << "globalVar = " << globalVar << std::endl;
}

int main()
{
	static_Test();
	return 0;
}
```

执行结果：

![](./Image/static_02.png)

**示例2（静态全局变量）**：

```cpp
//file static_02.cpp
static int globalVar = 10; //全局变量

//file static_01.cpp
#include <iostream>

void static_Test()
{
	extern int staticGlobalVar; //使用extern声明静态全局变量globalVar
	std::cout << "staticGlobalVar = " << staticGlobalVar << std::endl;
}

int main()
{
	static_Test();
	return 0;
}
```

执行未成功：

![](./Image/static_03.png)

## 1.3 静态方法

静态方法：被static修饰的方法（函数），限定该函数作用域，同时避免多文件命名冲突。

> 作用域：当前文件

以下示例将对静态方法与普通方法进行对比。

**示例1（普通方法）**：

```cpp
//file static_02.cpp
#include <iostream>

void func()
{
	std::cout << "非静态方法，可以跨文件调用！" << std::endl;
}

//file static_01.cpp
#include <iostream>

void static_Test()
{
	extern void func();
    func();
}

int main()
{
	static_Test();
	return 0;
}
```

执行结果：

![](./Image/static_04.png)

**示例2（静态方法）**：

```cpp
//file static_02.cpp
#include <iostream>

void static staticFunc()
{
	std::cout << "静态方法，无法跨文件调用！" << std::endl;
}

//file static_01.cpp
#include <iostream>

void static_Test()
{
	extern void staticFunc();
    staticFunc();
}

int main()
{
	static_Test();
	return 0;
}
```

执行未成功：

![](./Image/static_05.png)

# 二、static在C++中的扩展

**静态成员变量**：被static修饰的类的成员变量。

**静态成员方法**：被static修饰的类的成员方法。

## 2.1 静态成员变量/静态成员方法的特点

1. 静态成员变量在编译阶段已分配好内存（ 全局/静态存储区 ）。
2. [静态成员变量在类内声明，在类外初始化。](http://www.cppblog.com/elva/archive/2010/05/06/114577.html)
3. 类的所有对象（包括衍生类的对象）共享一份静态成员变量/方法。
4. 静态成员函数不包含this指针，只能调用静态成员变量。
5. 私有静态成员函数/方法只能间接通过类的实例的公有方法访问。

## 2.2 静态成员变量/静态成员方法的访问（使用）

- 通过类名调用。
- 通过对象调用。

**代码示例：**

```cpp
#include <iostream>

class Person
{
public:
	static int m_A;		//静态成员变量（类内声明）
	static void func()	//静态成员方法
	{
		m_A = 100;		//静态成员方法只能访问静态成员变量。
		std::cout << m_A << std::endl;
	}
};

int Person::m_A = 0;	//静态成员变量（类外初始化）

void test_Static()
{
	//1.通过对象调用
	Person p1;
	std::cout << p1.m_A << std::endl;		//0
	p1.func();								//100

	//2.通过类名调用
	std::cout << Person::m_A << std::endl;	//100
	Person::func();							//100
}

int main()
{
	test_Static();

	system("pause");
	return 0;
}
```

执行结果：

![](./Image/static_06.png)

