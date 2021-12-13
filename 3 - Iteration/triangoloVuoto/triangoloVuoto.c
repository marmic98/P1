#include <stdio.h>

int triangolo(int h){
    for (int i=0; i<h; i++){
        if (i==h-1){    
            for(int j=0;j<h-i;j++)
                printf(" ");        
            for(int j=0;j<2*i+1;j++)
                printf("*"); 
            printf("\n");
        }
        else{
            for(int j=0;j<h-i;j++)
                printf(" ");        
            for(int j=0;j<2*i+1;j++){
                if(j==0 || j == 2*i)                
                    printf("*"); 
                else printf (" ");
            }
            printf("\n");
                                
            
        }    
    }
    

}

int main(void){
    int h;
    printf("Fornisci altezza del triangolo ");
    scanf("%d",&h);
    triangolo(h);
}

