#pragma once

#include <iostream>

using namespace std;

/*
--------------------------------------------------
BruteForce(暴力匹配法)：
	主串与模式串当前字符相同，比较下一个字符，否则
	主串回退到本次匹配初始位置的下一个位置，模式串
	回退到初始位置。

	最坏情况：每次只有最后一个字符不匹配。
	最坏时间复杂度：O((n-m+1)*m)

	最好情况：所有字符都不匹配
	最好时间复杂度：O(n)

--------------------------------------------------
*/

class BruteForce
{
public:
	BruteForce(string& t, string& p)
	{
		//====================
		vector<int> v_pos;
		int tLen = t.size();
		int pLen = p.size();
		int i, j;
		for (i = 0; i <= tLen-pLen; i++)
		{
			for (j = 0; j < pLen; j++)
			{
				if (t[i + j] != p[j])
				{
					break;
				}
			}
			if (j == pLen)
			{
				v_pos.push_back(i + 1);
				//break;
			}
		}
		//====================
		cout << "Target string: " << t << endl;
		cout << "The length of the target string is: " << t.size() << endl;
		cout << "Pattern string: " << p << endl;
		cout << "The length of the pattern string is: " << p.size() << endl;

		if (v_pos.size() == 0)
		{
			cout << "No pattern string was found in the target string!" << endl;
		}
		else
		{
			cout << "The position of the pattern string in the target string is :";
			for (vector<int>::iterator it = v_pos.begin(); it != v_pos.end(); it++)
			{
				 cout << *it;
				 if (it != v_pos.end()-1)
				 {
					 cout << " , ";
				 }
			}
			cout << endl;
		}
		//====================
	}
};