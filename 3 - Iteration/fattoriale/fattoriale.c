#include <stdio.h>

long double fattoriale(long double n){
	long double fattoriale=1;
	if (n<2)
		return fattoriale;
	else{
		for(n;n>=2;n--){
			fattoriale*=n;
		}
	}
	return fattoriale;
}	

int main(){
	long double n;
	printf("Calcolo del fattoriale\nFornisci valore: ");
	scanf("%Lf",&n);
	printf("Il fattoriale di %Lg e' %Lg\n",n,fattoriale(n));
}
