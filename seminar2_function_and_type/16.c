#include <stdio.h>

double pi_approx(int n) {
    double sum = 0.0;
    double sign = 1.0;
    for (int i = 1; i <= n; i++) {
        sum += sign / (2 * i - 1);
        sign = -sign;
    }
    return 4.0 * sum;
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%f", pi_approx(n));
    return 0;
}