#include <stdio.h>

int isBisestile(int anno){
    return ((anno%400 == 0) || (anno%100!=0 && anno%4==0));
}

int main(void){
    int n=1582;
    while (n<10000){
        if (isBisestile(n))
            printf("%d\n",n);
        n++;
    }    
}
