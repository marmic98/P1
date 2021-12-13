#include <stdio.h>

int sumMatrix(int r, int c, int m[r][c]){
    int sum = 0;
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            sum += m[i][j];
        }
    }
    return sum;
}

void inputMatrix(int r, int c, int m[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

void setMatrix(int r, int c, int m[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            m[i][j]=0;
        }
    }
}

int main(void){

    int r,c;
   
    printf("Fornisci altezza matrice ");
    scanf("%d",&r);
    printf("Fornisci base matrice ");
    scanf("%d",&c);

    int m1[r][c], m2[r][c];

    setMatrix(r, c, m1);
    setMatrix(r, c, m2);

    printf("Matrice 1\n");
    inputMatrix(r, c, m1);
    printf("Matrice 2\n");
    inputMatrix(r, c, m2);

    printf("La somma degli elementi della prima matrice e' %d\n", sumMatrix(r, c, m1));
    printf("La somma degli elementi della seconda matrice e' %d\n", sumMatrix(r, c, m2));
}