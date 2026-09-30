#include <stdio.h>

int main()
{
    char c;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        printf("Letter");
    } else if (c >= '0' && c <= '9') {
        printf("Digit");
    } else {
        printf("Other");
    }
    return 0;
}