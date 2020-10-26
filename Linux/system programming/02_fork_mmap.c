/*
--------------------------------------------------
【mmap】
    一种内存映射文件的方法。
    将一个文件或者其它对象映射到进程的地址空间，实现文件
    磁盘地址和进程虚拟地址空间中一段虚拟地址的一一对映关系。
    实现不同进程间的文件共享。

--------------------------------------------------
*/

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int fd; pid_t pid;
    char buf[1024];
    char *str = "test for shared fd in parent child process\n";

    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    ftruncate(fd, 100);

    char *p = mmap(NULL, 100, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        //write(fd, str, strlen(str));
        strcpy(p, str);
        printf("child wrote over...\n");
    } else {
        sleep(1);                   //保证子进程写入数据
        //lseek(fd, 0, SEEK_SET);     //改变读写指针位置
        //int len = read(fd, buf, sizeof(buf));
        printf("--------%s\n", p);
        //write(STDOUT_FILENO, buf, len);
//        write(fd, "overwrite!\n", sizeof("overwrite\n"));

        wait(NULL);
    }

    munmap(p, 100);

    return 0;
}