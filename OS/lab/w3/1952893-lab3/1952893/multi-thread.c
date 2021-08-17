// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <pthread.h>

// typedef struct Info{
//     int id;
//     int npoints;
//     int count;
// };

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// typedef struct drand48_data RNGstate;

// double sample_interval(double a, double b, RNGstate *state) {
//     double x;
//     drand48_r(state, &x);
//     return (b-a)*x + a;
// }

int main (int argc, char **argv) {
    //*time measurement 
    clock_t start, end;
    start = clock();
    int N = atoi( argv[1] ); // convert command-line input to N = number of points
    int NumThreads = 1;
    // const double pi = 3.141592653589793;
    double x, y, z;
    double counter = 0;
    // time_t ctime = time(NULL);

    #pragma omp parallel private(x, y, z) reduction(+:counter) num_threads(NumThreads)
    {
        // RNGstate state;
        srand((int)time(0));
        for (int i=0; i < N; ++i) {
            x = (double)random() / RAND_MAX; 
            y = (double)random() / RAND_MAX;
            z = ((x*x)+(y*y));

            if (z<= 1) {
                counter++;
            }
        }

    } 
    double approx_pi = 4.0 * counter / (NumThreads * N);
    printf("PI: %f \n", approx_pi);
    //printf("%i %1.6e %1.6e\n ", N, approx_pi, fabs(approx_pi - pi) / pi);
    end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("time is: %f \n", time_taken);
    //*end of time measurement
    return 0;
}