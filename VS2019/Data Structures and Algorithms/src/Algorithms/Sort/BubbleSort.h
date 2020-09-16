#pragma once

#include <vector>
using namespace std;
class BubbleSort
{
public:
	BubbleSort(vector<int> &vec)
	{
		v = vec;
		sort();
	}

	vector<int> sort()
	{
		if (v.size() == 0)
			throw 0;
		int temp = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > v[i+1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
		return v;
	}

private:
	vector<int> v;
};
