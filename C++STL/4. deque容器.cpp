#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include <deque>
#include <algorithm>

/*
--------------------------------------------------
vector��deque��˫�˶��У���
	Vector�����ǵ��򿪿ڵ������ڴ�ռ䡣
	deque����һ��˫�򿪿ڵ��������Կռ䡣

˫�򿪿ڣ�
	������ͷβ���˷ֱ���Ԫ�صĲ����ɾ��������
	vector����Ҳ������ͷβ���˲���Ԫ�أ�
	��������ͷ������Ч�����޷������ܡ�

deque��
	deque�Ƕ�̬�ġ��Էֶ������ռ���϶��ɣ���ʱ��
	������һ���µĿռ䲢����������
	�����������㸴�ӣ������������Ϊ���Ǹ�Ч������
	�����Ƶ�vector����������ٿ�����deque��

dequeԭ��
	Deque����һ��һ�εĶ����������ռ乹�ɣ���Ҫ��չ
	ʱ��ͷ����β���������úõ��¿ռ䡣deque���ص���
	�ڶԷֶ������ڴ�ռ��ά�������ṩ�����ȡ�ӿڡ�
	���������ܹ����ӵ�ԭ��deque����һ��map��Ϊ���ء�
	map��һС���������ڴ�ռ䣬����ÿһ��Ԫ��(�˴���
	Ϊһ�����)����һ��ָ�룬ָ����һ���������ڴ�ռ䣬
	����������������������deque�Ĵ洢�ռ�����塣


������API������

���캯����
	deque<T> deqT;//Ĭ�Ϲ�����ʽ
	deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	deque(n, elem);//���캯����n��elem����������
	deque(const deque &deq);//�������캯����

��ֵ������
	assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	assign(n, elem);//��n��elem������ֵ������
	deque& operator=(const deque &deq); //���صȺŲ�����
	swap(deq);// ��deq�뱾���Ԫ�ػ���

��С������
	deque.size();//����������Ԫ�صĸ���
	deque.empty();//�ж������Ƿ�Ϊ��
	deque.resize(num);//����ָ�������ĳ���Ϊnum,����Ĭ��ֵ��䣬����ɾ����
	deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,����elem��䣬����ɾ����

˫�˲�����ɾ����
	push_back(elem);//������β�����һ������
	push_front(elem);//������ͷ������һ������
	pop_back();//ɾ���������һ������
	pop_front();//ɾ��������һ������

���ݴ�ȡ��
	at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
	operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
	front();//���ص�һ�����ݡ�
	back();//�������һ������

���������
	insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
	insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
	insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

ɾ��������
	clear();//�Ƴ���������������
	erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

--------------------------------------------------
*/


void printDeque(const deque<int>& d)
{
	//iterator��ͨ������
	//reverse_iterator ��ת������
	//const_iterator  ֻ��������

	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	deque<int>d2;
	d2 = d;
	printDeque(d2);

	if (d2.empty())
	{
		cout << "d2Ϊ��" << endl;
	}
	else
	{
		cout << "d2��Ϊ�� size = " << d2.size() << endl;
	}
}

void test02()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//  300 200 100 10 20 30
	printDeque(d);

	d.pop_back(); //βɾ
	d.pop_front(); //ͷɾ
	// 200 100 10 20
	printDeque(d);

	cout << "��һ��Ԫ��Ϊ�� " << d.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << d.back() << endl;
}


void test03()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//���� insert
	d.insert(++d.begin(), 2, 1000);
	//  300 1000 1000  200 100 10 20 30
	printDeque(d);
	//ɾ��erase
	//d.erase(++d.begin());
	//d.erase(++d.begin());
	//�������
	deque<int>::iterator it1 = d.begin();
	it1 = it1 + 1;
	deque<int>::iterator it2 = d.begin();
	it2 = it2 + 3;
	//ɾ��Ԫ�أ�������it2��
	d.erase(it1, it2);
	printDeque(d);
	//���
	d.clear();
	printDeque(d);
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//Ĭ�������С����
	//sort(d.begin(), d.end());
	//�Ӵ�С�����ṩ�ص��������ײ�ʵ�����Դ�룩
	sort(d.begin(), d.end(), myCompare);
	printDeque(d);
}


int main() {
	test01();
	test02();
	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}