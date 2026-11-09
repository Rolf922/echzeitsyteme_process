#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHILD 0
#define FAILURE -1

void gen_zombie() 
{
    pid_t pid = fork();
    switch (pid)
    {
    case FAILURE:
        perror("fork_failed");
        exit(EXIT_FAILURE);

    case CHILD:
        printf("Child: My process PID is %d\n" ,getpid());
        _exit(EXIT_SUCCESS);
    }
}

void usage() 
{
    fputs("Usage: ./auf2 <number_of_zombies>\n",stderr);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        usage();
    }
    int k = atoi(argv[1]);
    if (k == -1)
    {
        while(1){
            gen_zombie();
        }
    } else {
        for (int i = 0; i < k; i++) 
        {
        gen_zombie();
        }
    }
    printf("Created %d zombie processes. Press Enter to exit.\n", k);

    sleep(100); // Give time to observe zombie processes before the parent exits
    return 0;
}