#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void blur(Color* data, Color* result, int width, int height)
{
    memcpy(result, data, sizeof(Color) * width * height);
    for (int j = 1; j < height - 1; j++) {
        for (int i = 1; i < width - 1; i++) {
            int sum_r = 0;
            int sum_g = 0;
            int sum_b = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int index = (i + dx) + width * (j + dy);
                    sum_r += data[index].r;
                    sum_g += data[index].g;
                    sum_b += data[index].b;
                }
            }
            int index = i + width * j;
            result[index].r = sum_r / 9;
            result[index].g = sum_g / 9;
            result[index].b = sum_b / 9;
        }
    }
}

int main(int argc, char** argv)
{
    int n = atoi(argv[2]);
    int width, height;
    Color* data = load_image(argv[1], &width, &height);
    Color* result = (Color*)malloc(sizeof(Color) * width * height);
    for (int k = 0; k < n; k++) {
        blur(data, result, width, height);
        memcpy(data, result, sizeof(Color) * width * height);
    }
    save_image("result.ppm", data, width, height);
    free(data);
    free(result);
    return 0;
}
