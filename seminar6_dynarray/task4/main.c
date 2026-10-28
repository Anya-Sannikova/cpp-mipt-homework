#include <stdio.h>

int main()
{
#ifndef COUNT                      
    printf("No count!\n");
#elif COUNT > 100                   
    printf("Count is too large!\n");
#elif defined(REVERSE)              
    for (int i = COUNT; i >= 1; --i)
        printf("%i ", i);
    printf("\n");
#else
    for (int i = 1; i <= COUNT; ++i)
        printf("%i ", i);
    printf("\n");
#endif
}
