#include <stdio.h>

#define N 7

void printArray(int* a,int len){
	for(int i=0; i<len;i++){
		printf("|%d|",a[i]);
	}
	printf("\n");
}

int delete(int* a,int pos, int len){
	for(pos;pos<len;pos++){
		a[pos]=a[pos+1];
	}
	return len-1;

}

int occorrenzeMultiple(int* a,int len){
	int i=0;
	while(i<len){
		if (a[i]==a[i+1]){
			len=delete(a,i,len);
		}
		else i++;
	}
	return len;
}


int main(void){
	int a[N] = {1,1,1,5,9,9,5};
	int len = occorrenzeMultiple(a,N);
	printArray(a,len);
}
