#include <stdio.h>

unsigned long long fact(int n) {
    unsigned long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int k;
    scanf("%i", &k);
    printf("%llu\n", fact(k));
    return 0;
}