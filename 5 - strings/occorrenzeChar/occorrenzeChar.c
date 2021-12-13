#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define range 'a' - 'A'

int isMinusc(char c){
    return c >= 'a' && c <= 'z';
}

int isMaiusc(char c){
    return c >= 'A' && c <= 'Z';
}

int isLetter(char c){
    return isMaiusc(c) || isMinusc(c);
}

int containsChar(char* str, char c){
    int counter = 0;

    if (!isLetter(c))
        return -1;
    else{
        int len = strlen(str);
        c = tolower(c);
        
        for (int i = 0; i < len; i++)
            str[i] = tolower(str[i]);
        
        for(int i = 0; i < len; i++){
            if (str[i] == c || str[i] == c - range)
                counter++;
        }
    }
    return counter;
}

int main(void){
    char c = 'E';
    char str[] = "Questa qui e' una frase di esempio";

    if (containsChar(str, c) == -1)
        printf("non e' una lettera\n");
    else
        printf("Il carattere %c e' contenuto %d volte\n", c, containsChar(str, c));
}