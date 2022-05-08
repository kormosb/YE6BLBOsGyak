#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;

   if ( (pid = fork()) < 0)  perror("fork hiba");
	else if (pid == 0)
		exit(3);

    waitpid(pid, &status, 0);

    if ( WIFEXITED(status) )
    {
        int exit_status = WEXITSTATUS(status);

        printf("Exit code: %d\n", exit_status);
    }

    if ( (pid = fork()) < 0)  perror("fork hiba");
	else if (pid == 0)
		abort();
    if (wait(&status) != pid) perror("wait hiba");
    int exit_status = WEXITSTATUS(status);
    printf("Abort code: %d", exit_status);

return 0;
}
