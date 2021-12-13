#include <stdio.h>


int sumDivisori(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if((n % i) == 0)
            sum += i;
    }
    return sum == n;
}

int isPerfetto(int n){
    return sumDivisori(n);
}

int main(void){
    int n;
    
    printf("Fornisci numero ");
    scanf("%d", &n);

    isPerfetto(n) ? printf("Il numero e' perfetto\n") : printf("Il numero non e' perfetto\n");
}