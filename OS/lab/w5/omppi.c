#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
int main(int argc, char *argv[])
{
	long niter = 100000000; //number of iterations per FOR loop
	double x, y;		//x,y value for the random coordinate
	int i;				//loop counter
	int count = 0;		//Count holds all the number of how many good coordinates
	double z;			//Used to check if x^2+y^2<=1
	double pi;			//holds approx value of pi
	int numthreads = 4;
	clock_t start, end;
	start = clock();
	
#pragma omp parallel firstprivate(x, y, z, i) reduction(+ \
														: count) num_threads(numthreads)
	{
		//srand48((int)time(NULL)); //Give random() a seed value
		unsigned int rand_state = random() - RAND_MAX / 2 - 1;
		for (i = 0; i < niter; ++i)						 //main loop
		{
			// x = (double)drand48()/RAND_MAX;	 //gets a random x coordinate
			// y = (double)drand48()/RAND_MAX;	 //gets a random y coordinate

			// x = (double)random() / RAND_MAX; //gets a random x coordinate
            // y = (double)random() / RAND_MAX; //gets a random y coordinate

			x = 1.0 * rand_r(&rand_state) / RAND_MAX;
        	y = 1.0 * rand_r(&rand_state) / RAND_MAX;

			z = ((x * x) + (y * y)); //Checks to see if number is inside unit circle
			if (z <= 1)
			{
				++count; //if it is, consider it a valid random point
			}
		}
	}
	pi = ((double)count / (double)(niter * numthreads)) * 4.0;
	printf("Pi: %f\n", pi);
	end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("time is: %f \n", time_taken);
	return 0;
}
