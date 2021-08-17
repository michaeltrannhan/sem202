// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include  <string.h>

// #define   MAX_COUNT  200
// #define   BUF_SIZE   100

// int value = 19;
// int main()
// {
//     pid_t pid;
//     pid = fork();
//     if(pid == 0)
//     {
//         value += 15;
//         printf("PID of child process = %d \n", getpid()); //*a
//         return 0;
//     }
//     else if(pid > 0)
//     {
//         wait(NULL); //*b
//         printf("PARENT: value = %d \n", value); //*c
//         return 0;
//     }
// }

// // void  main(void)
// // {
// //      pid_t  pid;
// //      int    i;
// //      char   buf[BUF_SIZE]; //* buf_size =100 | max_size = 200

// //      fork();
// //      pid = getpid();
// //      printf("%s","helo");
// //      for (i = 1; i <= MAX_COUNT; i++) {
// //           sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
// //           write(1, buf, strlen(buf));
// //      }
// // }

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
     pid_t pid;
     /* fork a child process */
     pid = fork();
     if (pid < 0)
     { /* error occurred */
          fprintf(stderr, "Fork Failed");
          return 1;
     }
     else if (pid == 0)
     { /* child process */
          execlp("/bin/ls", "ls", NULL);
     }
     else
     { /* parent process */
          /* parent will wait for the child to complete */
          //wait(NULL);
          printf("Child Complete");
     }
     return 0;
}