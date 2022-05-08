#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    if((pid = fork()) <0)
        perror("fork error");
    else if(pid == 0){
        printf("Gyerek pid: %d\n", getpid());
        for(int i=0; i<10; i++)
            printf("Kormos Balázs YE6BLB\n");
    }
    else{
        printf("Szulo pid: %d", getpid());
    }

    return 0;
}
