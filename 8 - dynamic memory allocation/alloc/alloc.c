#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void inputArray(int* array, int elements){
    for (int i = 0; i < elements; i++){
        scanf("%d", &array[i]);
    }
}

void printArray(int* array, int elements){
    for (int i = 0; i < elements; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void){
    int numElem = 10;

    //malloc allocates array dinamically of a certain dimension defined by the programmer
    int *array = (int*) malloc(numElem * sizeof(int));
    
    if (!array) // it's like array == NULL
        printf("zizzinella is over\n");

    

    //calloc allocates array dinamically of a certain dimension defined by the programmer and inizialize their content to 0
    //calloc has a better parameter structure. multiplication is not needed
    array = (int*) calloc(numElem, sizeof(int));
    if (!array) // it's like array == NULL
        printf("zizzinella is over\n");

    inputArray(array, numElem);
    printArray(array, numElem);

    //realloc edits dimension of a pre-existent dinamic-allocated array 
    numElem = 5;
    array = realloc(array, numElem * sizeof(int));
    printArray(array, numElem);

    free(array); // flag allocated cells like aviable to be used by other data

    printArray(array, numElem); //first allocated elements get overwritten by other data
}