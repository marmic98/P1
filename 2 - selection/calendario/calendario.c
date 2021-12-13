#include <stdio.h>

int bisestile(int anno){
    return ((anno%400 == 0) || (anno%100!=0 && anno%4==0));
}

int verificaInterone(int data){
    return 1101582 <= data && 31129999 >= data;
}

int anno(int data){
    return (data%10000);
}

int mese(int data){
    return (data/10000)%100;
}

int giorno(int data){
    return (data/1000000)%100;
}

int verificaData(int anno, int mese, int giorno){
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
}

int main(void){
    unsigned int data,valida;
    printf("Questo software verifica se una data e' corretta\nsecondo il calendario gregoriano.\nEsso e' in vigore dal 01/10/1582 sostituendo il calendario  Giuliano.\n\nFornire data in input\n");
    scanf("%d",&data);
    
    if (verificaInterone(data)){
        int aaaa = anno(data);
        int mm = mese(data);
        int gg = giorno(data);
        printf("%d %d %d\n",gg,mm,aaaa);
        valida = verificaData(aaaa,mm,gg); 
    }else valida = 0;
    valida ? printf("data valida\n") : printf("data non valida\n");
}
