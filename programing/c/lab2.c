#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// /*
// int main(int argc, char ** agrv)
// {
//     pid_t child_pid;

//     child_pid = fork();
    
//     if(child_pid==-1)
//     {
//         perror("fork");
//         exit(1);
//     }

//     if(child_pid == 0)
//     {
//         printf("Hello, ");
//         fflush(stdout);
//     }
//     else
//     {
//         printf("World!\n");
//         fflush(stdout);
//     }
    
//     return 0;
// }
// */
int value = 19;

int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        value += 15;
        printf("PID of child process = %d \n", getpid());
        return 0;
    }
    else if(pid > 0)
    {
        wait(NULL);
        printf("PARENT: value = %d \n", value);
    }

}