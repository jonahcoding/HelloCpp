#pragma once

#include <iostream> 
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>

using namespace std;

class GetRandomNumbers
{
public:
	GetRandomNumbers(int begin = 0, int end = 100, int sum = 10, bool repeatFlag = false, bool orderFlag = false, bool descendFlag = false)
	{
		m_begin = begin;
		m_end = end;
		m_sum = sum;
		m_repeatFlag = repeatFlag;
		m_orderFlag = orderFlag;
		m_descendFlag = descendFlag;
	}

	vector<int> getGRN()
	{
		srand(unsigned(time(0)));
		set<int> s_GRN;
		vector<int> v_GRN;

		if (!m_repeatFlag)
		{
			if ((m_end - m_begin + 1) < m_sum)
			{
				cout << "If duplicate numbers are not allowed,please ensure " ;
				cout << "that the number of random numbers to be obtained ";
				cout << "is less than or equal to the capacity of the value set." << endl;
				throw 0;
			}
			while (s_GRN.size() != m_sum)
			{
				s_GRN.insert(rand() % (m_end - m_begin + 1) + m_begin);
			}
			v_GRN.assign(s_GRN.begin(), s_GRN.end());
		}
		else
		{
			while (v_GRN.size() != m_sum)
			{
				v_GRN.push_back(rand() % (m_end - m_begin + 1) + m_begin);
			}
		}
		if (!m_orderFlag)
		{
			random_shuffle(v_GRN.begin(), v_GRN.end());
		}
		else if (!m_descendFlag)
		{
			sort(v_GRN.begin(), v_GRN.end());
		}
		else
		{
			sort(v_GRN.rbegin(), v_GRN.rend());
		}

		return v_GRN;
	}

	int getGRNSize() { return m_sum; }

private:
	int m_begin;
	int m_end;
	int m_sum;
	bool m_repeatFlag;
	bool m_orderFlag;
	bool m_descendFlag;
};
