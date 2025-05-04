#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <locale.h>
#define S 11
void f(int g[S][S], int n, int s, int e) {
    int d[S];
    bool v[S];
    int p[S];
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
        v[i] = false;
        p[i] = -1;
    }
    d[s] = 0;
    for (int c = 1; c <= n - 1; c++) {
        int m = -1;
        int md = 1e9;
        for (int u = 1; u <= n; u++) {
            if (!v[u] && d[u] < md) {
                md = d[u];
                m = u;
            }
        }
        if (m == -1) break;
        v[m] = true;
        for (int u = 1; u <= n; u++) {
            if (g[m][u] > 0 && !v[u]) {
                int nd = d[m] + g[m][u];
                if (nd < d[u]) {
                    d[u] = nd;
                    p[u] = m;
                }
            }
        }
    }
    printf("���������� ���� �� %d �� %d: ", s, e);
    if (d[e] == 1e9) {
        printf("���� �� ����������!\n");
        return;
    }
    int pa[S];
    int pl = 0;
    for (int a = e; a != -1; a = p[a]) {
        pa[pl++] = a;
    }
    for (int i = pl - 1; i >= 0; i--) {
        printf("%d", pa[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n����� ����: %d\n", d[e]);
}
int main() {
    setlocale(LC_ALL, "rus");
    int n, g[S][S] = { 0 }, s, e;
    printf("������� ���������� ������:");
    scanf_s("%d", &n);
    printf("������� ������� ��������� %dx%d:\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf_s("%d", &g[i][j]);
            if (i > j && g[i][j] != g[j][i]) {
                printf("������: ������� ��������� ������ ���� ������������!\n");
                printf("�������� [%d][%d] ������ ���� ����� [%d][%d]\n", i, j, j, i);
                return 1;
            }
        }
    }
    printf("������� ��������� �������: ");
    scanf_s("%d", &s);
    printf("������� �������� �������: ");
    scanf_s("%d", &e);
    f(g, n, s, e);
}