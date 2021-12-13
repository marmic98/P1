#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENMAX 40

void printArray(int* a, int len){
    for(int i=0; i<len;i++){
        printf("La stringa %d ha lunghezza %d\n", i + 1, a[i]);
    }
    printf("\n");
}

void readLine (char* s){
    fgets(s, LENMAX, stdin);
    int len = strlen(s);
    if(s[len - 1] == '\n')
        s[len - 1] = '\0';
}

char* readString(int maxLen){
    char *s, *s1; 
    int len;

    s = (char*)malloc(maxLen + 1); //multiplicate for sizeof(char) is useless because size of char is 1 byte
    if (!s) 
        return NULL;

    readLine(s);

    len = strlen(s);

    s1 =(char*)malloc(len +1);

    if(!s1){
        free(s);
        return NULL;
    }

    strcpy(s1, s);
    free(s);
    return s1;
}

void inputString(char** strings, int n){
    for (int i = 0; i < n; i++){
        printf("Fornire Stringa\n");
        strings[i]= readString(LENMAX + 1); 
        printf("\n");
    }
}

void mapLength(char** strings, int n, int* lengths){
    for (int i = 0; i < n; i++){
        lengths[i] = strlen(strings[i]);
    }
}

int main(void){
    char *strs[LENMAX];
    int n = 5;
    int* lengths= (int*) calloc(n, sizeof(int));
    inputString(strs, n);
    mapLength(strs, n, lengths);
    printArray(lengths, n);
}