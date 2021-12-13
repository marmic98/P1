#include <stdio.h>

unsigned int primo(unsigned int n){
    if (n<2)
        return 0;
    if (n==2)
        return 1;
    if (n%2==0)
        return 0;
    for (int i=3;i*i<=n;i+=2){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(void){
    int n=1;
    while(1){
        if(primo(n))
            printf("%d\n",n);  
        n++;
}




}
