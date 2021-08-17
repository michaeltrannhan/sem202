#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    if (fork())
    {
        // B
        if (fork())
        {
            // C
            if (fork())
            {
                // D
            }
            else
            {
            }
        }
        else
        {
            fork();
            // G
        }
    }
    else
    {
        if (fork())
        {
            // E}
            if (fork())
            {
                // F
            }
            else
            {
                fork();
                // I
            }
        }
    }
        pause();
        return 0;
    }