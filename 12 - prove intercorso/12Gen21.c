#include <stdio.h>

typedef struct Libro {
    char autore[50];
    char titolo[100];
    int anno;
}Libro;

Libro * libriNuovi(Libro a[], int n, int anno0, int *nNuovi){
    for(int i = 0; i < n; i++){
            if (a[i].anno >= anno0)
                *nNuovi++;
    }

    if (*nNuovi == 0)
        return NULL;

    Libro * aNew = malloc(sizeof(Libro) * *nNuovi);

    for(int i = 0, j = 0; i < *nNuovi; i++){
        if (a[i].anno >= anno0){
            aNew[j] = a[i];
            j++;
        }
    }
    return aNew;
}

int copiaNuovi (FILE * fin, int nLibri, FILE* fout, int anno0){
    int nNuovi = 0;
    Libro a[] = malloc(sizeof(Libro) * nLibri);
    
    if (fread(a, sizeof(Libro), nLibri, fin) != nLibri){
        fprintf(stderr, "Errore lettura");
        fclose(fin);
        fclose(fout);
        free(a);
        exit();
    }
    fclose(fin);

    Libro *aNew = libriNuovi(a, nLibri, anno0, &nNuovi);

    if (!aNew){
        fclose(fout);
        free(a);
        free(aNew);
        return 0;
    }
    else {
        if (fwrite(aNew, sizeof(Libro), nNuovi, fout) != nNuovi){
            fprintf(stderr, "Errore scrittura"); 
            fclose(fout);
            free(a);
            free(aNew);
            exit();
        }
        fclose(fout);
        free(a);
        free(aNew);
        return nNuovi;
    }
}

int main(void){
    // FILE* fin = fopen("fin.bin", 'rb');
    // FILE* fout = fopen("fout.bin", 'rw');
}