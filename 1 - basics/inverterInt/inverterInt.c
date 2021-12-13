#include <stdio.h>
#include <math.h>

int intLen(int n){
    int len = 0;
    while (n > 0){
        n /= 10;
        len++;
    }
    return len;
}

int invert(int n){
    int inverso = 0;
    int i = 0;
    int molt = intLen(n) - 1;
    while(i < intLen(n)){
        inverso += ((n / (int)pow(10, i)) % 10) * (pow(10, molt)); //Considera il 
        molt--;
        i++;
    }
    return inverso;
}

int main(void){
    int n = 0;
    int inverso = 0;
    printf("Fornire numero da invertire\n");
    scanf("%d", &n);

    inverso = invert(n);

    printf("Il numero inverso e' %d\n", inverso);
}