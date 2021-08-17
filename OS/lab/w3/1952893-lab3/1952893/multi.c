#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct Info{
    int ID;
    int count;
    int nPoints;
};
Info[16];
int main(int argc, char* argv[])
{
    int ite;
    pthread_t tid;
    pthread_attr_t attr;
    if(argc != 2){
        return -1;
    }
    if(atoi(1) < 0){
        return -1;
    }

}

