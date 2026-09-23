#include <stdio.h>

void reverse(int mas[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = mas[i];
        mas[i] = mas[size - 1 - i];
        mas[size - 1 - i] = temp;
    }
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
    reverse(mas, n);
    for (int i = 0; i < n; i++) {
        printf("%i ", mas[i]);
    }
    printf("\n");
    return 0;
}