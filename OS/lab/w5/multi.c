#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>
int main(int argc, char *argv[])
{
    long niter = 100000000; //number of iterations per FOR loop
    double x, y;         //x,y value for the random coordinate
    int i;               //loop counter
    long count = 0;       //Count holds all the number of how many good coordinates
    double z;            //Used to check if x^2+y^2<=1
    double pi;           //holds approx value of pi
    int numthreads = 8;
    omp_set_num_threads(numthreads);
    omp_lock_t lock;
    omp_init_lock (&lock);
#pragma omp parallel shared(count)
    {
        unsigned int rand_state = random() - RAND_MAX / 2 - 1;
        //srandom((int)time(NULL) ^ omp_get_thread_num()); //Give random() a seed value
        for (i = 0; i < niter; ++i) //main loop
        {
            omp_set_lock(&lock);
            // x = (double)random() / RAND_MAX; //gets a random x coordinate
            // y = (double)random() / RAND_MAX; //gets a random y coordinate
            double x = 1.0 * rand_r(&rand_state) / RAND_MAX;
            double y = 1.0 * rand_r(&rand_state) / RAND_MAX;
            z = (x * x) + (y * y); //Checks to see if number is inside unit circle
            if (z <= 1)
            {
                ++count; //if it is, consider it a valid random point
            }
            omp_unset_lock(&lock);
        }
        //print the value of each thread/rank
    }
    pi = ((double)count / (double)(niter * numthreads)) * 4.0;
    printf("Pi: %f\n", pi);

    return 0;
}