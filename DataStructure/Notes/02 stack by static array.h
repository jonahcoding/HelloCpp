#ifndef STACK_BY_STATIC_ARRAY_H
#define STACK_BY_STATIC_ARRAY_H

#define STACK_TYPE int

#include <stdio.h>
#include <assert.h>

//入栈
void push(STACK_TYPE value);

//出栈
void pop(void);

//获取栈顶元素
STACK_TYPE top(void);

//判断栈空
int is_empty(void);

//判断栈满
int is_full(void);

#endif