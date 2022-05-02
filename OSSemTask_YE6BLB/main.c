#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0){
    printf("Szulo2 pid %d\n", getpid());

    pid_t pids[3];
    int i;

    for(i = 0; i < 3; i++){
        pids[i]=fork();
        if(pids[i]==0){
            sleep(i+3);
            printf("Gyerek2%d pid %d PPid %d\n",i, getpid(), getppid());
            exit(0);
        }
    }
    for(i = 0; i < 3; i++)
        waitpid(pids[i], NULL, 0);
    }

    else{
        printf("Szulo1 pid %d\n", getpid());

    pid_t pids[3];
    int i;

    for(i = 0; i < 3; i++){
        pids[i]=fork();
        if(pids[i]==0){
            sleep(i+3);
            printf("Gyerek1%d pid %d PPid %d\n",i, getpid(), getppid());
            exit(0);
        }
    }
    for(i = 0; i < 3; i++)
        waitpid(pids[i], NULL, 0);
    }


    return 0;

}
