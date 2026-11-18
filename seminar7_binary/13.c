#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};

typedef struct color Color;

Color* load_image(char* filename, int* pwidth, int* pheight) {
    FILE* file = fopen(filename, "rb");
    fscanf(file, "P6\n%d %d\n255\n", pwidth, pheight);
    Color* data = (Color*)malloc(sizeof(Color) * (*pwidth) * (*pheight));
    fread(data, sizeof(Color), (*pwidth) * (*pheight), file);
    fclose(file);
    return data;
}

void save_image(char* filename, Color* data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), width * height, file);
    fclose(file);
}

void make_sepia(Color* data, int width, int height) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int index = i + width * j;
            double r = data[index].r;
            double g = data[index].g;
            double b = data[index].b;
            double new_r = 0.393*r + 0.769*g + 0.189*b;
            double new_g = 0.349*r + 0.686*g + 0.168*b;
            double new_b = 0.272*r + 0.534*g + 0.131*b;
            if (new_r > 255)
                new_r = 255;
            if (new_g > 255)
                new_g = 255;
            if (new_b > 255)
                new_b = 255;
            data[index].r = new_r;
            data[index].g = new_g;
            data[index].b = new_b;
        }
    }
}

int main(int argc, char** argv)
{
    int width, height;
    Color* data = load_image(argv[1], &width, &height);
    make_sepia(data, width, height);
    save_image("result.ppm", data, width, height);
    free(data);
    return 0;
}
