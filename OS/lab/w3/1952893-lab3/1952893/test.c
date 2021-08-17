#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUMBER_OF_POINTS 1000000
#define NUMBER_OF_SLAVES    1000
 
/* Points in the circle */
int circle_count = 0;
 
/* Generates a double precision random number */
double random_double()
{
    return random() / ((double)RAND_MAX + 1);
}
 
int main (int argc, const char * argv[]) {
    long long i;
    double Pi;
    clock_t begin = clock();
    /* seed the random number generator */
    srandom((unsigned)time(NULL));
    //omp_set_num_threads(8);
    #pragma omp parallel
    {
        int hit_count = 0,i;
        double x,y;
 
        for (i = 0; i < NUMBER_OF_POINTS; i++) {
 
            /*generate random numbers between -1.0 and +1.0 (exclusive)*/
            /* to obtain a random (x, y) point*/
            x = random_double() * 2.0 - 1.0;
            y = random_double() * 2.0 - 1.0;
            /* is (x, y) point within the circle ? */
            if ((x*x + y*y) < 1.0 )
            ++hit_count; /* yes, (x, y) point is in circle */
        }
 
            #pragma omp critical 
            {   
                circle_count += hit_count;
            }
    }
         
    /* estimating Pi */
    Pi = 4.0 * circle_count / (NUMBER_OF_POINTS * omp_get_num_procs());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("NUMBER OF POINTS = %d\n",NUMBER_OF_POINTS);
    //printf("NUMBER OF SLAVES = %d\n",NUMBER_OF_SLAVES);
    printf("Pi = %f\n",Pi);
    printf("time = %f\n",time_spent);
         
    return 0;
}