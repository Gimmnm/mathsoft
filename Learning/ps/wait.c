#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#include <stdlib.h>
int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;
    printf("fork program starting\n");
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        message = "This is the child";
        n = 5;
        // 子进程退出码为37
        exit_code = 38;
        break;
    default:
        message = "This is the parent";
        n = 3;
        // 父进程退出码为0
        exit_code = 0;
        break;
    }
    for (; n > 0; n--)
    {
        puts(message);
        sleep(1);
    }
    // pid != 0 是父进程
    if (pid != 0)
    {
        int stat_val;
        pid_t child_pid;
        // 等待子进程结束，同时获得子进程的退出码，存在stat_val中
        child_pid = wait(&stat_val);
        printf("Child has finished : PID = %d\n", child_pid);
        // 如果子进程正常结束，打印退出码
        if (WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    // 父子都在这里退出
    exit(exit_code);
    
}