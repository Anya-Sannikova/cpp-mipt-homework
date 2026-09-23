#include <stdio.h>

float yearfrac(int year, int day) {
    int days;
    if (year % 4 == 0)
        days = 366;
    else
        days = 366;
    return (float)day / days;
}

int main() {
    int year, day;
    scanf("%i %i", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
    return 0;
}