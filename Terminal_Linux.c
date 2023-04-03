#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
	pid_t pid;
	int j = 0;
	char *args[10];
	char *userargs[10];
	int status;
	char *str = (char *)malloc(100);
	char *temp;
	char *com = (char *)malloc(100);
	char *path = getenv("PATH");
	if ((pid=fork())==0)
	{
	
	for(int i = 0; i<=8 ; i++)
	{
		args[i] = strtok(path, ":");
		path = path + (strlen(args[i]) + 1);
	}
	while(1)
	{
		printf("Enter your shell command\n");
		gets(str);
	
	if(!(strcmp(str, "leave")))
	{
		printf("exit now\n");
		return 0;
	}
		userargs[0] = strtok(str, " ");
		temp = str + (strlen(userargs[0]) + 1);
		for(int i = 1; *temp; i++)
	{
		userargs[i] = strtok(temp, " ");
		temp = temp + (strlen(userargs[i]) + 1);
	}
	
	for(int i = 0; i<=8; i++)
	{
		strcpy(com, args[i]);
		strcat(com,"/");
		strcat(com, userargs[0]);
		execv(com, userargs);
	}
		printf("Command not found\n");
		
	}
	}
	else 
	{
		wait(&status);
		sleep(3);
		printf("The command executed in the sun process\n");
		
	}
	
	return 0;
	
}
