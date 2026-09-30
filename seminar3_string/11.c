#include <stdio.h>

void safe_strcpy(char dest[], size_t dest_size, const char src[])
{
    size_t i = 0;
    while (src[i] != '\0' && i < dest_size - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}