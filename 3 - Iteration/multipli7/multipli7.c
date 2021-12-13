#include <stdio.h>

int main(void){
    for(int n = 1000; n>6; n--){
        if (n%7 == 0){
            printf("%d\n",n);
        }
    }
}