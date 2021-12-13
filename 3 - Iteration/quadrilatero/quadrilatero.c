#include <stdio.h>

void poligono(int b, int h){
    for(int i=0;i<h;i++){
        for(int j=0;j<b;j++){
            printf("* ");        
        }    
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int b,h;
    printf("Questo complesso software, mediante un complesso sistema di carrucole e specchi, stampa un poligono interemeto fatto di asterischi\nFornisci l'altezza per favore ");
    scanf("%d",&h);    
    printf("Fornisci l'base adesso ");
    scanf("%d",&b);
    poligono(b,h);

}
