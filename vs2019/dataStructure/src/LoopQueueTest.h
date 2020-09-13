#include "LoopQueue.h"


class LoopQueueTest
{
public:
	LoopQueueTest()
	{
		cout << "====================" << endl;
		cout << "Loop Queue Test!" << endl;
		cout << "--------------------" << endl;

		LoopQueue<int > loop_queue(10);
		cout << "Queue 是否为空：" << loop_queue.isEmpty() << endl;
		for (int i = 0; i < 14; i++)
		{
			loop_queue.enqueue(i);
		}
		loop_queue.print();
		cout << "当前队首是：" << loop_queue.front() << endl;

		for (int i = 0; i < 4; i++)
		{
			loop_queue.dequeue();
		}
		loop_queue.print();

		for (int i = 0; i <= 9; i++)
		{
			loop_queue.enqueue(i + 14);
		}
		loop_queue.print();

		cout << "Queue 是否为空：" << loop_queue.isEmpty() << endl;
		cout << "当前队首是：" << loop_queue.front() << endl;

		cout << "====================" << endl;
		cout << endl;
	}
};