#include <stdio.h>

#define N 30

int MoltMerge(double* a, int lenA, double* b){
    int i;
    for (i = 0; i < lenA - 1; i++){
        b[i] = a[i] * a[i + 1];
    }
    return i;
}

int inputArray(double *a){
    int len = 0;
    do{
        printf("Fornire numero di elementi da prendere in input: ");
        scanf("%d", &len);
    }while(len < 0 || len > 30);

    for (int i = 0; i < len; i++)
        scanf("%lf", &a[i]);
    return len;
}

void printArray(double *a, int len){
    for (int i = 0; i < len; i++)
        printf("%lf ", a[i]);
    printf("\n");
}

int main(void){
    double sorg[N], dest[N];

    int lenSorg = inputArray(sorg);
    int lenDest = MoltMerge(sorg, lenSorg, dest);

    printArray(dest, lenDest);
}