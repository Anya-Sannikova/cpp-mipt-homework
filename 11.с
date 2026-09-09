#include <stdio.h>

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);

    int sum[m] = {0};

    for (int i = 0; i < n * m; i++)
    {
        int a;
        scanf("%i", &a);
        sum[i % m] += a;
    }

    for (int j = 0; j < m; j++)
        printf("%i ", sum[j]);
}