#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;

/*
--------------------------------------------------
一、问题
	五名选手ABCDE，10的评委打分，去除最高分最低分，取平均分。

二、解决方案
	2.1. 创建五名选手，放到vector中
	2.2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	2.3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	2.4. deque容器遍历一遍，累加分数，累加分数/d.size()
	2.5. person.score = 平均分

--------------------------------------------------
*/

class Player
{
public:
	Player(string name, double score) :m_Name(name), m_Score(score) {}
	string m_Name;
	double m_Score;
};

void creatPlayer(vector<Player> &v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameseed[i];
		int score = 0;

		Player p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Player> &v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		double sum = 0;
		for (deque<double>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		double avg = sum / d.size();
		it->m_Score = avg;
	}
}

void showScore(vector<Player> &v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " , 成绩：" << it->m_Score << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	vector<Player> v;
	creatPlayer(v);
	setScore(v);
	showScore(v);

	system("pause");
	return 0;
}