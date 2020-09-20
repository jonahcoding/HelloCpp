/*
--------------------------------------------------
【程序与进程】
    程序：一组指令的有序集合，静态实体，不占用系统资源。
    进程：具有一定独立功能的程序关于某个数据集合上的一次运行活动，动态实体，占用系统资源（有生命周期）。
    并发：进程并行运行，轮流使用系统资源。
--------------------------------------------------

--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    printf("xxxxxxxxxx\n");

    pid = fork();
    if (pid == -1)
    {
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child, pid = %u, ppid = %lu\n", getpid(), getppid());
    }
    else
    {
        printf("Parent, pid = %u, ppid = %lu\n", getpid(), getppid());
    }
    
    printf("YYYYYYYYYYYYYYYYYY\n");

    return 0;
}
