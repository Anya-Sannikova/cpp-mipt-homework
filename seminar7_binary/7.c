#include <stdio.h>

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "rb");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    printf("%ld\n", size);
    fclose(file);
    return 0;
}
