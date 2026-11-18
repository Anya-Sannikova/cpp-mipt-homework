#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "rb");
    fseek(file, -3, SEEK_END);
    for (int i = 0; i < 3; i++) {
        int c = fgetc(file);
        printf("%c", c);
    }
    fclose(file);
    return 0;
}
