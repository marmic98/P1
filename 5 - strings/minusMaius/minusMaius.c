#include <stdio.h>
#include <string.h>

void upper(char* c){
    *c -= 32;
}

void lower(char* c){
    *c += 32;
}

int isMinusc(char c){
    return c >= 'a' && c <= 'z';
}

int isMaiusc(char c){
    return c >= 'A' && c <= 'Z';
}

void minusMaius(char* str){
    int lenStr = strlen(str);

    for(int i = 0; i < lenStr; i++){
        if (isMinusc(str[i]))
            upper(&str[i]);
        else if (isMaiusc(str[i]))
            lower(&str[i]);
    }
}

int main(void){
    char str[] = ("stringatRopPoBellissimAAssAI!");
    printf("%s\n", str);
    minusMaius(str);
    printf("%s\n", str);
}