#include <stdio.h>
#include <stdlib.h>

void printArray(int* a, int len){
    if (a){
        for(int i=0; i<len;i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }else printf("Array vuoto\n");
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

int contains(int *a, int len, int daCercare){
    int i = 0;
    while(i < len && a[i] != daCercare)
        i++;
    return i < len;
}

int* intersez(int* x, int xSize, int* y ,int ySize,int* newSize){
    int* intersez = xmalloc(sizeof(int));
        for(int i = 0; i < xSize; i++){
            if(contains(y, ySize, x[i])){
                intersez[*newSize] = x[i];
                *newSize += 1;
                intersez = xrealloc(intersez, (*newSize) * sizeof(int));
            }
        }
        *newSize -= 1;
    if (*newSize == 0)
        return NULL;
    return intersez;
}


int main(void){
    int x[] = {-6, 56, 3, 4};
    int xSize = 4;
    
    int y[] = {0, 1, 9, 2, 4};
    int ySize = 5;
    
    int newSize = 0;
    int *r = intersez(x, xSize, y , ySize, &newSize); 
    
    printArray(x, xSize);
    printArray(y, ySize);
    printArray(r, newSize);
}