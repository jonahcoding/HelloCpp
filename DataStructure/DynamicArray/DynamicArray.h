#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *	�ṹ�壺��̬����
 *  ��ԱpAddr��ָ�������̬����Ԫ�ص�ָ�루����Ԫ�س�ʼΪvoid*���ͣ���
 *	��Աm_capacity����̬����������
 *	��Աm_size����̬�����С��
 */
struct dynamicArray {
	void** pAddr;
	int m_capacity;
	int m_size;
};

//��ʼ����̬����
struct dynamicArray*  init_DynamicArray(int capacity);
//����Ԫ��
void insert_DynamicArray(struct dynamicArray * array, int pos, void * data);
//������̬����
void foreach_DynamicArray(struct dynamicArray * array, void(*myPrint)(void *));
//��λ���Ƴ�Ԫ��
void removeByPos_DynamicArray(struct dynamicArray * array, int pos);
//��ֵ�Ƴ�Ԫ��
void removeByValue_DynamicArray(struct dynamicArray * array, void * data, int(*myCompare)(void *, void *));
//���ٶ�̬����
void destory_DynamicArray(struct dynamicArray * array);