#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
    printf("process ID: %d \n", getpid());
    printf("Parent process ID: %d \n", getppid());
    printf("my group: %d \n", getpgrp());
    return 0;
}