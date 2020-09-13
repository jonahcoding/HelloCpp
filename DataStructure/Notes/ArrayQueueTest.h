#pragma

#include "ArrayQueue.h"

class ArrayQueueTest
{
public:
	ArrayQueueTest()
	{
		cout << "====================" << endl;
		cout << "Array Queue Test!" << endl;
		cout << "--------------------" << endl;

		ArrayQueue<int > arr_queue(10);
		cout << "Queue �Ƿ�Ϊ�գ�" << arr_queue.isEmpty() << endl;
		for (int i = 0; i < 14; i++)
		{
			arr_queue.enqueue(i);
		}
		arr_queue.print();
		cout << "��ǰ�����ǣ�" << arr_queue.front() << endl;

		for (int i = 0; i < 4; i++)
		{
			arr_queue.dequeue();
		}
		arr_queue.print();

		for (int i = 0; i <= 9; i++)
		{
			arr_queue.enqueue(i + 14);
		}
		arr_queue.print();


		cout << "Queue �Ƿ�Ϊ�գ�" << arr_queue.isEmpty() << endl;
		cout << "��ǰ�����ǣ�" << arr_queue.front() << endl;

		cout << "====================" << endl;
		cout << endl;
	}

};

