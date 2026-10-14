#include <stdio.h>

#define SIZE 1000000000ULL

int main()
{
    getchar();
    printf("Allocating memory on stack...\n");
    char data[SIZE];

    getchar();
    data[0] = 'A';
    printf("First char = %c\n", data[0]);

    return 0;
}