#include <stdio.h>

#define N 30

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

void potenza(int* a, int len, int* b, int e){ //simone rompe
    for(int i = 0; i< len; i++){
        b[i] = a[i];
        for (int j = 0; j < e - 1; j++)
            b[i] *= a[i]; 
    }
}

int main(void){
    int a[N], b[N], c[N];
    int len = inputArray(a);
     
    potenza(a, len, b, 2);
    potenza(a, len, c, 3);

    printArray(b, len);
    printArray(c, len);

}