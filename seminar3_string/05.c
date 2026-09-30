#include <stdio.h>

int main()
{
    char str[1000];
    scanf("%s", str);
    long long sum = 0;
    int i = 0;
    while (str[i] != '\0') {
        sum += str[i] - 48;
        i++;
    }
    printf("%lld", sum);
    return 0;
}