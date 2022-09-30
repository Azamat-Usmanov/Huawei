#include <stdio.h>
#include <stdlib.h>

#define RETURN_ERROR(counter) if (counter) {abort(); return 1;} else return 0

int test()
{
    int count = 2;
    if (count) 
    {
        return 1;
    } 
    else 
        return 0;
}

int main() {
    printf("%d", test());
    printf("123");
    return 0;
}