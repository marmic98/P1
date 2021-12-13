#include <stdio.h>

void quadrato(int l){
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            printf("* ");        
        }    
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int l;
    printf("Questo complesso software, mediante un complesso sistema di carrucole e specchi, stampa un poligono interemeto fatto di asterischi\nFornisci il lato per favore ");
    scanf("%d",&l);  
    quadrato(l);  
}
