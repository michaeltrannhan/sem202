#include <sys/types.h>
#include <unistd.h>

void *simple_malloc(size_t size)
{
    void *p;
    p = sbrk(0);

    //* if sbrk fails we return NULL
    if(sbrk(size) == (void*)-1)
        return NULL;
    return p;
}

