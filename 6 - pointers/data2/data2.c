#include <stdio.h>
#include <string.h>

int bisestile(int anno){
    return ((anno%400 == 0) || (anno%100!=0 && anno%4==0));
}

int verificaData(int giorno, int mese, int anno){
    if (anno > 1581 && anno<3000){       
        if(mese>0 && mese <13){
            if(giorno>0 && giorno<32){
                if ((mese==2 || mese==4 || mese==6 || mese ==9 || mese == 11) && (giorno>30)){
                    return 0;
                }
                if (mese == 2){
                    if (giorno==29 && bisestile(anno)){
                        return 1;
                    }else return 0;
                }   
            }else return 0;   
        }else return 0;  
    }else return 0;   
}


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
        default:
            break;
    }
}


int outputData(int data, int* giorno, char* mese, int* anno){
    *giorno=getGiorno(data);
    meseStr(getMese(data),mese);
    *anno=getAnno(data);
    return verificaData(*giorno,getMese(data),*anno);  
}

int main(void){

    int data=0, giorno=0, anno=0;
    char mese[8];
    
    printf("Fornisci data in formato ggmmaa ");
    scanf("%d",&data); 
    
    outputData(data,&giorno,mese,&anno) ? 
    printf("%d %s %d\n",giorno, mese, anno) : printf("Data non valida\n");     
}
