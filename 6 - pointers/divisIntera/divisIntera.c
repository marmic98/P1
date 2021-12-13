#include <stdio.h>

void divisIntera (int n, int div, int* q, int* r){

    *q=n/div;
    *r=n%div;
} 

int main(void){
    int quoziente, resto;

    divisIntera(15,4,&quoziente, &resto);
    printf("15/4\nquoziente = %d resto = %d\n",quoziente, resto);
}
