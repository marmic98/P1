#include <stdio.h>

void printArray(int* a, int len){
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void inputArray(int* a, int len){
    for(int i=0;i<len;i++){
        printf("Fornisci %d valore ",i);
        scanf("%d",&a[i]);
    }
}

int contains(int* a, int len, int daCercare){

    len -= 1;
    while(len>=0  && a[len]!=daCercare)
        len--;
        
    return len >= 0; //se len < 0 elemento non trovato
}

int deleteDuplicate(int*a,int* b, int len){
    
    int lenB=0;
    
    for(int i = 0; i<len; i++){
        if (!contains(b, lenB, a[i])){
            b[lenB]=a[i];
            lenB++;
        } 
    }
    return lenB;
}




int main(void){
    int len = 0;
    int lenB=0;
    do{
        printf("Fornire lunghezza dell'array\n");
        scanf("%d",&len);
    }while(len>20);
        
        int a[len];
        int b[len];
        
        inputArray(a,len);
        lenB = deleteDuplicate(a,b,len);
        
        printArray(b,lenB);
    
}
