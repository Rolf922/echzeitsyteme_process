#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHILD 0
#define FAILURE -1

void exit_handler1() {
    char *owner = getenv("USER");
    if(owner) printf("Goodbye %s\n", owner);
    else perror("getenv()");
}

int main()
{
    pid_t pid = fork();
    switch (pid)
    {
    case FAILURE:
        perror("fork_failed");
        exit(EXIT_FAILURE);

    case CHILD:
        printf("Child: My process PID ist %d\n" ,getpid());
        printf("My parent process PID ist %d\n" ,getppid());
        sleep(4);
        printf("My current parent process PID ist %d\n" ,getppid());
        exit(EXIT_SUCCESS);

    default:
        atexit(exit_handler1);
        sleep(2);
    }
}