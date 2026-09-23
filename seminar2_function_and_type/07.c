#include <stdio.h>

int count_even(int mas[], int size) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] % 2 == 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int mas[1000];
    int size = 0;
    char c;
    while (1) {
        scanf("%i%c", &mas[size], &c);
        size++;
        if (c == '\n') {
            break;
        }
    }
    int n;
    scanf("%i", &n);
    printf("%i\n", count_even(mas, n));
    return 0;
}