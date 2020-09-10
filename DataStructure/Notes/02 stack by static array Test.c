﻿/*
==================================================
【静态数组实现栈】
--------------------------------------------------
默认容量（宏定义）：5
数据类型（宏定义）：int

方法：
	入栈：push()
	出栈：pop()
	返回栈顶元素：top()
	判断栈空：is_empty()
	判断栈满：is_full()
--------------------------------------------------
==================================================
*/

#include <stdio.h>
#include "02 stack by static array.h"

int main()
{
	if(is_empty())
	{
		printf("栈空\n");
	}
	push(1);
	push(2);
	push(3);
	push(4);
	printf("栈顶元素：%d\n", top());
	
	push(5);
	printf("栈顶元素：%d\n", top());

	if(is_full())
	{
		printf("栈满\n");
	}
	pop();
	printf("栈顶元素：%d\n", top());
	
	system("pause");
	return 0;
}