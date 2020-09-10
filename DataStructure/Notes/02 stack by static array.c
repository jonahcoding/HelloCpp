#include "02 stack by static array.h"

#define STACK_SIZE 5

static STACK_TYPE stack[STACK_SIZE];

static int top_element = -1;

//入栈
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element++;
	stack[top_element] = value;
}

//出栈
void pop(void)
{
	assert(!is_empty());
	top_element--;
}

//获取栈顶元素
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

//判断栈空
int is_empty(void)
{
	return top_element == -1;
}

//判断栈满
int is_full(void)
{
	return top_element == (STACK_SIZE - 1);
}

