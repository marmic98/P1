#include <stdio.h>

#define N 6

void printArray(int* a, int len){
    for(int i=0; i<len;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void inputArray(int* a, int len){
    for(int i=0; i<len;i++){
        scanf("%d", &a[i]);
    }
}

void reversePrint(int* a, int len){
    for(int i=len-1; i>-1; i--){
        printf("%d ",a[i]);       
    }
    printf("\n");
}

int main(void){

    int a[N];
        
    inputArray(a, N);
    printArray(a,N);
    reversePrint(a, N);
    
}
