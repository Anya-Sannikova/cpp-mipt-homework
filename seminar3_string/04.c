#include <stdio.h>

int main()
{
    char str1[1000], str2[1000];
    scanf("%s %s", str1, str2);
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        len2++;
    }
    int max_len;
    if (len1 > len2)
        max_len = len1;
    else
        max_len = len2;

    for (int i = 0; i < max_len; i++) {
        if (i < len1) {
            printf("%c", str1[i]);
        }
        if (i < len2) {
            printf("%c", str2[i]);
        }
    }
    return 0;
}