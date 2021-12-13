#include <stdio.h>

void showArray(int* aereo){
    for(int i = 0; i < 10; i++)
        printf(" %d ",aereo[i]);
    printf("\n");
}

void zeroArray(int* aereo){
    for(int i = 0; i < 10; i++)
        aereo[i] = 0;
}

int bookFclass(int* aereo){
    for (int i = 0; i < 5; i++){
        if (aereo[i] == 0){
            aereo[i]=1;
            return 1;   
        }
    }
    return 0;
}

int book2class(int* aereo){
    for (int i = 5; i < 10; i++){
        if (aereo[i] == 0){
            aereo[i]=1;
            return 1;   
        }
    }
    return 0;
}
int booking(int* aereo){

    int volo,scelta, firstClass=0, economy=0;
    printf("Sistema di prenotazione realizzato di IncredibleTech Inc.\n");
    do{
        printf("Digita 1 per prima classe\nDigita 2 per Economy\n");
        scanf("%d",&volo);
    }while(volo != 1 && volo != 2);

    if (volo == 1){
        if (firstClass < 5 && bookFclass(aereo)){
            printf("Prenotazione effettuata\n");
            firstClass++;
            return 1;
        }
        else {
            
            if (economy < 5){
                printf("Prima classe piena. Desideri prenotare in Economy?\n1)Si\n2)No\n"); 
                scanf("%d", &scelta);
            }
            if (scelta == 1)
                return book2class(aereo);
            else{
                printf("Il prossimo volo disponibile decollerà tra 3 ore\n");
                return 0;
            }
        }
    }
    else {
        if (economy < 5 && book2class(aereo)){
            printf("Prenotazione effettuata\n");
            economy++;
            return 1;
        }
        else {
            
            if (firstClass < 5){
                printf("Economy piena. Desideri prenotare in First CLass?\n1)Si\n2)No\n"); 
                scanf("%d", &scelta);
            }
            if (scelta == 1)
                return bookFclass(aereo);
            else{
                printf("Il prossimo volo disponibile decollerà tra 3 ore\n");
                return 0;
            }
        }
    }
}

int main(void){
    int aereo[10];
    int prenotazioni=0;;
    zeroArray(aereo);

    do{

        prenotazioni += booking(aereo);
        showArray(aereo);
        
    }while(prenotazioni < 10);

    printf("Numero di prenotazioni massime raggiunto\n");
}