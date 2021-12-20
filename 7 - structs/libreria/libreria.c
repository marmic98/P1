#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIBRI 3
#define MAXLENSTR 30

typedef struct Libro{
    char* editore;
    char* autore;
    char* titolo;
    int anno;
}Libro;

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Allocation failed\n");
        exit(-1);
    }
    return p;
}

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation failed\n");
        exit(-1);
    }
    return p;
}

void readLine(char* s, int len){
    fgets(s, len, stdin);
    int newLen = strlen(s);
    if (s[newLen - 1] == '\n');
        s[newLen - 1] = '\0';
}

char* readString(int len){
    char *s = xmalloc(len);
    readLine(s, len);
    int newLen = strlen(s);
    s = xrealloc(s, newLen);
}

Libro* inputLibro(){
    Libro* libro = xmalloc(sizeof(Libro));
    
    printf("autore: ");
    libro->autore = readString(MAXLENSTR);
    
    printf("titolo: ");
    libro->titolo = readString(MAXLENSTR);
    
    printf("anno di pubblicazione: ");
    scanf("%d",&libro->anno); 
    fflush(stdin);
    
    printf("editore: ");
    libro->editore = readString(MAXLENSTR);
    
    return libro;
}

int piuVecchio(Libro** libreria, int n){
    int piuVecchioIndex = 0;
    int min = libreria[0]->anno;
    for (int i = 0; i< n;i++){
        if (libreria[i]->anno < min){
            piuVecchioIndex = i;
            min = libreria[i]->anno;
        }
    }
    return piuVecchioIndex;
}

void printLibro(Libro** libreria, int n, int index){
    printf("titolo %s\nanno %d\neditore %s\nautore %s\n", libreria[index]->titolo, libreria[index]->anno, libreria[index]->editore, libreria[index]->autore);
}

Libro** inputLibreria(int maxLibri){
    Libro** libreria = xmalloc(sizeof(Libro*) * maxLibri);
    for(int i = 0; i < maxLibri; i++){
        printf("Libro %d/%d\n", i + 1, MAXLIBRI);
        libreria[i] = inputLibro();
    }
    return libreria;
}

int isPresentByAutore (Libro** libreria, int n, char* daCercare){
    for(int i = 0; i < n; i++){
        if (strcmp(daCercare, libreria[i]->autore) == 0)
            return 1;
    }
    return 0;
}

int main(void){
    Libro** libreria = inputLibreria(MAXLIBRI);
    int old = piuVecchio(libreria, MAXLIBRI);
    printf("\nPiu vecchio\n");
    printLibro(libreria, MAXLIBRI, old);
    isPresentByAutore(libreria, MAXLIBRI, "Martino") ? printf("Autore presente\n") : printf("Autore non presente\n"); 
}