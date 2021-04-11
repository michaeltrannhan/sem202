#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv[])   
{
    size_t MB = 1024*1024; // # of bytes for al locat ing
    size_t maxMB = 0;
    void *ptr = NULL;

    do
    {
        if(ptr != NULL)
        {
            printf("Bytes of memory checked = %zi \n", maxMB);
            memset(ptr, 0, maxMB); // f i l l the al located region
        }
        maxMB += MB;
        ptr = malloc(maxMB);
    } while (ptr != NULL);

    return 0;
}