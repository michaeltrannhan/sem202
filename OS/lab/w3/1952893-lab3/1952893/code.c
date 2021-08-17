#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
void *hello (void *tid){
    printf("Hello from thread %d\n", *((int*)tid));
}

int  main(){
    clock_t start, end;
    start = clock();

    pthread_t tid [1000000000];
    long int i;
    for(i = 0; i < 1000000000; i++)
    {
        // void *id = &i;
        pthread_create(&tid[i], NULL, hello, (void*)&i);
        pthread_join(tid[i], NULL);
    }
    end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("time is: %f \n", time_taken);

    pthread_exit(NULL);

    
}

