#include <stdio.h>

#define N 6
#define M 8

void printArray(int* a, int len){
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int contains(int* array, int len, int daCercare){
    int i = 0;
    while(i<len && ((array[i]+array[i+1])!=daCercare)){
        i++;
    }
    return i<len; //se i < len vuol dire che l'elemendo daCercare è presente nell'array
}

int filtroSum(int* a, int lenA, int* b, int lenB, int* c, int lenC){

    for (int i = 0; i<lenA; i++){
        if(contains(b, lenB,a[i])){
            c[lenC]=a[i];
            lenC++;
        }
    }
    return lenC;
}

int main(void){
    int a[N] = {-7,9,33,-100,21,6};
    int b[M] = {55,34,1,3,3,20,-5,26}; 
    int c[N];
    int lenA= N, lenB=M, lenC=0;    
    lenC = filtroSum(a, lenA, b, lenB, c, lenC);
    printArray(c, lenC);
}