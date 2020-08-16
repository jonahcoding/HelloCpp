/*
---------------------------------------------
externC：extern "C" void show()
告知编译器用C的方式对show()进行链接。（在Cpp文件中，不写头文件）


第二种：对c的头文件进行修改，在c++中调用c文件
原因：c++存在重载，对函数名称进行修饰，无法找到c函数（C中不修饰函数名称）

---------------------------------------------
*/

//【条件编译】C++中使用C代码
#ifdef __cplusplus
extern "C" {
#endif

	/*add somethings*/


#ifdef __cplusplus
}
#endif