#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid;

	pid = fork();

	if(pid>0)
	{
		wait();
		printf("I am back.\n");
	}
	else
	{
		if(execlp("ls","ls","-l",NULL)==-1)
			printf("Bad command\n");
	}

	return 0;
}
