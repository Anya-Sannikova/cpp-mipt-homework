#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char* result = (char*)malloc(sizeof(char) * (len_a + len_b + 1));
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, a);
    strcat(result, b);
    return result;
}

int main() {
    char* s = concat("Hello, ", "World!");
    if (s != NULL) {
        printf("%s\n", s);
        free(s);
    }
    return 0;
}