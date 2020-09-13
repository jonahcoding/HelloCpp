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
		cout << "Queue �Ƿ�Ϊ�գ�" << loop_queue.isEmpty() << endl;
		for (int i = 0; i < 14; i++)
		{
			loop_queue.enqueue(i);
		}
		loop_queue.print();
		cout << "��ǰ�����ǣ�" << loop_queue.front() << endl;

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

		cout << "Queue �Ƿ�Ϊ�գ�" << loop_queue.isEmpty() << endl;
		cout << "��ǰ�����ǣ�" << loop_queue.front() << endl;

		cout << "====================" << endl;
		cout << endl;
	}
};