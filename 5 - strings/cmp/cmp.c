#include <stdio.h>
#include <string.h>

int compare (char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    int len = 0;

    while(i < len1){
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        else i++;
    }

    if (len1 == len2)
        return 0;
    else if (len1 < len2)
        return -1;
    else
        return 1;
}

void main(void){
    char *s1 = "Distasi";
    char *s2 = "Dislasi";
    //printf("%d \n", strcmp(s1, s2));
    if (compare(s1, s2) == 1){
        printf("1  s1 viene dopo s2");
    }  
    else if(compare(s1, s2) == -1){
        printf("-1  s1 viene prima di s2");
    }
    else printf("0  s1 e' uguale a s2");
}