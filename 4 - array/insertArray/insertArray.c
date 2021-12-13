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

int insert(int* a, int len, int pos, int daInserire){
    for (int i = len; i>pos; i--)
        a[i]=a[i-1];
    a[pos]=daInserire;
    return len+1;
}

int main(void){
    int a[N], posizione, daInserire, lenA=8;
    inputArray(a, lenA);
    printf("elemento da inserire ");
    scanf("%d",&daInserire);
    printf("posizione elemento da inserire ");
    scanf("%d",&posizione);
    lenA = insert(a, lenA, posizione, daInserire);
    printArray(a, lenA);
}
