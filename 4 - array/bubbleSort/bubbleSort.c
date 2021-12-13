#include <stdio.h>

#define N 6

void printArray(int* a,int len){
	for(int i=0; i<len;i++){
		printf("|%d|",a[i]);
	}
	printf("\n");
}

int swap(int* a, int* b){
    *a=*a+*b;                    
    *b=*a-*b;
    *a=*a-*b;  
}

int sort(int* a){
    for(int j=0;j<N-1;j++){
        for (int i=0;i<N-j-1;i++){
            if (a[i]>a[i+1]){
                //a[i]=a[i]+a[i+1];                    
                //a[i+1]=a[i]-a[i+1];
                //a[i]=a[i]-a[i+1];
                swap(&a[i],&a[i+1]);
            }    
        }    
    }
}

int main(){
    int a[N]={25,3,1,98,56,278};
    sort(a);
    printArray(a,N);
}
