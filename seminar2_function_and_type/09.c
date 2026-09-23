#include <stdio.h>

void bob(int n);

void alice(int n) {
    int res = n * 3 + 1;
    printf("Alice: %i\n", res);
    bob(res);
}

void bob(int n) {
    while (n % 2 == 0) {
        n /= 2;
        printf("Bob: %i\n", n);
    }
    if (n != 1) {
        alice(n);
    }
}

int main() {
    int n;
    scanf("%i", &n);
    alice(n);
    return 0;
}