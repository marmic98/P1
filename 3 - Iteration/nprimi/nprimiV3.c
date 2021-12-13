#include <stdio.h>

int primo(int n){
    if (n<2)
        return 0;
    if (n==2)
        return 1;
    for (int i=2;i<(n/3)+1;i++){
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
