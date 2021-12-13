#include <stdio.h>

int main(void){
    int n;
    printf("Fornire numero di numeri pari (in N) da mostrare ");
    scanf("%d",&n);
    for(int i=2; i<2*n; i+=2){
        printf("%d ",i);        
    }
    printf("\n");
}
