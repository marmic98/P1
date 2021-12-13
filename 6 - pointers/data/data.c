#include <stdio.h>
#include <string.h>

int getAnno(int data){
    return 2000+(data%100);
}

int getMese(int data){
    return (data/100)%100;
}

int getGiorno(int data){
    return (data/10000)%100;
}

void meseStr(int mm,char* mese){
    switch(mm){
        case 1:
            strcpy(mese,"Gennaio");
            break;
        case 2:
            strcpy(mese,"Febbraio");
            break;
        case 3:
            strcpy(mese,"Marzo");
            break;
        case 4:
            strcpy(mese,"Aprile");
            break;
        case 5:
            strcpy(mese,"Maggio");
            break;
        case 6:
            strcpy(mese,"Giugno");
            break;
        case 7:
            strcpy(mese,"Luglio");
            break;
        case 8:
            strcpy(mese,"Agosto");
            break;
        case 9:
            strcpy(mese,"Settembre");
            break;
        case 10:
            strcpy(mese,"Ottobre");
            break;    
        case 11:
            strcpy(mese,"Novembre");
            break;
        case 12:
            strcpy(mese,"Dicembre");
            break;
    }
}



void outputData(int data, int* giorno, char* mese, int* anno){
    *giorno=getGiorno(data);
    meseStr(getMese(data),mese);
    *anno=getAnno(data);
}

int main(void){

    int data=0, giorno=0, anno=0;
    char mese[8];
    
    printf("Fornisci data in formato ggmmaa ");
    scanf("%d",&data); 
    
    outputData(data,&giorno,mese,&anno);
    printf("%d %s %d\n",giorno, mese, anno);     
}
