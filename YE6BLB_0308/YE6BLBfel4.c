#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
char	*env_init[] = {"USER=ismeretlen","PATH=/tmp","ENV=vége\n", NULL };

int main(int argc, char *argv[])
{
    int	i;
	pid_t pid;

	if ( (pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) {
		if (execle(strcat(getenv("BIN"),"/echoall"),
				   "echoall", "myarg1", "MY ARG2", (char *) 0,
				   env_init) < 0)
			perror("execle error");
	}
	if (waitpid(pid, NULL, 0) < 0)
		perror("wait error");

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	exit(0);
}

