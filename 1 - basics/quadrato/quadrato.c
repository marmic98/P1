#include <stdio.h>

float quadrato(float x){ 
	return x*x;
}

int main(void){
	float x;
	printf("inserisci il valore di x: ");
	scanf("%f", &x);
	printf("il quadrato di %g è %g\n", x, quadrato(x));
	return 0;
}
