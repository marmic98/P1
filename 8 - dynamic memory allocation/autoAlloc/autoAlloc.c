#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void** pointers;
int pointerCounter = 0;
int sizeMemoryPointers = 0;

void printArray(int* a, int len){
    for(int i=0; i<len;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void inputArray(int* a, int len){
    for(int i=0; i<len;i++){
        scanf("%d", &a[i]);
    }
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

void* xrealloc (void* p, size_t size){
    p = realloc(p, size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }

    return p;
}

void updatePointer(void* p, size_t size){
        pointers = xrealloc(pointers, ((sizeMemoryPointers + size)) * sizeof(void*));
        pointers[pointerCounter] = p;
        sizeMemoryPointers += size;
        pointerCounter++;
}

void* autoAlloc (size_t size){
    void* p = xmalloc(size);
    updatePointer(p, size);
    return p;
}

void freeAll(){
    for (int i = 0; i < pointerCounter; i++){
        free(pointers[i]);
    }
}

int main(void){
    int* p = (int*)autoAlloc(sizeof(int) * 10);
    inputArray(p, 10);
    freeAll();
    
    printArray(p, 10);
}