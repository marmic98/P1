#include <stdio.h>

#define LENMAX 10

void inputArray(int* a, int len){
    for(int i=0; i< len; i++){
        printf("Inserisci valore %d di %d ", i, len-1);
        scanf("%d",&a[i]);  
    }
}

int isThreeCifres(int n){
    return n<1000 && n>99;
}

void isolaCifre(int n, int* n1, int* n2, int* n3){
    *n1= (n/100)%10;
    *n2= (n/10)%10;
    *n3= n%10;
}

int cubo(int n){
    return n = n*n*n;
}

int sommaCubi(int n1, int n2, int n3){
    return cubo(n1)+cubo(n2)+cubo(n3);
}

void notZeroPrint(int* a, int len){
    for(int i=0; i<len; i++){
        if(a[i]!=0){
            printf("%d ",a[i]);
        } 
    }
    printf("\n");
}

void isArmstrong(int* arm, int len){
    int n1, n2, n3, counterZero=0;
    for(int i=0;i<len;i++){
        if(isThreeCifres(arm[i])){
            isolaCifre(arm[i], &n1, &n2, &n3);                
        }        
        if (sommaCubi(n1, n2, n3) != arm[i]){
            arm[i]=0;
            counterZero++;
        }
    }
    counterZero == len ? printf ("Non ci sono numeri di Armstrong nell'array\n") : notZeroPrint(arm, len);

}

int main(void){
    // numeri di Armstrong a 3 cifre --> 153 370 371 407
    int arm[LENMAX];
    int lenArm= 5;
    inputArray(arm, lenArm);
    isArmstrong(arm, lenArm);
}
