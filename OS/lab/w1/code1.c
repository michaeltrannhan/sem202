#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for(int i = 0; i <idx ; i++)
    {
        printf("%d \n", arr[i]); 
    }
    return 0;
}