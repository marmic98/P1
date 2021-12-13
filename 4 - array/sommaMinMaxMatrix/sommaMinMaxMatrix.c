#include <stdio.h>

void sumMatrix(int r, int c, int m1[r][c], int m2[r][c], int m3[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            m3[i][j]=m1[i][j]+m2[i][j];
        }
    }
}

void maxMatrix(int r, int c, int m1[r][c], int m2[r][c], int m3[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            if(m1[i][j] > m2[i][j])
                m3[i][j] = m1[i][j];
            else
                m3[i][j] = m2[i][j];
        }
    }
}

void minMatrix(int r, int c, int m1[r][c], int m2[r][c], int m3[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            if(m1[i][j] < m2[i][j])
                m3[i][j] = m1[i][j];
            else
                m3[i][j] = m2[i][j];
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

void printMatrix(int r, int c, int m[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}

void inputMatrix(int r, int c, int m[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

int main(void){
    
    int r,c;
   
    printf("Fornisci altezza matrice ");
    scanf("%d",&r);
    printf("Fornisci base matrice ");
    scanf("%d",&c);
    
    int m1[r][c], m2[r][c], sum[r][c], max[r][c], min[r][c];
    
    setMatrix(r,c,sum);

    printf("Matrice 1\n");
    inputMatrix(r,c,m1);
    printf("Matrice 2\n");
    inputMatrix(r,c,m2);
    
    printf("Matrice 1\n");
    printMatrix(r,c,m1);
    printf("Matrice 2\n");
    printMatrix(r,c,m2);

    sumMatrix(r, c, m1, m2, sum);
    maxMatrix(r, c, m1, m2, max);
    minMatrix(r, c, m1, m2, min);

    printf("Matrice SOMMA\n");
    printMatrix(r, c, sum);

    printf("Matrice MASSIMI\n");
    printMatrix(r, c, max);

    printf("Matrice MINIMI\n");
    printMatrix(r, c, min);
}
