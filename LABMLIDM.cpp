#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define MAX_SIZE 100
bool fun(int n, int m, int a[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        int q = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                q++;
            }
        }
        if (q != 1) {
            return false;
        }
    }
    return true;
}
int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    int a[MAX_SIZE][MAX_SIZE];
    printf("¬ведите количество строк матрицы: ");
    scanf_s("%d", &n);
    printf("¬ведите количество столбцов матрицы: ");
    scanf_s("%d", &m);
    printf("¬ведите матрицу отношени€ %dx%d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }
    bool r = fun(n, m, a);
    printf("–езультат:\n");
    if (r) {
        printf("1");
    }
    else {
        printf("0");
    }
}