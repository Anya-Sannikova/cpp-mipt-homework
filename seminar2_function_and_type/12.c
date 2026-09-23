#include <stdio.h>
#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k) {
    assign(C, A, n);
    for (int step = 1; step < k; step++) {
        float temp[MAX][MAX];
        multiply(C, A, temp, n);
        assign(C, temp, n);
    }
}

int main() {
    int n, k;
    scanf("%i %i", &n, &k);
    float A[MAX][MAX], C[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    power(A, C, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}