#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENMAX 40

void readLine (char* s){
    fgets(s, LENMAX, stdin);
    int len = strlen(s);
    if(s[len - 1] == '\n')
        s[len - 1] = '\0';
}

char* readString(int maxLen){
    char *s, *s1; 
    int len;

    s = (char*)malloc(maxLen + 1); //multiplicate for sizeof(char) is useless because size of char is 1 byte
    if (!s) return NULL;

    readLine(s);

    len = strlen(s);

    s1 =(char*) malloc (len +1);

    if(!s1){
        free(s);
        return NULL;
    }

    strcpy(s1, s);
    free(s);
    return s1;
}
//nomi colonna 0 - cognomi colonna 1

//oltre alla normale definizione di array bidimensionale 
//c'è un ulteriore asterisco poichè esso contiene dei puntatori a sua volta
void inputElenco(char* elenco[][2], int k){
    for (int i = 0; i < k; i++){
        printf("Fornire Nome ");
        elenco[i][0] = readString(LENMAX + 1);
        printf("Fornire Cognome ");
        elenco[i][1] = readString(LENMAX+ 1); 
        printf("\n");
    }
}

void cercaCognome(char *elenco[][2], int k, char* cognome){
    int counter = 0;
    for (int i = 0; i < k; i++){
        if (strcmp(elenco[i][1], cognome) == 0){
            printf("%s\n", elenco[i][0]);
            counter++;
        }
    }
    if (counter == 0)
        printf("Nessuna corrispondenza con il cognome richiesto\n");
}

int main(void){
    int k = 3;
    char elenco[k][2];
    inputElenco(elenco, k);
    char cognome[LENMAX];
    printf("Fornisci cognome da cercare ");
    scanf("%s", cognome);
    cercaCognome(elenco, k, cognome);
}