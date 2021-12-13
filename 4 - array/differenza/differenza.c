#include <stdio.h>

#define N 7
#define M 5


int delete(int* a,int pos, int len){
	for(pos;pos<len;pos++){
		a[pos]=a[pos+1];
	}
	return len-1;
}

int differenza(int* a,int* b){
	int len=M;
	for(int i=0;i<N;i++){
		for(int j=0;j<len;j++){
			if (a[i]==b[j]){
				len=delete(b,i,len);
			}
		}
	}
	return len;
}

void printArray(int* a,int len){
	for(int i=0; i<len;i++){
		printf("|%d|",a[i]);
	}
	printf("\n");
}

int main(void){
	int a[N] = {0,2,3,81,5,6,7};
	int b[M] = {0,10,3,81,6};
	printArray(a,N);
	printArray(b,M);
	int newLenB = differenza(a,b);
	printf("B - A = ");
	printArray(b,newLenB);
}
