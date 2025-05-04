#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_SIZE 100
struct Element {
    char let;     
    char num1;    
    char num2; 
    char num3;    
} ;
void inArr(Element* mass, int size, int* rS) {
    for (int i = 0; i < size; ++i) {
        printf("Ââåäèòå ýëåìåíò %d: ", i);
        char in[5]; 
        fgets(in, sizeof(in), stdin);
        getchar(); 
        if (strlen(in) == 4 &&
            (in[0] >= 'a' && in[0] <= 'z') &&
            (in[1] >= '0' && in[1] <= '9') &&
            (in[2] >= '0' && in[2] <= '9') && ((in[1] - '0') % 2 != 0) &&
            (in[3] >= '0' && in[3] <= '9') && ((in[3]-'0')%2==0)) {
            mass[*rS].let = in[0];
            mass[*rS].num1= in[1];
            mass[*rS].num2 = in[2];
            mass[*rS].num3 = in[3];
            (*rS)++;
        } else {
            printf("Error input\n");
            i--;
        }
    }
}
void printArray(Element* mass, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Ýëåìåíò %d: %c%c%c%c\n", i, mass[i].let, mass[i].num1, mass[i].num2, mass[i].num3);
    }
}
void rnotun(Element* mass, int* size) {
    Element uEl[MAX_SIZE];
    int uncnt = 0;
    for (int i = 0; i < *size; ++i) {
        int uniq = 1;
        for (int j = 0; j < uncnt; ++j) {
            if (mass[i].let == uEl[j].let &&
                mass[i].num1 == uEl[j].num1 &&
                mass[i].num2 == uEl[j].num2 &&
                mass[i].num3 == uEl[j].num3) {
                uniq = 0;
                break;
            }
        }
        if (uniq) {
            uEl[uncnt] = mass[i];
            uncnt++;
        }
    }
    for (int i = 0; i < uncnt; ++i) {
        mass[i] = uEl[i];
    }
    *size = uncnt;
}
void unArr(Element* res, int* rS, Element* mass1, int size1, Element* mass2, int size2) {
    for (int i = 0; i < size1; ++i)
        res[(*rS)++] = mass1[i];

    for (int i = 0; i < size2; ++i)
        res[(*rS)++] = mass2[i];

    rnotun(res, rS);
}
void interArr(Element* res, int* rS, Element* mass1, int size1, Element* mass2, int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (mass1[i].let == mass2[j].let &&
                mass1[i].num1 == mass2[j].num1 &&
                mass1[i].num2 == mass2[j].num2 &&
                mass1[i].num3 == mass2[j].num3) {
                res[(*rS)++] = mass1[i];
                break;
            }
        }
    }
}
void diffArr(Element* res, int* rS, Element* mass1, int size1, Element* mass2, int size2) {
    for (int i = 0; i < size1; ++i) {
        int found = 0;
        for (int j = 0; j < size2; ++j) {
            if (mass1[i].let == mass2[j].let &&
                mass1[i].num1 == mass2[j].num1 &&
                mass1[i].num2 == mass2[j].num2 &&
                mass1[i].num3 == mass2[j].num3) {
                found = 1;
                break;
            }
        }
        if (!found) {
            res[(*rS)++] = mass1[i];
        }
    }
}
void symArr(Element* res, int* rS, Element* mass1, int size1, Element* mass2, int size2) {
    diffArr(res, rS, mass1, size1, mass2, size2);
    for (int i = 0; i < size2; ++i) {
        int found = 0;
        for (int j = 0; j < size1; ++j) {
            if (mass2[i].let == mass1[j].let &&
                mass2[i].num1 == mass1[j].num1 &&
                mass2[i].num2 == mass1[j].num2 &&
                mass2[i].num3 == mass1[j].num3) {
                found = 1;
                break;
            }
        }
        if (!found) {
            res[(*rS)++] = mass2[i];
        }
    }
    rnotun(res, rS);
}
int main() {
    setlocale(LC_ALL, "rus");
    int size1, size2;
    Element mass1[MAX_SIZE], mass2[MAX_SIZE], mass_uniq[MAX_SIZE], mass_inter[MAX_SIZE], mass_diff2[MAX_SIZE], mass_diff1[MAX_SIZE], mass_sd[MAX_SIZE];
    int rS1 = 0, rS2 = 0, rS = 0, iS= 0, dS1 = 0, dS2 = 0, sdS = 0;
    printf("Введите размер 1 множества: ");
    scanf_s("%d", &size1);
    getchar();
    inArr(mass1, size1, &rS1);
    printf("\n");
    printf("Введите размер 2 множества: ");
    scanf_s("%d", &size2);
    getchar();
    inArr(mass2, size2, &rS2);
    printf("\n");
    printf("Проверка на уникальность 1 множества:  \n");
    printArray(mass1, rS1);
    printf("\n");
    rnotun(mass1, &rS1);
    printf("Проверка на уникальность 2 множества: \n");
    printArray(mass2, rS2);
    printf("\n");
    rnotun(mass2, &rS2);
    printf("Элементы 1 множества: \n");
    printArray(mass1, rS1);
    printf("\n");
    printf("Элементы 2 множества: \n");
    printArray(mass2, rS2);
    printf("\n");
    unArr(mass_uniq, &rS, mass1, rS1, mass2, rS2);
    printf("Элементы при объединении: \n");
    printArray(mass_uniq, rS);
    printf("\n");
    interArr(mass_inter, &iS, mass1, rS1, mass2, rS2);
    printf("Элементы при пересечении: \n");
    printArray(mass_inter, iS);
    printf("\n");
    diffArr(mass_diff1, &dS1, mass1, rS1, mass2, rS2);
    printf("Элементы A \ B:  \n");
    printArray(mass_diff1, dS1);
    printf("\n");
    diffArr(mass_diff2, &dS2, mass2, rS2, mass1, rS1);
    printf("Элементы B \ A: \n");
    printArray(mass_diff2, dS2);
    printf("\n");
    symArr(mass_sd, &sdS, mass1, rS1, mass2, rS2);
    printf("Симметрическая разность A и B:  \n");
    printArray(mass_sd, sdS);
    printf("\n");
}

