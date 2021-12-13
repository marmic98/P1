#include <stdio.h>

int isPrimo(int n){
    if (n<2)
        return 0;
    if (n==2)
        return 1;
        for (int i=2;i<n;i++){
            if(n%i==0)
                return 0;
        }   
    return 1;
}


int main(void){
    int n=1;
    while(1){
        if(isPrimo(n))
            printf("%d\n",n);  
        n++;
    }




}
