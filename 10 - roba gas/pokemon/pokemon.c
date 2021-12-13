#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    char nome[20];
    int danno;
} Mossa;

typedef struct {
    char nome[20];
    int hp;
    Mossa mossa1;
    Mossa mossa2;
} Pokemon;

int readLine (char* str, int size){

    fflush(stdin);
    fgets(str, size, stdin);
    int lenStr = strlen(str);
    
    if(str[lenStr-1] == '\n')
        str[lenStr-1] = '\0';
    return lenStr;
}

Mossa inputMossa(Mossa m){
    
    printf("Inserisci nome mossa\n");
    readLine(m.nome, 20);
    //fgets(m.nome, 20, stdin);

    printf("Danno della mossa\n");
    scanf("%d", &m.danno);

    return m;

}

Pokemon inputPokemon(Pokemon p){
    
    printf("Inserisci nome del pokemon\n");
    readLine(p.nome, 20);
    //fgets(p.nome, 20, stdin);
      
    printf("Inserisci vita\n");
    scanf("%d", &p.hp);    
    fflush(stdin);

    while ((getchar()) != '\n'); //fixing fgets issue after scanf

    printf("Mossa 1\n");
    p.mossa1 = inputMossa(p.mossa1);

    while ((getchar()) != '\n');

    printf("Mossa 2\n");
    p.mossa2 = inputMossa(p.mossa2);

    while ((getchar()) != '\n');

    return p;
}

int main(void){

    Pokemon p1, p2;
    int turno = 1;
    time_t t;

    printf("Giocatore 1, fornisci i dati del tuo Pokemon!\n");
    p1 = inputPokemon(p1);

    printf("Giocatore 2, fornisci i dati del tuo Pokemon!\n");
    p2 = inputPokemon(p2);

    while(p1.hp > 0 && p2.hp > 0){
        if(turno == 1){
            if(rand()%2 == 0){
                p2.hp -= p1.mossa1.danno;
                printf("%s attacca %s usando %s. Hp di %s restanti: %d\n", p1.nome, p2.nome, p1.mossa1.nome, p2.nome, p2.hp < 0 ? 0 : p2.hp);
            }
            else{ 
                p2.hp -= p1.mossa2.danno;
                printf("%s attacca %s usando %s. Hp di %s restanti: %d\n", p1.nome, p2.nome, p1.mossa2.nome, p2.nome, p2.hp < 0 ? 0 : p2.hp);
            }
        turno = 2;
        sleep(1);
        }
        else{
            if(rand()%2 == 0){
                p1.hp -= p2.mossa1.danno;
                printf("%s attacca %s usando %s. Hp di %s restanti: %d\n", p2.nome, p1.nome, p2.mossa1.nome, p1.nome, p1.hp < 0 ? 0 : p1.hp);
            }
            else {
                p1.hp -= p2.mossa2.danno;   
                printf("%s attacca %s usando %s. Hp di %s restanti: %d\n", p2.nome, p1.nome, p2.mossa2.nome, p1.nome, p1.hp < 0 ? 0 : p1.hp);
            }
        sleep(1);
        turno = 1;    
        }
    }
p1.hp <= 0 ? printf("Giocatore 2 ha vinto. Bella\n") :  printf("Giocatore 1 ha vinto. Bella\n");  
}