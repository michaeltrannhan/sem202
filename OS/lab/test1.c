#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int glo_init_data = 99;
int glo_noninit_data;

void print_func()
{
    int local_data = 9;
    printf("process Id :%d\n", getpid());
    printf("add: \n");
    printf("1. glo_init = %p \n", &glo_init_data);
    printf("2. glo_noninit = %p \n", &glo_noninit_data);
    printf("3. printfunc = %p \n", &print_func);
    printf("4. local = %p \n", &local_data);    
}

int main(int argc, char** argv[])
{
    print_func();
    return 0;
}