#include <stdio.h>

#define N 5

void minMax(int* a,int len, int* min, int* max){
    *min=a[0];
    *max=a[0];
    for (int i=1;i<len;i++){
        if(a[i]<*min)
            *min=a[i];
        if(a[i]>*max)
            *max=a[i];
    } 
}

int main(void){
    int a[N]={5,56,84,3,0};
    int min=0, max=0;
    minMax(a, N, &min, &max);
    printf("min = %d\nmax = %d\n", min,max);
}
