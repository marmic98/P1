#include <stdio.h>

int main(void){
    float sum=0,voto=0;
    for(int i=0;i<10;i++){
        scanf("%f",&voto);
        sum+=voto;
    }
    float media=sum/10;
    printf("La media voti e' %g\n",media);
}
