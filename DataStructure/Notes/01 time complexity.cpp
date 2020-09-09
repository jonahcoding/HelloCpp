#include <iostream>
using namespace std;

/*
--------------------------------------------------
时间复杂度：
    默认执行一行指令花费一个unit_time
简化：
    n趋于无穷
--------------------------------------------------
伪代码（一）：
	int sum = 0;    //  unit_time
	int i;    //  unit_time
	for (i = 0; i < n; i++) //  n * unit_time
	{
		sum += i;   //  n * unit_time
	}
	return sum; //  忽略不计
--------------------------------------------------
以上代码执行花费的时间为：T(n) = (2n+2) * unit_time
令f(n) = 2n+2
T(n)：算法执行的总时间。
f(n)：算法执行的总次数。
T(n) = O(f(n))
时间复杂度为：O(2n+2) = O(n)

--------------------------------------------------
 伪代码（二）：
	 int sum = 0;    //  unit_time
	 int i = 0;    //  unit_time
	 int j = 0;    //  unit_time
	 for(i; i < n; i++)   //  n * unit_time
	 {
		j = 0;   //  n * unit_time
		for(; j < n; j++)   //  n * n * unit_time
		{
			sum += i;   //  n * n * unit_time
		}
	 }
	 return sum;
--------------------------------------------------
 3 * unit_time + 2n * unit_time + 2n^2 * unit_time
 时间复杂度为：O(3+2n+2n^2) = O(n^2)

 常见时间复杂度：
    O(1)：数组取值
    O(logn)：二分查找、二叉查找树的增删改查
    O(n)：链表的查找
    O(nlogn)：快速排序、堆排序
    O(n^2)：冒泡排序、插入排序
    O(2^n)：递归（斐波那契数列）f(n) = f(n - 1) + f(n - 2)
    O(n!)：排列（阶乘）

--------------------------------------------------
*/

int main() {

    return 0;
}
