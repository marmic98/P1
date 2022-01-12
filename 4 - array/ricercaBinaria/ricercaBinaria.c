#include <stdio.h>

#define N 8

int ricercaBinaria(int* a,int item){
    int inizio=0,fine=N-1,centro;
    while(inizio <= fine){
        centro = (inizio+inizio)/2;
        if (a[centro]==item){
            return centro;
        }
         else if (item > a[centro]){
            inizio = centro+1;
        }
        else {
            fine = centro-1;
        }
    }
    return -1;

}

int main(){
    int item;
    
    printf("Fornire elemento da ricercare: ");
    scanf("%d", &item);

    int a[N] = {0,5,10,15,91,115,215,366};
    int pos = ricercaBinaria(a,item);	

    pos == -1 ? printf("L'elemento %d non è presente nell'array\n",item) : printf("L'elemento %d e' in posizione %d\n",item,pos);
}
