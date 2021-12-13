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

void reverse(int* a, int len){
    for(int i=0; i<len/2; i++){
        int temp=0;
        a[i] = a[i] + a[len-1-i];
        a[len-1-i] = a[i] - a[len-1-i];
        a[i] = a[i] - a[len-1-i];
    }
}

int main(void){

    int a[N];
        
    inputArray(a, N);
    printArray(a,N);
    reverse(a, N);
    
    printArray(a,N);
}
