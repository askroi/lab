#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void f(int** r, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
            }
        }
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    printf("Введите количество вершин: ");
    scanf_s("%d", &n);
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Введите матрицу смежности:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }
    int** r = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        r[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            r[i][j] = a[i][j];
        }
    }
    f(r, n);
    printf("Матрица достижимости:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}