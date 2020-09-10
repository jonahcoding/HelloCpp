/*
==================================================
【队列】
--------------------------------------------------
队列：
	先进先出（FIFO），front/rear

方法：

--------------------------------------------------

==================================================
*/

#include <stdio.h>
#include "queue.h"

int main()
{
	en_queue(1);
	en_queue(2);
	en_queue(3);
	en_queue(4);

	printf("%d\n", first());
	de_queue();
	printf("%d\n", first());
	de_queue();
	printf("%d\n", first());
	de_queue();
	printf("%d\n", first());
	de_queue();
	printf("%d\n", first());
	de_queue();

	//system("pause");
	return 0;
}