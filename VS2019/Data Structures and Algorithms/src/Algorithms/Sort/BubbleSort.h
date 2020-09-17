#pragma once

#include <vector>
#include <chrono>

using namespace std;

/*
--------------------------------------------------
BubbleSort��ð�����򷨣���
	1.�Ƚ�����Ԫ�أ�ǰ�߱Ⱥ��ߴ�С���򽻻���
	2.��ʼ��һ����ĩβ��һ�β�����ĩβΪ���ֵ��
	3.�ظ����ϲ���ֱ��ȫ������

�ȶ�����Ԫ�ش�С��ͬ���ı�λ�á�

���ʱ�临�Ӷȣ�O(N)	����Ԫ������
�ʱ�临�Ӷȣ�O(N^2)	����Ԫ�ط���
ƽ��ʱ�临�Ӷȣ�O(N^2)	

�Ľ���
	���ñ�־λ����ĳ�α�������δ��������˵���Ѿ�����

���֣�
	��β������
		1.�����������ٴ��ҵ�������ȷ�����ֵ����Сֵ��
		2.�ظ����ϲ��衣
--------------------------------------------------
*/


class BubbleSort
{
public:
	static vector<int> Sort(vector<int> arr)
	{
		for (int i = 0; i < arr.size() - 1; i++)
			for (int j = 0; j < arr.size() - 1 - i; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
		return arr;
	}

	static vector<int> Sort_Pro(vector<int> arr)
	{
		bool isSorted = true;
		for (int i = 0; (i < arr.size() - 1) && isSorted; i++)
		{
			isSorted = false;
			for (int j = 0; j < arr.size() - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					isSorted = true;
				}
			}
		}
		return arr;
	}

	static vector<int> Sort_Cocktail(vector<int> arr)
	{
		bool isSorted = true;
		for (int i = 0; i < arr.size() - 1 && isSorted; i++)
		{
			bool isSorted = false;
			for (int j = i; j < arr.size() - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					isSorted = true;
				}
			}

			for (int j = arr.size() - 1 - i; j > i; j--)
			{
				if (arr[j - 1] > arr[j])
				{
					swap(arr[j - 1], arr[j]);
					isSorted = true;
				}
			}
		}
		return arr;
	}
};
