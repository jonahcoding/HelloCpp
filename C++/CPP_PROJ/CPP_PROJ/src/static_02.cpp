#include <iostream>

void static staticFunc()
{
	std::cout << "静态方法，无法跨文件调用！" << std::endl;
}