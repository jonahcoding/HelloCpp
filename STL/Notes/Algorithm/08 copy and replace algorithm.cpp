#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <ctime>

using namespace std;

/*
--------------------------------------------------
【常用拷贝、替换、交换算法】

copy算法：将容器内指定范围的元素拷贝到另一容器中。

replace算法 将容器内指定范围的旧元素修改为新元素。

replace_if算法：replace_if(iterator beg, iterator end, _callback, newvalue);
	按条件替换。

swap算法：交换。

--------------------------------------------------
*/

//copy
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

//replace
//replace_if
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};

void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//指定替换
	replace(v.begin(), v.end(), 3, 3000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//条件替换
	replace_if(v.begin(), v.end(), MyReplace() , 30000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

//swap交换
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2(10, 100);
	
	cout << "交换数据前：" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "交换数据后：" << endl;
	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main(){

	test01();
	test02();
	test03();
	
	system("pause");
	return 0;
}