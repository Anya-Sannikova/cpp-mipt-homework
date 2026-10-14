#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* p = (char*)malloc(sizeof(char) * 9);
    strcpy(p, "Elephant");
    printf("%s\n", p);
    free(p);
    return 0;
}