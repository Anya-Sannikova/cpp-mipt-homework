#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n) {
    float* arr = (float*)malloc(sizeof(float) * n);
    if (arr == NULL) {
        return NULL;
    }
    float current = a;
    for (int i = 0; i < n; i++) {
        arr[i] = current;
        current *= r;
    }
    return arr;
}

int main() {
    float* p = get_geometric_progression(1.0f, 3.0f, 10);
    if (p != NULL) {
        for (int i = 0; i < 10; i++) {
            printf("%.0f ", p[i]);
        }
        printf("\n");
        free(p);
    }
    return 0;
}