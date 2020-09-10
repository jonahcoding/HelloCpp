#define QUEUE_SIZE 100

#include "queue.h"
#include <assert.h>

static QUEUE_TYPE queue[QUEUE_SIZE];
static int front = 0;
static int rear = 0;

int is_empty()
{
    return front == rear;
}

int is_full()
{
    return rear == QUEUE_SIZE;
}

// //入队
// void en_queue(QUEUE_TYPE value)
// {
//     assert(!is_full());
//     queue[rear++] = value;
// }

//入队优化（避免队列浪费）
void en_queue(QUEUE_TYPE value)
{
    if (is_full())
    {
        if (front == 0)
        {
            return;
        }
        for (int i = front; i < rear; i++)
        {
            queue[i - front] = queue[i];
        }
        rear -= front;
        front = 0;
    }
    queue[rear++] = value;
}
//出队
void de_queue(void)
{
    assert(!is_empty());
    front++;
}
//获取队首元素值
QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}