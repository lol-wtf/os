#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void parent()
{
	int i;
	for(i=1;i<=5;i++)
	{
		printf("Parent: %d\n",i);
		sleep(3);
	}
}

void child()
{
	int i;
	for(i=1;i<=5;i++)
	{
		printf("Child: %d\n",i);
		sleep(3);
	}
}

int main()
{
	int pid;

	pid = fork();

	if(pid<0)
	{
		printf("Failed to fork()");
		exit(1);
	}
	else if(pid>0)
	{
		wait();
		parent();
	}
	else
	{
		child();
	}

	return 0;
}
