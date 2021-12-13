#include <stdio.h> 

float calcolaCommissione(float quota, float perc, float valore){
	return (quota + perc * valore /100);
}

int main(void){
	float valore, commissione;
	printf("insert trade value: \n");
	scanf("%g", &valore);
	if (valore < 2500){
		commissione = calcolaCommissione(30, 1.7, valore);
    }
	else if (valore < 6250){
		commissione = calcolaCommissione(56, 0.66, valore);
	}
	else if (valore < 20000){
		commissione = calcolaCommissione(76, 0.34, valore);
	}
	else if (valore < 50000){
		commissione = calcolaCommissione(100, 0.22, valore);
	}
	else if (valore < 500000){
		commissione = calcolaCommissione(155, 0.11, valore);
	}
	else{
		commissione = calcolaCommissione(255, 0.09, valore);
	}
	if (commissione < 39)
		commissione = 39;
	printf("commission: $%g\n", commissione);
	return 0;
}
