#include <stdio.h>

void mult2_ptr(int* p, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        *(p + i) *= 2;
    }
}


void mult2_arr(int* p, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] *= 2;
    }
}


int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    mult2_ptr(arr1, size1);
    for (size_t i = 0; i < size_t size1; i++) {
        printf("%i ", arr[i]);
    }
    return 0;
}