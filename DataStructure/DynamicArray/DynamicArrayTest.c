#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

//	��������
struct Letter
{
	char key[64];
	int value;
};

//	��ӡ�Զ�����������
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

	printf("��������ǰ����ʼ������5���� ������%d  ��С��%d\n\n", array->m_capacity, array->m_size);

	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 1, &p2);
	insert_DynamicArray(array, 2, &p3);
	insert_DynamicArray(array, 3, &p4);
	insert_DynamicArray(array, 4, &p5);
	foreach_DynamicArray(array, myPrint);
	printf("��һ�β������ݺ� ������%d  ��С��%d\n\n", array->m_capacity, array->m_size);

	insert_DynamicArray(array, 0, &p6);
	foreach_DynamicArray(array, myPrint);
	printf("�ڶ��β������ݺ󣨳���ԭ������ͷ�����룩�� ������%d  ��С��%d\n\n", array->m_capacity, array->m_size);
	removeByPos_DynamicArray(array, 3);
	foreach_DynamicArray(array, myPrint);
	printf("��λ���Ƴ����ݺ�Pos = 3(C)���� ������%d  ��С��%d\n\n", array->m_capacity, array->m_size);

	removeByValue_DynamicArray(array, &p2, myCompare);
	foreach_DynamicArray(array, myPrint);
	printf("��ֵ�Ƴ����ݺ�Value = p2(B)���� ������%d  ��С��%d\n\n", array->m_capacity, array->m_size);

	system("pause");
	return EXIT_SUCCESS;
}

