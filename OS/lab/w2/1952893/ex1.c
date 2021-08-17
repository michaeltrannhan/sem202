#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char** argv)
{
    int arr[100];
    int idx = 0;
    FILE *fp = fopen("numbers.txt", "r");
    if(fp == NULL)
    {
        perror("Unable to open file!");
        exit(1);
    }
    char line[500];
    while(fgets(line, sizeof(line), fp)){
        arr[idx] = atoi(line);
        idx+=1;
    }
    fclose(fp);
/*
    for(int i = 0; i <idx ; i++)
    {
        printf("%d \n", arr[i]); 
    }
*/
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
	int Count3 = 0;
        for(int i = 0; i < idx; i++)
	{
		if(arr[i] % 3 == 0) Count3++;
	}
	printf("Parent: %d\n", Count3);
    }
    else if(pid > 0)
    {
	int Count2 = 0; 
	for(int i = 0; i < idx; i++)
	{
		if(arr[i] % 2 == 0) Count2++;
	}
	printf("Child: %d\n", Count2);
        wait(NULL);
    }
    return 0;
}
