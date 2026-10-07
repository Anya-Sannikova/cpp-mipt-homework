#include <stdio.h>

void cube(float* px)
{
    *px = (*px) * (*px) * (*px);
}

int main()
{
    float n = 2.5;
    cube(&n);
    printf(n);
    return 0;
}