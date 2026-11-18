#include <stdio.h>

union Data
{
    int numbers[4];
    char str[16];
};

int main()
{
    union Data data;
    data.numbers[0] = 1819043144;
    data.numbers[1] = 1461726319;
    data.numbers[2] = 1684828783;
    data.numbers[3] = 2593;
    printf("%s", data.str);
    return 0;
}
