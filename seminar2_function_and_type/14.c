#include <stdio.h>

unsigned long long placements(int n, int k) {
    unsigned long long res = 1;
    for (int i = n - k + 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", placements(n, k));
    return 0;
}