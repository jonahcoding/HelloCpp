#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
--------------------------------------------------
myArray���ʵ�֣�
	1. Ĭ�Ϲ��졣
	2. �вι��졣
	3. �������졣
	4. ����β�塣
	5. ��λ���������ݡ�
	6. ��λ�û�ȡ���ݡ�
	7. ��ȡ����������
	8. ��ȡ�����С��
	9.
--------------------------------------------------
*/



class myArray
{
public:
	myArray();//Ĭ��100����
	myArray(int capacity);//�вι���
	myArray(const myArray &arr);//��������

	void pushback(int val);//β�巨
	void setData(int pos, int val);//��λ����������
	int getData(int pos);//��λ�û�ȡ����
	int getCapacity();//��ȡ��������
	int getSize();//��ȡ�����С

	~myArray();

private:
	int m_Capacity;//��������
	int m_Size;//�����С
	int* pAddress;//�ڶ������ٵ������ָ��

};