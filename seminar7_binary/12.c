#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};

typedef struct color Color;

Color* load_image(char* filename, int* pwidth, int* pheight)
{
    FILE* file = fopen(filename, "rb");
    fscanf(file, "P6\n%d %d\n255\n", pwidth, pheight);
    Color* data = (Color*)malloc(sizeof(Color) * (*pwidth) * (*pheight));
    fread(data, sizeof(Color), (*pwidth) * (*pheight), file);
    fclose(file);
    return data;
}

void save_image(char* filename, Color* data, int width, int height)
{
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), width * height, file);
    fclose(file);
}

void change_colors(Color* data, int width, int height) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int index = i + width * j;
            unsigned char temp = data[index].r;
            data[index].r = data[index].b;
            data[index].b = temp;
        }
    }
}

int main(int argc, char** argv) {
    int width, height;
    Color* data = load_image(argv[1], &width, &height);
    change_colors(data, width, height);
    save_image("result.ppm", data, width, height);
    free(data);
    return 0;
}
