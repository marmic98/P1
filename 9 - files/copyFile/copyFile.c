#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 300

void readLine (char* str, int len){
    fgets(str, len, stdin);
    int realLen = strlen(str);
    if (str[realLen - 1] == '\n')
        str[realLen - 1] = '\0';
}

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }

    return p;
}

FILE* xfopen(char* fileName, char* mode){
    FILE *f = fopen(fileName, mode);
    if (f == NULL){
        printf("Impossibile aprire il file\n");
        return NULL;
    } 
    return f;
} 

void writeOnFile (FILE* f, int maxRow){
    char buf[LEN];
    int i = 0;
    while(i < maxRow && strcmp("end", buf) != 0){
        printf("%d: ", i+1);
        fgets(buf, LEN, stdin);
        fprintf(f, "%s", buf);
        i++;
    }
}

void copyFile(FILE* file, FILE* copiedFile){
    char buf[LEN];
    
    while(fgets(buf, LEN, file) != NULL){
        
        fprintf(copiedFile, "%s", buf);
    }
}

void showFileContent (FILE* f){
    char buf[LEN];
    int i = 0;
    while(fscanf(f, "%s", buf) == 1){
        
        printf("%d: %s\n", i + 1, buf);
        i++;
    }
}


int main(void){
    FILE *fin = xfopen("IN.txt", "w");
    writeOnFile(fin, 10);
    fclose(fin);

    fin = xfopen("IN.txt", "r");
    FILE *fout = xfopen("OUT.txt", "w");
    copyFile(fin, fout);
    fclose(fin);
    fclose(fout);
    printf("\n");
    
    fout = xfopen("OUT.txt", "r");
    showFileContent(fout);
    fclose(fout);
}