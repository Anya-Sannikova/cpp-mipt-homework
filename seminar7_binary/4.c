#include <stdio.h>

int is_little_endian() {
    int a = 1;
    unsigned char* p = (unsigned char*)&a;
    if (p[0] == 1) {
        return 1;
    }
    return 0;
}

int main() {
    printf("%d\n", is_little_endian());
    return 0;
}
