#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENMAX 30
#define LENCF 16

typedef struct Persona {
    char* nome;
    char* cognome;
    char codiceFiscale[LENCF + 1];
}Persona;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
    }
    return p;
}

void* xrealloc (void* p, size_t size){
    p = realloc(p, size);

    if (!p){
        printf("Allocation failed\n");
        return NULL;
    }

    return p;
}

int isMaiusc(char c){
    return c >= 'A' && c <= 'Z';
}


int isNumber(char c){
    return c >= '0' && c <= '9';
}

void upper (char* str){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
}

void readLine (char* str){
    fgets(str, LENMAX, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

char* readString (int lenMax){
    char* s = xmalloc(lenMax * sizeof(char));
    readLine(s);

    int len = strlen(s);

    s = xrealloc(s, len * sizeof(char));

    return s;
}

int verificaCF(char* cf){
    if (strlen(cf) != LENCF)
        return 0;

    for(int i = 0; i < 16; i++){
        if (i == 6 || i == 7 || i == 9 || i == 10 || i == 12 || i == 13 || i == 14){
            if (!isNumber(cf[i]))
                return 0;
        }
        else if (!isMaiusc(cf[i]))
            return 0;
    }
    return 1;
}


Persona* inputPersona (char* nome, char* cognome, char* codiceFiscale){
    Persona* p = xmalloc(sizeof(Persona));

    //printf("Fornire nome ");
    p->nome = nome;//readString(LENMAX);
    
    //printf("Fornire cognome ");
    p->cognome = cognome;//readString(LENMAX);
    
    do{
        //printf("Fornire codice fiscale ");
        strcpy(p->codiceFiscale, codiceFiscale);
        //readLine(p->codiceFiscale);
        upper(p->codiceFiscale);
    }while(!verificaCF(p->codiceFiscale));
    
    return p;
}

void printPersona (Persona* p){
    printf("nome: %s\ncognome: %s\nCodice fiscale: %s\n", p->nome, p->cognome, p->codiceFiscale);
}

int main(void){
    Persona* p;
    p = inputPersona("Michele", "Martino", "mrtmhl98c10h703a");
    printPersona(p);
    free(p);
}