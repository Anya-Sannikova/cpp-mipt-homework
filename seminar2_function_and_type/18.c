#include <stdio.h>
#include <math.h>

double f(double t, double x) {
    return pow(t, x - 1.0) * exp(-t);
}

double gamma_func(double x) {
    const double step = 1e-2;
    const double eps = 1e-10;
    double t = 0.00001;
    double sum = 0.0;
    
    while (1) {
        double trap = (f(t, x) + f(t + step, x)) / 2.0 * step;
        if (trap < eps && t > 1.0) {
            break;
        }
        sum += trap;
        t += step;
    }
    return sum;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%.5f\n", gamma_func(x));
    return 0;
}