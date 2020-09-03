#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点结构体
struct LinkNode
{
	//数据域
	void * data;
	//指针域
	struct LinkNode * next;
};

//链表结构体
struct LList
{
	//头节点
	struct LinkNode pHeader;
	//链表长度
	int m_size;
};

typedef void * LinkList;


//初始化链表
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

//插入链表
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
	//list还原为struct LList数据类型
	struct LList * myList = list;
	//插入位置无效：执行尾插
	if (pos < 0 || pos >myList->m_size)
	{
		pos = myList->m_size;
	}

	//找到插入节点的前驱节点位置
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		//pCurrent 要插入节点的前驱
		pCurrent = pCurrent->next;
	}

	//创建新节点
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//建立节点关系
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//更新链表长度
	myList->m_size++;

}

//遍历链表
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

//删除链表节点（按位置）
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

	//找到待删除节点的前驱节点
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除的节点
	struct LinkNode * pDel = pCurrent->next;

	//重新建立节点关系
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	//更新链表长度
	mylist->m_size--;
}

//删除链表节点（值）
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
	//辅助指针
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

		//辅助指针后移
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
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

//返回链表长度
int  size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * mylist = list;
	return mylist->m_size;
}

//销毁链表
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	//清空链表
	clear_LinkList(list);
	free(list);
	list = NULL;

}
