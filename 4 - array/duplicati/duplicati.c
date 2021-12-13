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

int deleteDuplicate(int* a,int len){
	
	for (int j=0;j<len;j++){
		int i=j+1;
		while(i<len){
			if (a[j]==a[i]){
				len=delete(a,i,len);
			}
			else i++;
		}
	}
	return len;
}

int main(void){
	int a[N] = {1,1,1,5,9,5,5};
	int len = deleteDuplicate(a,N);
	printArray(a,len);
}
