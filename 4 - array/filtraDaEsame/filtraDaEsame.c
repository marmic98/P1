#include <stdio.h>
#include <math.h>

#define N 6

void printArray(int *a, int len){
    for (int i = 0; i < len; i++){
        if (a[i] != 0)
            printf("%d ", a[i]);
    }
    printf("\n");
}

int nCifre (int n){
    int nCifre = 0;
    
    while (n > 0){
        n /= 10;
        nCifre++;
    }
    return nCifre;
}

int divideEtSum(int n, int nCifre){
    int sum = 0;
    while(nCifre - 1 >= 0){
        sum += (n / (int)pow(10, nCifre-1)) % 10;
        nCifre -= 1;
    }
    return sum;
}

int isSei(int n){
    return  divideEtSum(n, nCifre(n)) == 6;
}

int filtraDaEsame (int* a, int n){
    for(int i = 0; i < n; i++){
        if(!isSei(a[i]))
            a[i] = 0;   
    }
}

int main(void){
    int a[N] = {123, 56, 0, 321, 42, 114};

    filtraDaEsame(a, N);

    printArray(a, N);
}