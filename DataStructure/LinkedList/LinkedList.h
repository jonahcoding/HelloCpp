#pragma once

typedef void * LinkList;

LinkList init_LinkList();
void insert_LinkList(LinkList list, int pos, void * data);
void foreach_LinkList(LinkList list, void(*myPrint)(void *));
void removeByPos_LinkList(LinkList list, int pos);
void removeByValue_LinkList(LinkList list, void * data, int(*myCompare)(void *, void *));
void clear_LinkList(LinkList list);
int size_LinkList(LinkList list);
void destory_LinkList(LinkList list);