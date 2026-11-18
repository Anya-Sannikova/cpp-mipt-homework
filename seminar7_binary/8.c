#include <stdio.h>

int main() {
    int width = 600;
    int height = 400;
    FILE* file = fopen("japan.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", width, height);
    int x0 = 300;
    int y0 = 200;
    int radius = 120;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int dx = i - x0;
            int dy = j - y0;
            if (dx * dx + dy * dy <= radius * radius) {
                fprintf(file, "190 0 41\n");
            } else {
                fprintf(file, "255 255 255\n");
            }
        }
    }
    fclose(file);
    return 0;
}
