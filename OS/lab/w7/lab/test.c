#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define OFF_LEN 12

typedef uint32_t address_t;
typedef uint32_t index_t;
typedef uint32_t offset_t;

index_t getIndex(address_t address)
{
    return (address >> OFF_LEN);
}

int main()
{
    address_t add;
    
    printf("%x", (add << OFF_LEN));
    return 0;
}
