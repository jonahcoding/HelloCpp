#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڵ�ṹ��
struct LinkNode
{
	//������
	void * data;
	//ָ����
	struct LinkNode * next;
};

//����ṹ��
struct LList
{
	//ͷ�ڵ�
	struct LinkNode pHeader;
	//������
	int m_size;
};

typedef void * LinkList;


//��ʼ������
LinkList init_LinkList()
{
	struct LList * myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_size = 0;

	return myList;
}

//��������
void insert_LinkList(LinkList list, int pos, void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//list��ԭΪstruct LList��������
	struct LList * myList = list;
	//����λ����Ч��ִ��β��
	if (pos < 0 || pos >myList->m_size)
	{
		pos = myList->m_size;
	}

	//�ҵ�����ڵ��ǰ���ڵ�λ��
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		//pCurrent Ҫ����ڵ��ǰ��
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//�����ڵ��ϵ
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//����������
	myList->m_size++;

}

//��������
void foreach_LinkList(LinkList list, void(*myForeach)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;
	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		myForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}

//ɾ������ڵ㣨��λ�ã�
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;
	if (pos < 0 || pos > mylist->m_size - 1)
	{
		return;
	}

	//�ҵ���ɾ���ڵ��ǰ���ڵ�
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//��¼��ɾ���Ľڵ�
	struct LinkNode * pDel = pCurrent->next;

	//���½����ڵ��ϵ
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	//����������
	mylist->m_size--;
}

//ɾ������ڵ㣨ֵ��
void removeByValue_LinkList(LinkList list, void * data, int(*myCompare)(void *, void *))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * mylist = list;
	//����ָ��
	struct LinkNode * pPrev = &mylist->pHeader;
	struct LinkNode * pCurrent = pPrev->next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		if (myCompare(pCurrent->data, data))
		{
			pPrev->next = pCurrent->next;
			free(pCurrent);
			pCurrent = NULL;
			mylist->m_size--;
			break;
		}

		//����ָ�����
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//�������
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;
	struct LinkNode * pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		struct LinkNode * pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

//����������
int  size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * mylist = list;
	return mylist->m_size;
}

//��������
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	//�������
	clear_LinkList(list);
	free(list);
	list = NULL;

}
