#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int width = 500;
    int height = 500;
    for (int number = 1; number <= 5; number++) {
        char filename[30];
        sprintf(filename, "function%d.ppm", number);
        FILE* file = fopen(filename, "w");
        fprintf(file, "P3\n%d %d\n255\n", width, height);
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                double x = (i - 250) / 250.0;
                double y = (j - 250) / 250.0;
                double value;
                if (number == 1) {
                    value = 255 * fabs(x * y);
                } else if (number == 2) {
                    value = 255 * fabs(sin(10 * (x*x + y*y)));
                } else if (number == 3) {
                    value = 255 * fabs(sin(5000 * (x*x + y*y)));
                } else if (number == 4) {
                    value = 255 * fabs(cos(10*x) * sin(10*y));
                } else {
                    value = sqrt(255) * fabs(sin(M_PI / (0.1 + fabs(x))) + sin(M_PI / (0.1 + fabs(y))));
                }
                int color = (int)value;
                if (color > 255)
                    color = 255;
                if (color < 0)
                    color = 0;
                fprintf(file, "%d %d %d\n", color, color, color);
            }
        }
        fclose(file);
    }
    return 0;
}
