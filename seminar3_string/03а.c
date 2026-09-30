#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c) != 1;
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        printf("Letter");
    } else if (c >= 48 && c <= 57) {
        printf("Digit");
    } else {
        printf("Other");
    }
    return 0;
}