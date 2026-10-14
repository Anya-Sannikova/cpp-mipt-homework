#include <stdio.h>
#include <stdlib.h>

int diff(int x, int y) {
    return x - y;
}

int sum(int x, int y) {
    return x + y;
}

int mult(int x, int y) {
    return x * y;
}

int sqdiff(int x, int y) {
    return x * x - y * y;
}

int lin(int x, int y) {
    return 5 * x - y;
}

typedef int (*FuncPtr)(int, int);

void print_func_name(FuncPtr p) {
    if (p == sum) {
        printf("sum\n");
    } else if (p == diff) {
        printf("diff\n");
    } else if (p == mult) {
        printf("mult\n");
    } else if (p == sqdiff) {
        printf("sqdiff\n");
    } else if (p == lin) {
        printf("lin\n");
    } else {
        printf("other\n");
    }
}

FuncPtr array[5] = {sum, diff, mult, sqdiff, lin};

void print_array_names(FuncPtr* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        print_func_name(array[i]);
    }
}

void sort_funcs(FuncPtr* a, size_t n, int x, int y) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (a[i](x, y) > a[j](x, y)) {
                FuncPtr temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    print_array_names(array, 5);
    printf("---\n");
    sort_funcs(array, 5, 2, 2);
    print_array_names(array, 5);
    printf("---\n");
    sort_funcs(array, 5, 8, 1);
    print_array_names(array, 5);
    return 0;
}