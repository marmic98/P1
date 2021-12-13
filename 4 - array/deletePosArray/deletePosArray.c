#include <stdio.h>

#define N 10

void printArray(int* a,int len){
	for(int i=0; i<len;i++){
		printf("|%d|",a[i]);
	}
	printf("\n");
}

void inputArray(int* a,int len){
	for(int i=0; i<len;i++){
		scanf("%d",&a[i]);
	}
	printf("\n");
}

int delete(int* a, int len, int pos){
    for (pos; pos<len; pos++)
        a[pos]=a[pos+1];
    return len-1;
}

int main(void){
    int a[N], posizione, daInserire, lenA=8;
    
    inputArray(a, lenA);
    printArray(a, lenA);
    
    printf("posizione elemento da eliminare ");
    scanf("%d",&posizione);
    lenA = delete(a, lenA, posizione);
    printArray(a, lenA);
}
