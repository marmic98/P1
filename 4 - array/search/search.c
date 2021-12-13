#include <stdio.h>

#define N 10

int contains(int* a, int len, int daCercare){

    len -= 1;
    while(len>=0  && a[len]!=daCercare)
        len--;
    if (len >= 0)    
        return len; //se len < 0 elemento non trovato
    else return -1;
}

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

int main(void){
    int a[N]={0,1,2,3,4,5,6,7,8,9};
    int daCercare, lenA=8;
    
    printArray(a, lenA);
    
    printf("Elemento da cercare ");
    scanf("%d",&daCercare);
    int found = contains(a, lenA, daCercare);
    found==-1 ? printf("Elemento non presente\n") : printf("Elemento presente in posizione %d\n",found);
}

