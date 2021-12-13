#include <stdio.h>
#include <math.h>

int primo(double n){
    if (n<2)
        return 0;
    if (n==2)
        return 1;
    for (double i=2;i<sqrt(n);i++){
        if((int)n%(int)i==0)
            return 0;
    }
    return 1;
}


int main(void){
    double n=1;
    while(1){
        if(primo(n))
            printf("%g\n",n);  
        n++;
}




}
