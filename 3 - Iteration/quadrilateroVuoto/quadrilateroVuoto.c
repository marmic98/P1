#include <stdio.h>

void pV(int b,int h){
    for (int i=0;i<h;i++){
        if (i==0 || i==h-1){
    
            for(int j=0;j<b;j++)
                printf("* ");
            printf("\n");
        }
        else{
            for(int j=0;j<b;j++){
                if (j==0 || j==b-1)
                    printf("* ");
                else             
                    printf("  ");        
            }
            printf("\n");
        }
    }
}



int main(void){
    int b,h;
    printf("Fornisci base del poligono ");
    scanf("%d",&b);
    printf("Fornisci altezza del poligono ");
    scanf("%d",&h);
    pV(b,h);
}
