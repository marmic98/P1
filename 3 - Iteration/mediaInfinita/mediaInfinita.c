#include <stdio.h> 

int main(void){

	int counter=0;
	float sum=0, media=0, voto=0;

	while (voto != -1){
		printf("inserisci voto: ");
		scanf("%g",&voto);
		if (voto >= 18 && voto <= 30){
			sum += voto;
			counter++;
		}
		else if (voto == -1)
		    printf("Calcolo della media\n");
		else
		    printf("valore non valido\n");
	}
	
	media = sum/counter;
	printf("la media voti e': %g\n", media);
}
