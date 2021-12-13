#include <stdio.h>

#define costunit 0.13

int main(void){
	int id;
	float KWhprec, KWhatt, KWh, canone, bolletta;
	
	printf("lettura precedente: ");
	scanf("%f", &KWhprec);
	printf("lettura attuale: ");
	scanf("%f", &KWhatt);
	KWh = KWhatt-KWhprec;
	printf("i KWh da addebitare sono %g \n", KWh);
	printf("la quota fissa è: ");
	scanf("%f", &canone);
	bolletta = canone+KWh*costunit;
	printf("utente %d, l'ammontare della bolletta è %g \n",id, bolletta);
}
