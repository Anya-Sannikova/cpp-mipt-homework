#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    if (isalpha(c)) {
        printf("Letter");
    } else if (isdigit(c)) {
        printf("Digit");
    } else {
        printf("Other");
    }
    return 0;
}