#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radio.h"

int main(){
    int scelta = 0;
    char artist[50];
    char song[50];
    char songs[20];
    printf("Inserisci nome file\n");
    scanf("%s", songs);
    
    do{
        printf("0 - Cerca brano per artista\n1 - inserisci canzone\n2 - Modifica nome di un artista\n3 - Cancella artista\n4 - Esci\n");
        scanf("%d", &scelta);
        if(scelta == 0){
            printf("Cerca brani di un dato artista\n");
            printf("Fornire nome artista\n");
            scanf("%s", artist);
            findSongbyArtist(artist, songs);
        }
        if(scelta == 1){
            printf("Inserisci canzone\n");
            printf("Fornisci artista\n");
            scanf("%s", artist);
            printf("Fornisci song\n");
            scanf("%s", song);
            insertArtistOrdered(artist, song, songs);
        }
        if(scelta == 2){
            printf("Modifica nome dell'artista\n");
            printf("Artista da moddare: ");
            scanf("%s", artist);
            char toChange[50];
            printf("nuovo nome artista: \n");
            scanf("%s", toChange);
            editArtist(toChange, artist, songs);
        }
        if(scelta == 3){
            printf("Cancella artista\n");
            scanf("%s", artist);
            deleteArtist(artist, songs);
        }
    }while(scelta < 4);
    printf("Arrivederci\n");
}