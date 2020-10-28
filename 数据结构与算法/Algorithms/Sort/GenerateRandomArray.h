#ifndef _GENERETE_RANDOM_ARRAY_H_
#define _GENERETE_RANDOM_ARRAY_H_

#include <iostream> 
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> GenerateRandomArray(int begin = 0, int end = 100, int num = 10, bool repeatFlag = false, bool orderFlag = false, bool descendFlag = false)
{
	int m_begin = begin;				//The first element of the range.
	int m_end = end;					//The last element of the range.
	int m_num = num;					//Random array capacity.
	bool m_repeatFlag = repeatFlag;		//Produce duplicate values, it is false by default.
	bool m_orderFlag = orderFlag;		//Generate ordered values, it is false by default.
	bool m_descendFlag = descendFlag;	//Sort all elements in descending order, it is false by default.

	std::srand(unsigned(std::time(0)));
	std::set<int> s_GRA;
	std::vector<int> v_GRA;

	if (!m_repeatFlag)
	{
		if ((m_end - m_begin + 1) < m_num)
		{
			cout << "The interval must be greater than the number of values, ";
			cout << "or repeated values are allowed." << endl;
			system("pause");
			throw 0;
		}
		while (s_GRA.size() != m_num)
		{
			s_GRA.insert(rand() % (m_end - m_begin + 1) + m_begin);
		}
		v_GRA.assign(s_GRA.begin(), s_GRA.end());
	}
	else
	{
		while (v_GRA.size() != m_num)
		{
			v_GRA.push_back(rand() % (m_end - m_begin + 1) + m_begin);
		}
	}
	if (!m_orderFlag)
	{
		random_shuffle(v_GRA.begin(), v_GRA.end());
	}
	else if (!m_descendFlag)
	{
		sort(v_GRA.begin(), v_GRA.end());
	}
	else
	{
		sort(v_GRA.rbegin(), v_GRA.rend());
	}

	return v_GRA;
}

#endif