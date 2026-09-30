#include <stdio.h>

void encrypt(char* str, int k)
{
    k = (k % 26 + 26) % 26;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = 65 + (str[i] - 65 + k) % 26;
        } else if (str[i] >= 97 && str[i] <= 122) {
            str[i] = 97 + (str[i] - 97 + k) % 26;
        }
    }
}