#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
//void multi()
{
    //*time measurement
    clock_t start, end;
    start = clock();

    long int niter;
    if (argc != 2)
    {
        return 1;
    }
    niter = atoi(argv[1]);
    //printf("ite is: %d\n", niter);
    // scanf("%d", &niter);
    double x, y;
    long int i;
    // int count = 0;
    double z;
    double pi;
    // unsigned int rand_state = rand();
    omp_set_num_threads(8);
#pragma omp parallel
    {
        int count;
        srandom((int)time(0)); //Give random() a seed value
        for (i = 0; i < niter; ++i)
        {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            // double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
            // double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
            z = (x * x) + (y * y);
            if (z <= 1)
            {
                ++count;
            }
        }
        //print the value of each thread/rank
    }
    pi = ((double)count / (double)(niter)) * 4.0;
    printf("Pi: %f\n", pi);

    end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("time is: %f \n", time_taken);
    //*end of time measurement
}
