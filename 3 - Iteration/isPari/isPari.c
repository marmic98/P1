#include <stdio.h>

int isPari(int n){
    if(n%2 == 0)
        return 1;
    return 0;
}

int main(void){
    for (int i = 100; i >= 0; i-=2)
        printf("%d\n", i);
}