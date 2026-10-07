#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double eps = 1e-10;
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            return 0;
        }
        *px1 = -c / b;
        return 1;
    }

    double d = b * b - 4 * a * c;
    if (d < -eps) {
        return 0;
    } else if (fabs(d) < eps) {
        *px1 = -b / (2 * a);
        return 1;
    } else {
        *px1 = (-b - sqrt(d)) / (2 * a);
        *px2 = (-b + sqrt(d)) / (2 * a);
        return 2;
    }
}
