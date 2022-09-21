#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findSongbyArtist(char* artistRef, char* songs){
    FILE* f;
    char artist[50];
    char song[50];
    if((f = fopen(songs, "r")) == NULL){
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    else{
        while(fscanf(f, "%s%s", artist, song) == 2){
            if(!strcmp(artistRef, artist))
                printf("artist: %s\nsong: %s\n", artist, song);
        }
    }
    printf("\n");
    fclose(f);
}

void insertSong(char* artist, char* song, char* songs){
FILE* f;
    if((f = fopen(songs, "r")) == NULL){
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    else{
        fprintf(f, "%s %s\n", artist, song);
    }
    printf("\n");
    fclose(f);
}

void insertArtistOrdered(char* artistRef, char* songRef ,char* songs){
    FILE* f;
    FILE* fTemp = fopen("fTemp.txt", "w");
    char artist[50];
    char song[50];
    int flag = 0;
    if((f = fopen(songs, "r")) == NULL){
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    else{
        while(fscanf(f, "%s %s", artist, song) == 2){
            if(strcmp(artistRef, artist) <= 0 && flag == 0){
                fprintf(fTemp, "%s %s\n", artistRef, songRef);
                fprintf(fTemp, "%s %s\n", artist, song);
                flag = 1;
            }
            else 
                fprintf(fTemp, "%s %s\n", artist, song);
        }
    }
    printf("\n");
    fclose(f);
    fclose(fTemp);
    remove(songs);
    rename("fTemp.txt" ,songs);
}

void editArtist(char* newNameArtist, char* toChange ,char* songs){
    FILE* f;
    FILE* fTemp = fopen("fTemp.txt", "w");
    char artist[50];
    char song[50];
    if((f = fopen(songs, "r")) == NULL){
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    else{
        while(fscanf(f, "%s %s", artist, song) == 2){
            if(strcmp(toChange, artist) == 0)
                fprintf(fTemp, "%s %s\n", newNameArtist, song);
            else 
                fprintf(fTemp, "%s %s\n", artist, song);
        }
    }
    printf("\n");
    fclose(f);
    fclose(fTemp);
    remove(songs);
    rename("fTemp.txt" ,songs);
}

void deleteArtist(char* toDelete ,char* songs){
    FILE* f;
    FILE* fTemp = fopen("fTemp.txt", "w");
    char artist[50];
    char song[50];
    if((f = fopen(songs, "r")) == NULL){
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    else{
        while(fscanf(f, "%s%s", artist, song) == 2){
            if(strcmp(toDelete, artist) != 0)
                fprintf(fTemp, "%s %s\n", artist, song);
        }
    }
    printf("\n");
    fclose(f);
    fclose(fTemp);
    remove("songs.txt");
    rename("fTemp.txt" ,"songs.txt");
}