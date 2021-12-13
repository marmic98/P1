#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define LENMAX 20

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }

    return p;
}

void readLine (char* s){
    fgets(s, LENMAX, stdin);
    int len = strlen(s);
    if(s[len - 1] == '\n')
        s[len - 1] = '\0';
}

char* readString(int maxLen){
    
    char* s = (char*)malloc(maxLen + 1); //multiplicate for sizeof(char) is useless because size of char is 1 byte
    if (!s) 
        return NULL;

    readLine(s);

    int len = strlen(s);

    char* s1 = (char*)malloc(len +1);

    if(!s1){
        free(s);
        return NULL;
    }

    strcpy(s1, s);
    free(s);
    return s1;
}

void inputStrings(char* strs[], int numElem){
    for (int i  = 0; i < numElem; i++){
        printf("stringa %d ", i+1);
        strs[i] = readString(LENMAX + 1);
        fflush(stdin);    }
}

char* iniziali (char** strs, int numElem){
    char* str = (char*)xmalloc(numElem);
    for (int i = 0; i < numElem; i++){
        str[i] = strs[i][0];
    }
    return str;
}

int main(void){
    char* strs[N];
    inputStrings(strs, N);
    char* str = iniziali(strs, N);
    printf("La stringa con le iniziali corrisponde a %s", str);

    free (str);
}