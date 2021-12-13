#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void showCanvas(char floor[50][50]){
    for (int i = 0; i< 50; i++){
        for (int j = 0; j< 50; j++){
            printf("%2c", floor[i][j]);
        }
        printf("\n");
    }
}

void showDir (int direzione){
    switch(direzione){
            case 1:
                printf("La tartaruga punta a NORD\n");
                break;
            case 2:
                printf("La tartaruga punta a EST\n");
                break;
            case 3:
                printf("La tartaruga punta a SUD\n");
                break;
            case 4:
                printf("La tartaruga punta a OVEST\n");
                break;
    }
}

void newCanvas(char floor[50][50]){
    for (int i = 0; i< 50; i++){
        for (int j = 0; j< 50; j++){
            floor[i][j] = ' ';
        }
        printf("\n");
    }
}

void movimento (int direzione, int* x, int* y, int steps){
    switch(direzione){
            case 1:
                if (steps < *x)
                    *x -= steps;
                else 
                    *x = 0;
                break;
            case 2:
                if (steps < 50 - *y)
                    *y -= steps;
                else
                    *y = 50; 
                break;
            case 3:
                if (steps < 50 - *x)
                    *x += steps;
                else
                    *x = 50;
                break;
            case 4:
                if(steps < *y)
                    *y += steps;
                else 
                    *y = 0;
                break;
    }
}

void scrivi(int direzione, int* x, int* y, int steps, char floor[50][50]){
    switch(direzione){
            case 1:
            if (steps < *x){
                for (steps; steps > 0; steps--){
                    floor[*x][*y] = '*';
                    *x -= 1;
                }
            }
            else{
                for (int i = *x; i > 0; i--){
                    floor[*x][*y] = '*';
                    *x -= 1;
                }
            }
                break;
                
            case 2:
            if (steps < 50 - *y){
                for (steps; steps > 0; steps--){
                    floor[*x][*y] = '*';
                    *y += 1;
                }
            }
            else{
                for (int i = 50 - *y; i > 0; i--){
                    floor[*x][*y] = '*';
                    *y += 1;
                }
            }
                break;
                
            case 3:

                if (steps < 50 - *x){
                for (steps; steps > 0; steps--){
                    floor[*x][*y] = '*';
                    *x += 1;
                }
            }
            else{
                for (int i = 50 - *x; i > 0; i--){
                    floor[*x][*y] = '*';
                    *x += 1;
                }
            }
                break;
                
            case 4:
            if (steps < *y){
                for (steps; steps > 0; steps--){
                    floor[*x][*y] = '*';
                    *y -= 1;
                }
            }
            else{
                for (int i = *y; i > 0; i--){
                    floor[*x][*y] = '*';
                    *y -= 1;
                }
            }
                break;
    }
}

int changeDirection(int where, int direzione){
    if (where == 3){ //gira a destra
        switch(direzione){
            case 1:
                return direzione = 2;
                break;
            case 2:
                return direzione = 3;
                break;
            case 3:
                return direzione = 4;
                break;
            case 4:
                return direzione = 1;
                break;
        }
    }
    else{ // gira a sinistra
        switch(direzione){
            case 1:
                return direzione = 4;
                break;
            case 2:
                return direzione = 1;
                break;
            case 3:
                return direzione = 2;
                break;
            case 4:
                return direzione = 3;
                break;
        }
    }
}

/*
    nord  1
    est   2
    sud   3
    ovest 4
*/

int main(void){
    char floor[50][50];
    int comando;
    int direzione = 3, penna = 0, x = 0, y = 0, steps;

    newCanvas(floor);
    //system("clear");
        
        do {
            //system("clear");
            printf("x: %d\ny: %d\n", x, y);
            showDir(direzione);
            printf("Inserisci comando\n1) Penna su\n2) Penna giu'\n3) Gira a destra\n4) Gira a sinistra\n5) Spostati\n6) Mostra canvas\n9) Esci\n");
            scanf("%d", &comando);
            
        switch(comando){
            case 1:
                penna = 1;
                break;
            case 2:
                penna = 2;
                break;
            case 3:
                direzione = changeDirection(3, direzione);
                break;
            case 4:
                direzione = changeDirection(4, direzione);
                break;
            case 5:
                printf("Quanti passi vuoi fare?\n");
                scanf("%d", &steps);
                if (penna == 1)
                    movimento(direzione, &x, &y, steps);
                else
                    scrivi(direzione, &x, &y, steps, floor);
                break;
            case 6:
                showCanvas(floor);
                break;
            case 9:
                break;
        }
    }while(comando != 9);

}
