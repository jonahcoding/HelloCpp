#ifndef queue_h
#define queue_h

#define QUEUE_TYPE int

#include <stdio.h>

//入队
void en_queue(QUEUE_TYPE value);
//出队
void de_queue(void);
//获取队首元素值
QUEUE_TYPE first(void);
int is_empty();
int is_full();

#endif