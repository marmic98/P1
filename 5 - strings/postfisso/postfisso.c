#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 21

void toLower(char* s){
    int len = strlen(s)-1;
    for (int i = 0; i< len; i++)
        s[i] = tolower(s[i]);
    
}
//wrapper: ingloba una funzione già esistente a vantaggio dell'utilizzatore 
int readLine(char* s, int len){
    fgets(s, len, stdin);
    int lenStr = strlen(s);

    if (s[lenStr - 1] == '\n')
        s[lenStr - 1] == '\0';
    
    return lenStr;
}

char* postfisso (char* s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    while(s1[len1] == s2[len2]){
        len1--;
        len2--;
    }
    return &s2[len2+1];
}

int main(void){
    char s1[LEN], s2[LEN];
    readLine(s1, LEN);
    readLine(s2, LEN);

    toLower(s1);
    toLower(s2);

    printf("%s", postfisso(s1, s2));
}