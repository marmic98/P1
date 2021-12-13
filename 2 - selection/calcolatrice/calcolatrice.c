#include <stdio.h>

int main(void){
    float a, b, sum, diff, molt, div;
    
    printf("inserisci il primo numero: ");
    scanf("%f", &a);
    printf("inserisci il secondo numero: ");
    scanf("%f", &b);
    
    sum = a+b;
    diff = a-b;
    molt = a*b;
    div = a/b;
    
    printf("la somma è %g\n", sum);
    printf("la differenza è %g\n", diff);
    printf("il prodotto è %g\n", molt);
    printf("il quoziente è %g\n", div);
}
