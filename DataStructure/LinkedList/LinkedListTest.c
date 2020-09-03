#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

//��������
struct Letter
{
	char key[64];
	int value;
};

//��ӡ�Զ�����������
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
	struct Letter p1 = { "A", 1 };
	struct Letter p2 = { "B", 2 };
	struct Letter p3 = { "C", 3 };
	struct Letter p4 = { "D", 4 };
	struct Letter p5 = { "E", 5 };
	struct Letter p6 = { "F", 6 };
	LinkList myList = init_LinkList();
	printf("������Ϊ��%d\n\n", size_LinkList(myList));

	//��������
	insert_LinkList(myList, 0, &p1);
	insert_LinkList(myList, 0, &p2);
	insert_LinkList(myList, -1, &p3);
	insert_LinkList(myList, 0, &p4);
	insert_LinkList(myList, 1, &p5);
	insert_LinkList(myList, 0, &p6);

	foreach_LinkList(myList, myPrint);
	printf("(����)������Ϊ��%d\n\n", size_LinkList(myList));


	removeByPos_LinkList(myList, 3);
	removeByValue_LinkList(myList, &p2, myCompare);
	foreach_LinkList(myList, myPrint);
	printf("(ɾ��)������Ϊ��%d\n\n", size_LinkList(myList));

	clear_LinkList(myList);
	foreach_LinkList(myList, myPrint);
	printf("(���)������Ϊ��%d\n\n", size_LinkList(myList));

	destory_LinkList(myList);
	foreach_LinkList(myList, myPrint);
	printf("(����)������Ϊ��%d\n\n", size_LinkList(myList));

	system("pause");
	return EXIT_SUCCESS;
}