#include <stdio.h>

void qV(int l){
    for (int i=0;i<l;i++){
        if (i==0 || i==l-1){
    
            for(int j=0;j<l;j++)
                printf("* ");
            printf("\n");
        }
        else{
            for(int j=0;j<l;j++){
                if (j==0 || j==l-1)
                    printf("* ");
                else             
                    printf("  ");        
            }
            printf("\n");
        }
    }
}



int main(void){
    int l;
    printf("Fornisci lato del quadrato ");
    scanf("%d",&l);
    qV(l);

}
