#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Segmento{
    double x1, x2, y1, y2;
}Segmento;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Alloc failed\n");
        exit(-1);
    }
    return p;
}

int delete(Segmento** as, int pos, int n){
    for (pos; pos < n; pos++)
        as[pos] = as[pos+ 1];
    return n - 1;
}

double lunghezza (Segmento* s){
    return sqrt((s->x2 - s->x1)*(s->x2 - s->x1) + (s->y2 - s->y1)*(s->y2 - s->y1));
}

int eliminaLunghi(Segmento** as, int n, double maxLen){
    int i = 0;
    while(i < n){
        if(lunghezza(as[i]) > maxLen)
            n = delete(as, i, n);
        else i++;
    }
    return n;
}

Segmento** inputSegmenti (int n){
    Segmento**as = xmalloc(sizeof(Segmento*) * n); 
    for(int i = 0; i < n; i++){
        as[i] = xmalloc(sizeof(Segmento));
        printf("x1 = ");
        scanf("%lf", &as[i]->x1);
        printf("x2 = ");
        scanf("%lf", &as[i]->x2);
        printf("y1 = ");
        scanf("%lf", &as[i]->y1);
        printf("y2 = ");
        scanf("%lf", &as[i]->y2);
        printf("\n");
    }
    return as;
}

void printSegmenti(Segmento** as, int n){
    for (int i = 0; i < n; i++){
        printf("x1 = %g\nx2 = %g\ny1 = %g\ny2 = %g\n\n", as[i]->x1, as[i]->x2,as[i]->y1,as[i]->y2);
    }
}

int main(void){
    int n = 3;
    Segmento **as = inputSegmenti(n);   
    //printSegmenti(as, n);
    double maxLen = 30;
    n = eliminaLunghi(as, n, maxLen);
    printf("Segmenti non lunghi\n");
    printSegmenti(as, n);
}