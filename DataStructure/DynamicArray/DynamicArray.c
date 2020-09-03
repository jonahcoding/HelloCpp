#include "DynamicArray.h"
/*
 *功能：初始化动态数组
 *参数capacity：动态数组容量初始值。
 */
struct dynamicArray*  init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray* array = malloc(sizeof(struct dynamicArray));
	if (array == NULL)
	{
		return NULL;
	}

	array->pAddr = malloc(sizeof(void *) * capacity);
	array->m_capacity = capacity;
	array->m_size = 0;

	return array;
}

/*
 *功能：动态数组插入元素
 */
void insert_DynamicArray(struct dynamicArray * array, int pos, void* data)
{
	if (array == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	if (pos < 0 || pos > array->m_size)
	{
		pos = array->m_size;
	}

	if (array->m_size == array->m_capacity)
	{
		int newCapacity = array->m_capacity * 2;
		void ** newSpace = malloc(sizeof(void *) * newCapacity);
		memcpy(newSpace, array->pAddr, sizeof(void *) * array->m_capacity);
		free(array->pAddr);
		array->pAddr = newSpace;
		array->m_capacity = newCapacity;
	}

	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	array->pAddr[pos] = data;
	array->m_size++;
}

/*
 *功能：遍历动态数组
 */
void foreach_DynamicArray(struct dynamicArray * array, void(*myPrint)(void *))
{
	if (array == NULL)
	{
		return;
	}

	if (myPrint == NULL)
	{
		return;
	}

	for (int i = 0; i < array->m_size; i++)
	{
		myPrint(array->pAddr[i]);
	}
}

/*
 *功能：按位置删除元素
 */
void removeByPos_DynamicArray(struct dynamicArray * array, int pos)
{
	if (array == NULL)
	{
		return;
	}

	if (pos < 0 || pos > array->m_capacity)
	{
		pos = array->m_capacity;
	}

	for (int i = pos; i < array->m_size; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}

	array->m_size--;
}

/*
 *功能：按值删除元素
 */
void removeByValue_DynamicArray(struct dynamicArray * array, void * data, int(*myCompare)(void *, void *))
{
	if (array == NULL)
	{
		return;
	}
	
	for (int i = 0; i < array->m_size;i++)
	{
		if (myCompare(array->pAddr[i], data))
		{
			removeByPos_DynamicArray(array, i);
			break;
		}
	}
}

/*
 *功能：销毁动态数组
 */
void destory_DynamicArray(struct dynamicArray * array)
{
	if (array == NULL)
	{
		return;
	}

	if (array->pAddr != NULL)
	{
		free(array->pAddr);
		array->pAddr = NULL;
	}

	free(array);
	array = NULL;
}

