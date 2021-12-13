#include <stdio.h>

#define N 30

int alternateMerge(int* a, int lenA, int* b, int lenB, int* c){
    
    int lenC = lenA + lenB;
    int counterA = 0, counterB = 0;
    
    for(int i = 0; i< lenC; i++){
        if(i % 2 == 0){
            c[i] = a[counterA];
            counterA++;
        }
        else{
            c[i] = b[counterB];
            counterB++;
        }
    }

    return lenC;
}

int inputArray(int *a){
    int len = 0;
    do{
        printf("Fornire numero di elementi da prendere in input: ");
        scanf("%d", &len);
    }while(len < 0 || len > 30);

    for (int i = 0; i < len; i++)
        scanf("%d", &a[i]);
    return len;
}

void printArray(int *a, int len){
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void){
    int a[N], b[N], c[2*N];

    int lenA = inputArray(a);
    int lenB = inputArray(b);

    int lenC = alternateMerge(a, lenA, b, lenB, c);

    printArray(c, lenC);
}