#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define MAX_SIZE 100
void in(int p[MAX_SIZE][2], int i, int n) {
    while (1) {
        if (scanf_s("%d %d", &p[i][0], &p[i][1]) != 2) {
            while (getchar() != '\n');
            printf("������: ������� ��� ����� ����� ����� ������.\n");
            continue;
        }
        if (p[i][0] < 1 || p[i][0] > n || p[i][1] < 1 || p[i][1] > n) {
            printf("������: ����� ������ ���� �� 1 �� %d.\n", n);
            continue;
        }
        break;
    }
}
bool ref(int n, int m, int p[MAX_SIZE][2]) {
    for (int i = 1; i <= n; i++) {
        bool f = false;
        for (int j = 0; j < m; j++) {
            if (p[j][0] == i && p[j][1] == i) {
                f = true;
                break;
            }
        }
        if (!f) return false;
    }
    return true;
}
bool sym(int m, int p[MAX_SIZE][2]) {
    for (int i = 0; i < m; i++) {
        bool f = false;
        for (int j = 0; j < m; j++) {
            if (p[j][0] == p[i][1] && p[j][1] == p[i][0]) {
                f = true;
                break;
            }
        }
        if (!f) return false;
    }
    return true;
}
bool antisym(int m, int p[MAX_SIZE][2]) {
    for (int i = 0; i < m; i++) {
        if (p[i][0] != p[i][1]) {
            for (int j = 0; j < m; j++) {
                if (p[j][0] == p[i][1] && p[j][1] == p[i][0]) {
                    return false;
                }
            }
        }
    }
    return true;
}
bool tran(int m, int p[MAX_SIZE][2]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (p[i][1] == p[j][0]) {
                bool f = false;
                for (int k = 0; k < m; k++) {
                    if (p[k][0] == p[i][0] && p[k][1] == p[j][1]) {
                        f = true;
                        break;
                    }
                }
                if (!f) return false;
            }
        }
    }
    return true;
}
int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    int p[MAX_SIZE][2];
    printf("������� ���������� ��������� ���������: ");
    scanf_s("%d", &n);
    printf("������� ���������� ���: ");
    scanf_s("%d", &m);
    printf("������� ����:\n");
    for (int i = 0; i < m; i++) {
        in(p, i, n);
    }
    bool refl = ref(n, m, p);
    bool symm = sym(m, p);
    bool antisy = antisym(m, p);
    bool transi = tran(m, p);
    printf("��������������: %d\n", refl);
    printf("��������������: %d\n", symm);
    printf("������������������: %d\n", antisy);
    printf("��������������: %d\n", transi);
}