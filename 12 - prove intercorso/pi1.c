#include <stdio.h>

void printArray(int* a, int len){
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int elimina(int* a, int n, int pos){
    for (pos; pos < n; pos++){
        a[pos] = a[pos + 1];
    }
    return n - 1;
}

int isInteressante(int n){
    return n >= 0 && n % 3 == 1 && n % 2 != 0;
}

int cancellaNoiosi(int* a, int n){
    int i = 0;
    while (i < n){
        if (!isInteressante(a[i])){
            n = elimina(a, n, i);
        }
        else{
            i++;
        }
    }
    return n;
}

int main(void){
    int a[] = {-7, 10, 13, 2, 1, 21};
    int len = cancellaNoiosi(a, 6);
    printArray(a, len);
}