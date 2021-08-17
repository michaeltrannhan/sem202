#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
// void serial()
{
    //*time measurement
    clock_t start, end;
    start = clock();

    int input;
    if(argc != 2)
    {
        //printf("Usage: %s number : \n", argv[0]);
        return 1;
    }
    input = atoi(argv[1]);
    // printf("ite is: %d\n", input);

    srand((int)time(0)); //*randomly choose the time seed
    int inside = 0;
    double x, y;
    for(int i =0 ;i < input; i++)
    {
        double scalex = (double)rand()/ RAND_MAX;
        double scaley = (double)rand()/ RAND_MAX;
        x = scalex;
        y = scaley;
        if(x*x + y *y <= 1)
            inside++;

    }
    float ans = 4*((float)inside/input);
    printf("Pi: %f\n", ans);

    end = clock();
    double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    printf("time is: %f \n", time_taken);
    //*end of time measurement
}