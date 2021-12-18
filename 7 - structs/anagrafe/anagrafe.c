#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENMAX 30
#define LENCF 16
#define MAXPER 3

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
    fflush(stdin);
    fflush(stdout);
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

Persona* inputPersona (){
    Persona* p = xmalloc(sizeof(Persona));
        printf("Fornire nome ");
        p->nome = readString(LENMAX);
        
        printf("Fornire cognome ");
        p->cognome = readString(LENMAX);
        
        do{
            printf("Fornire codice fiscale ");
            readLine(p->codiceFiscale);
            upper(p->codiceFiscale);
        }while(!verificaCF(p->codiceFiscale));
        printf("\n");
    return p;
}

Persona** inputPersone(Persona** p, int numPersone){
    p = xmalloc(sizeof(Persona*) * numPersone);
    for (int i = 0; i< numPersone; i++){
        printf("Persona %d\n", i + 1);
        p[i] = inputPersona();
    }
    return p;
}

void freeAll(Persona** p, int k){
    for (int i = 0; i < k; i++){
        free(p[i]);
    }
}

void printPersona (Persona** p, int k){
    for(int i = 0; i < k; i++){
        printf("nome: %s\ncognome: %s\nCodice fiscale: %s\n\n", p[i]->nome, p[i]->cognome, p[i]->codiceFiscale);
    }
}


int byCognome(Persona** p, char* cognome, int k){
    int counter = 0;
    for (int i = 0; i < k; i++){
        if ((strcmp(p[i]->cognome, cognome) == 0)){
            counter += 1;
        }
    }
    return counter;
}

int byCodFis(Persona** p, char* codFis, int k){
    int counter = 0;
    for (int i = 0; i < k; i++){
        if ((strcmp(p[i]->codiceFiscale, codFis) == 0)){
            counter += 1;
        }
    }
    return counter;
}

Persona** searchByNomeCognome(Persona** p, Persona** pNew, char* nome, char* cognome, int k, int* j){
    printf("Le persone il cui cognome e nome sono %s %s sono:\n", cognome, nome);
    pNew = xmalloc(sizeof(Persona*));
    for (int i = 0; i < k; i++){
        if ((strcmp(p[i]->nome, nome) == 0) && (strcmp(p[i]->cognome, cognome) == 0)){
            pNew[*j] = p[i];
            *j += 1;
            pNew = xrealloc(pNew, sizeof(Persona*) * (*j + 1));
        }
    }
    printPersona(pNew, *j);
    return pNew;
}

int numberPeople(){
    int k = 0;
    do{
        printf("Quante persone si desiderano inserire nell'archivio ");
        scanf("%d", &k);
        fflush(stdin);
    }while(k > MAXPER);
    return k;
}

int main(void){
    int k = numberPeople();
    int choice = 0;
    
    printf("Popolamento Archivio\n");
    Persona** p = inputPersone(p ,k);
    do{
        printf("1 - Ricerca per codice fiscale\n2 - Ricerca per cognome\n3 - Crea sottoelenco relativo ad uno specifico nome e cognome\n4 - Mostra Archivio\n5 - Esci\nScelta: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1){
            printf("Fornire CF: ");
            char cf[LENCF+1];
            readLine(cf);
            upper(cf);
            printf("Persone con codice fiscale %s presenti sono %d\n", cf, byCodFis(p, cf, k));
            
        }
        if (choice == 2){
            printf("Fornire Cognome: ");
            char* cognome = readString(LENMAX);
            printf("Persone con Cognome %s presenti sono %d\n", cognome, byCognome(p, cognome, k));
        }
        if (choice == 3){
            int j = 0;
            char* nome; 
            char* cognome;
            printf("Fornire Nome: "); 
            nome = readString(LENMAX);
            printf("Fornire Cognome: ");
            cognome = readString(LENMAX);
            Persona** pNew = searchByNomeCognome(p, pNew, nome, cognome, k, &j);
        }
        if (choice == 4){
            printPersona(p, k);
        }
    }while(choice < 5);
    printf("Ciao ciao\n");
    freeAll(p, k);
}