#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Acquisto{
    char descrizione[30];
    double quantita;
    double prezzoUnitario;
}Acquisto;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }
    return p;
}

Acquisto *leggiAcquisti(FILE* fin, int *nAcquisti){

    fscanf(fin, "%d", nAcquisti);
    Acquisto *acquisti = xmalloc(sizeof(Acquisto)* *nAcquisti);
    int i = 0;
    for (i; i < *nAcquisti; i++){
        if (fscanf(fin, "%s", acquisti[i].descrizione) != 1) break;
        
        if (fscanf(fin, "%lf", &acquisti[i].quantita) != 1) break;
        
        if (fscanf(fin, "%lf", &acquisti[i].prezzoUnitario) != 1) break;
        
    }
    *nAcquisti = i;
    fclose(fin);
    return acquisti;
}


double spesaTotale(Acquisto *acquisti, int nAcquisti){
    double tot = 0;
    for (int i = 0; i < nAcquisti; i++){
            tot += acquisti[i].prezzoUnitario * acquisti[i].quantita;
    }
    return tot;
}

void scontrino(Acquisto *acquisti, int nAcquisti){
    for (int i = 0; i < nAcquisti; i++){
            printf("descrizione: %s\nquantita': %g\nprezzo unitario: %g\n", acquisti[i].descrizione, acquisti[i].quantita, acquisti[i].prezzoUnitario);
            printf("\n");        
    }
    printf("spesa totale = %g\n", spesaTotale(acquisti, nAcquisti));
}

int main(void){
    FILE* fin; 
    int nAcquisti = 0;
    if(fin = fopen("elenco.txt", "r")){
        Acquisto *acquisti = leggiAcquisti(fin, &nAcquisti);
        scontrino(acquisti, nAcquisti);
    }
    else printf ("Apertura file fallita\n");
}