#include <stdio.h>

int str_to_int(const char* str)
{
    int num = 0;
    int i = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        num = num * 10 + (str[i] - 48);
        i++;
    }
    return num;
}

int main(int argc, char** argv)
{
    char* word = argv[1];
    int count = str_to_int(argv[2]);
    for (int i = 0; i < count; i++) {
        if (i == count - 1) {
            printf("%s", word);
        } else {
            printf("%s ", word);
        }
    }
    return 0;
}