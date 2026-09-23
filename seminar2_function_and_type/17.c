#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double eps = 1e-5;

    if (fabs(d - (r1 + r2)) < eps || fabs(d - fabs(r1 - r2)) < eps) {
        printf("Touch\n");
    } else if (d < r1 + r2 && d > fabs(r1 - r2)) {
        printf("Intersect\n");
    } else {
        printf("Do not intersect\n");
    }
    return 0;
}