#include <stdio.h>
#include <stdlib.h>

typedef struct Rect{
    double w, h;
}Rect;

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Allocation failed\n");
        exit(-1);
    }
    return p;
}

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation failed\n");
        exit(-1);
    }
    return p;
}

double area(Rect rettangolo){
    return rettangolo.h * rettangolo.w;
}

Rect* rettangoliGrandi(Rect a[], int n, double areaMin, int* nGrandi){
    *nGrandi = 0;
    Rect* aNew = xmalloc(sizeof(Rect));
    for(int i = 0; i < n; i++){
        if (area(a[i]) > areaMin){
            aNew[*nGrandi] = a[i];
            *nGrandi += 1;
            aNew = xrealloc(aNew, sizeof(Rect)* (*nGrandi + 1));
        }
    }
    if (*nGrandi == 0){
        free(aNew);
        return NULL;
    }
    else 
        return aNew;
}

void printRettangoli(Rect a[], int n){
    for (int i = 0; i < n; i++){
        printf("Rettangolo %d\nh = %g\nw = %g\n\n", i + 1, a[i].h, a[i].w);
    }
}

int main(void){
    int n = 3;
    int nGrandi = 0;
    double areaMin = 40;
    Rect *a = xmalloc(sizeof(Rect) * n);
    a[0].h = 7;
    a[0].w = 7;

    a[1].h = 5;
    a[1].w = 2;

    a[2].h = 4;
    a[2].w = 11;

    Rect* aNew = rettangoliGrandi(a, n, areaMin, &nGrandi);

    printRettangoli(aNew, nGrandi);
}
