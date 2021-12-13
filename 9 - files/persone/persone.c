#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona {
    char *nome;
    char *cognome;
    char *codFis;
    int eta;
    int sesso;
}Persona;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }
    return p;
}

Persona* creaPersona (char* nome, char* cognome, char* codFis, int eta, int sesso){
    Persona* p = xmalloc(sizeof(Persona));

    p->nome = nome;
    p->cognome = cognome;
    p->codFis = codFis;
    p->eta = eta;
    p->sesso = sesso;

    return p;
} 

Persona* popolaArchivio(Persona* archivio[], int len){
    
    //for(int i = 0; i < len; i++){
        archivio[0] = creaPersona("Michele", "Martino", "MRTMHL98C10H703A", 23, 1);
        archivio[1] = creaPersona("Pino", "Mauro", "MRAPNI39T15F839P", 81, 1);
        archivio[2] = creaPersona("Maria", "Nazionale", "NZNMRA69L71F839M", 52, 2);
    //}
}

void fileDonne(Persona* archivio[], int len){
    FILE * fp;
    if(fp = fopen("donne.txt", "w")){
        for(int i = 0; i < len; i++){
            if (archivio[i]->sesso == 2){
                fprintf(fp, "%s\n%s\n%s\n%d\n%s\n\n", archivio[i]->nome, archivio[i]->cognome, archivio[i]->codFis, archivio[i]->eta, "Donna");
            }
        }
        fclose(fp);
    }
    else 
        printf("Opening file failed\n");
}

void fileUomini(Persona* archivio[], int len){
    FILE * fp;
    if(fp = fopen("uomini.txt", "w")){
        for(int i = 0; i < len; i++){
            if (archivio[i]->sesso == 1){
                fprintf(fp, "%s\n%s\n%s\n%d\n%s\n\n", archivio[i]->nome, archivio[i]->cognome, archivio[i]->codFis, archivio[i]->eta, "Uomo");
            }
        }
        fclose(fp);
    }
    else 
        printf("Opening file failed\n");
}

void fileMaggiorenni(Persona* archivio[], int len){
    FILE * fp;
    if(fp = fopen("maggiorenni.txt", "w")){
        for(int i = 0; i < len; i++){
            if (archivio[i]->eta > 17){
                fprintf(fp, "%s\n%s\n%s\n%d\n%s\n\n", archivio[i]->nome, archivio[i]->cognome, archivio[i]->codFis, archivio[i]->eta, archivio[i]->sesso == 1 ? "Uomo" : "Donna");
            }
        }
        fclose(fp);
    }
    else 
        printf("Opening file failed\n");
}

void fileCognome(Persona* archivio[], int len, char iniziale){
    FILE * fp;
    if(fp = fopen("cognomi.txt", "w")){
        for(int i = 0; i < len; i++){
            if (archivio[i]->cognome[0] == iniziale){
                fprintf(fp, "%s\n", archivio[i]->cognome);
            }
        }
        fclose(fp);
    }
    else 
        printf("Opening file failed\n");
}

void menu(Persona* archivio[], int len){
    int scelta;
    char iniziale = ' ';
    do{
        printf("1 - File Donne\n2 - File Uomini\n3 - File Maggiorenni\n4 - File Cognome\n5 - Esci\n");
        scanf("%d", &scelta);
        if (scelta == 1){
            fileDonne(archivio, len);
        } 
        if (scelta == 2){
            fileUomini(archivio, len);
        }
        if (scelta == 3){
            fileMaggiorenni(archivio, len);
        }
        if (scelta == 4){
            printf("Fornire iniziale del cognome ");
            scanf(" %c", &iniziale);
            fileCognome(archivio, len, iniziale);
        }
    }while(scelta != 5);
    printf("bye bye\n");
}

int main(void){
    Persona* archivio[3];
    popolaArchivio(archivio, 3);
    menu(archivio, 3);
}