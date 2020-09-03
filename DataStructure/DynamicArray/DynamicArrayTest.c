#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

//	测试数据
struct Letter
{
	char key[64];
	int value;
};

//	打印自定义数据类型
void myPrint(void * data)
{
	struct Letter *p = data;
	printf("Key:%s  Value:%d\n", p->key, p->value);
}

int myCompare(void * data1, void * data2)
{
	struct Letter * p1 = data1;
	struct Letter * p2 = data2;

	return strcmp(p1->key, p2->key) == 0 && p1->value == p2->value;
}


int main()
{
	struct dynamicArray * array = init_DynamicArray(5);

	struct Letter p1 = { "A", 1 };
	struct Letter p2 = { "B", 2 };
	struct Letter p3 = { "C", 3 };
	struct Letter p4 = { "D", 4 };
	struct Letter p5 = { "E", 5 };
	struct Letter p6 = { "F", 6 };

	printf("插入数据前（初始容量：5）： 容量：%d  大小：%d\n\n", array->m_capacity, array->m_size);

	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 1, &p2);
	insert_DynamicArray(array, 2, &p3);
	insert_DynamicArray(array, 3, &p4);
	insert_DynamicArray(array, 4, &p5);
	foreach_DynamicArray(array, myPrint);
	printf("第一次插入数据后： 容量：%d  大小：%d\n\n", array->m_capacity, array->m_size);

	insert_DynamicArray(array, 0, &p6);
	foreach_DynamicArray(array, myPrint);
	printf("第二次插入数据后（超出原容量，头部插入）： 容量：%d  大小：%d\n\n", array->m_capacity, array->m_size);
	removeByPos_DynamicArray(array, 3);
	foreach_DynamicArray(array, myPrint);
	printf("按位置移除数据后（Pos = 3(C)）： 容量：%d  大小：%d\n\n", array->m_capacity, array->m_size);

	removeByValue_DynamicArray(array, &p2, myCompare);
	foreach_DynamicArray(array, myPrint);
	printf("按值移除数据后（Value = p2(B)）： 容量：%d  大小：%d\n\n", array->m_capacity, array->m_size);

	system("pause");
	return EXIT_SUCCESS;
}

