#include <stdio.h>

int main(void){
	int n, somma, counter;
	printf("Fornire numero di numeri pari da sommare ");
	scanf("%d", &n);
	for(somma=0, counter=1; counter<=n; counter++)
		somma += 2*counter;
	printf("la somma dei primi %d numeri pari è %d\n", n, somma);
}
