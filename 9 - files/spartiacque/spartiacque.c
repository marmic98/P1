#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN  "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"


int delete(char **a, int pos, int aSize){
    for(pos; pos < aSize; pos++){
        a[pos] = a[pos + 1];
    }
    return aSize - 1;
}

void printArray(char** a,int len){
	for(int i=0; i<len;i++){
		printf(" |%s| ",a[i]);
	}
	printf("\n");
}

int spartiacque(FILE* file, char* metro, char **a, int aSize){
    int counter = 0;
    while(counter < aSize){
        if (strcmp(a[counter], metro) == -1){
            fprintf(file, "%s\n", a[counter]);
            counter++;
        }
        else 
            aSize = delete(a, counter, aSize);
    }

    fprintf(file, "END");
    fclose(file);
    return counter;
}

int main (void){
    char* fileName = {"spartiacquati.txt"};
    FILE* file;
    if (!(file = fopen(fileName, "w"))){
        printf("Impossibile aprire il file richiesto");
        abort();
    }

    char *a[] = {"charlie", "rocky", "alpha", "super"};
    char* metro = "danny";
    int aSize = 4; 
    printArray(a, aSize);
    printf("I caratteri alfabeticamente conformi alla parola %s%s%s sono %s%d%s\n",GREEN,metro,RESET, YELLOW,spartiacque(file, metro, a, aSize), RESET);
}