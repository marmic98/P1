#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

typedef struct Punto{
    double x, y;
} Punto;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
        exit(-1);
    }

    return p;
}

void printArray(double* array){
    for (int i = 0; i < N; i++){
        printf("%g ", array[i]);
    }
    printf("\n");
}

void printTriangolo(Punto** triangolo){
    for(int i = 0; i < N; i++){
        printf("(%g, %g)\n", triangolo[i] -> x, triangolo[i] -> y);
    }
}

void* creaPunto(double xx, double yy){
    Punto* p = xmalloc(sizeof(Punto));
    p -> x = xx;
    p -> y = yy;
    return p;
}

void creaTriangolo(Punto** triangolo){
    double x,y;
    
    for(int i = 0; i < N; i++){
        printf("Fornisci coordinate punto %d\n", i + 1);
        printf("x: ");
        scanf("%lf", &x);
        printf("y: ");
        scanf("%lf", &y);
        triangolo[i] = creaPunto(x, y);
    }
}

void sort (double* array){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if (array[j] > array[j + 1]){
                array[j] = array[j] + array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1];
            }
        }
    }
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}

int areEqual(Punto** triangolo1, Punto** triangolo2){
    double distanze1[N];
    double distanze2[N];

    for(int i = 0; i < N; i++){
        if (i+1 < N){
            distanze1[i] = distance(triangolo1[i] -> x, triangolo1[i] -> y, triangolo1[i+1] -> x, triangolo1[i+1] -> y);    
            distanze2[i] = distance(triangolo2[i] -> x, triangolo2[i] -> y, triangolo2[i+1] -> x, triangolo2[i+1] -> y);
        }
        else{
            distanze1[i] = distance(triangolo1[i] -> x, triangolo1[i] -> y, triangolo1[(i+1)%N] -> x, triangolo1[(i+1)%N] -> y);    
            distanze2[i] = distance(triangolo2[i] -> x, triangolo2[i] -> y, triangolo2[(i+1)%N] -> x, triangolo2[(i+1)%N] -> y);
        }
    }

    sort(distanze1);
    sort(distanze2);

printArray(distanze1);
    printArray(distanze2);
    return (distanze1[0] == distanze2[0]) && (distanze1[1] == distanze2[1]) && (distanze1[2] == distanze2[2]);
}

int main(void){
    Punto *triangolo1[3];
    Punto *triangolo2[3];
    printf("Triangolo 1\n");
    creaTriangolo(triangolo1);
    printf("Triangolo 2\n");
    creaTriangolo(triangolo2);

    printf("coord. 1\n");
    printTriangolo(triangolo1);
    printf("coord. 2\n");
    printTriangolo(triangolo2);

    areEqual(triangolo1, triangolo2) ? printf("I triangoli sono uguali\n") : printf("I triangoli sono diversi\n");
}