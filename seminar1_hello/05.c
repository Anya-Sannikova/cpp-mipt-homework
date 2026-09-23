#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%i", &n);
    int max = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%i", &a);
        if (a > max)
        {
            max = a;
            cnt = 1;
        }
        else if (a == max)
            cnt++;
    }
    printf("Max = %i, Count = %i\n", max, cnt);
}