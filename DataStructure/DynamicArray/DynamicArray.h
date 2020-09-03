#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *	结构体：动态数组
 *  成员pAddr：指向堆区动态数组元素的指针（数组元素初始为void*类型）。
 *	成员m_capacity：动态数组容量。
 *	成员m_size：动态数组大小。
 */
struct dynamicArray {
	void** pAddr;
	int m_capacity;
	int m_size;
};

//初始化动态数组
struct dynamicArray*  init_DynamicArray(int capacity);
//插入元素
void insert_DynamicArray(struct dynamicArray * array, int pos, void * data);
//遍历动态数组
void foreach_DynamicArray(struct dynamicArray * array, void(*myPrint)(void *));
//按位置移除元素
void removeByPos_DynamicArray(struct dynamicArray * array, int pos);
//按值移除元素
void removeByValue_DynamicArray(struct dynamicArray * array, void * data, int(*myCompare)(void *, void *));
//销毁动态数组
void destory_DynamicArray(struct dynamicArray * array);