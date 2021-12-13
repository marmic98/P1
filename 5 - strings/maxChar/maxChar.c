#include <stdio.h>
#include <string.h>
#include <ctype.h>

void setArray(int* a, int len){
    for(int i = 0; i < len; i++){
        a[i] = 0;
    }
}

void setLettere(char* a, int len){
    for(int i = 0; i < len; i++){
        a[i] = 0;
    }
}

void printArray(int* a, int len){
    for(int i = 0; i < len; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

int delete(char* a,int pos, int len){
	for(pos;pos<len;pos++){
		a[pos]=a[pos+1];
	}
	return len-1;
}

int isMaius(char c){
    return c >= 'A' && c <= 'Z';
}

int isMinus(char c){
    return c >= 'a' && c <= 'z';
}

int onlyLetters(char* str){
    int len  = strlen(str);
    int i = 0;
    while(i < len){
        if(isMaius(str[i]) || isMinus(str[i]))
            i++;
        else len  = delete(str, i, len);
    }
}

void lower(char* str){
    int lenStr = strlen(str);
    for (int i = 0; i < lenStr; i++){
            str[i] = tolower(str[i]);
    }
}

int max(int* a, int len){
    int max = a[0];
    int maxLoc = 0;
    for(int i = 0; i < len; i++){
        if (max < a[i]){
            max = a[i];
            maxLoc = i;
        }
    }
    return maxLoc;
}

int contains(char* str, int len, char daCercare){
    int i = 0;
    while( i < len && str[i] != daCercare)  
        i++;
    return i;
}

int maxChar (char* str){
    int lenStr = strlen(str), pos = 0, lenLetters = 0;
    char lettere[lenStr];
    int occorrenze[lenStr];
    
    setLettere(lettere, lenStr);
    setArray(occorrenze, lenStr);
    
    for (int i = 0; i < lenStr; i++){
        pos = contains(lettere, lenLetters, str[i]);
        if(pos == lenLetters){
            lettere[lenLetters] = str[i];
            lenLetters++;
        }
        occorrenze[pos]++;
    }

    printf("%s\n", lettere);
    printArray(occorrenze, lenLetters);
    
    int maxPos =  max(occorrenze, lenLetters);
    printf("Il carattere %c e' il carattere con il maggior numero di occorrenze. Esse sono ben %d\n",lettere[maxPos], occorrenze[maxPos]);
}

int main(void){
    char frase[] = {"Questa qui e' una frase di esempio"};
    char work[strlen(frase)];
    strcpy(work, frase);
    onlyLetters(work);
    lower(work);
    maxChar(work);
}