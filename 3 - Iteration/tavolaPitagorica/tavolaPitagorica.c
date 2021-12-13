#include <stdio.h>

#define rows 10
#define columns 10

void printMatrix(int matrix[][columns]){

    for (int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
}

void tabPitagorica(int tab[][columns]){
    
    for (int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            tab[i][j]=(i+1)*(j+1);
        }
    }     
}

void setMatrix(int tab[][columns]){
    
    for (int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            tab[i][j]=0;
        }
    }     
}

int main(void){

    int tab[rows][columns];
    setMatrix(tab);
    tabPitagorica(tab);
    printMatrix(tab);
} 
