#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);

    int idx = 0;
    for (int nidx = 0; nidx < n; nidx++)
    {
        if (a[nidx] >= 0)
        {
            a[idx] = a[nidx];
            idx++;
        }
    }
    
    for (int i = 0; i < idx; i++)
    {
        printf("%i ", a[i]);
    }
}