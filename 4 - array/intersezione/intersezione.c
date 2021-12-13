#include <stdio.h>

void printArray(int* a, int len){
    for(int i=0; i<len;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void inputArray(int* a, int len){
    for(int i=0; i<len;i++){
        scanf("%d", &a[i]);
    }
}

int delete(int* a,int pos, int len){
	for(pos;pos<len;pos++){
		a[pos]=a[pos+1];
	}
	return len-1;
}

int deleteDuplicate(int* a,int len){
	
	for (int j=0;j<len;j++){
		int i=j+1;
		while(i<len){
			if (a[j]==a[i]){
				len=delete(a,i,len);
			}
			else i++;
		}
	}
	return len;
}

int contains(int* a, int len, int daCercare){

    len -= 1;
    while(len>=0  && a[len]!=daCercare)
        len--;
        
    return len >= 0; //se len >= 0 elemento trovato
}

int intersezione(int*a,int* b, int* r, int lenA, int lenB){
    
    int lenR=0;
    
    for(int i = 0; i<lenA; i++){
        if (contains(b, lenB, a[i])){
            r[lenR]=a[i];
            lenR++;
        } 
    }
    return lenR;
}


int main(void){
    
    int len1, len2;
    do{
        printf("Fornisci lunghezza primo array ");
        scanf("%d",&len1);
    }while (len1>30);
    
    do{
        printf("Fornisci lunghezza secondo array ");
        scanf("%d",&len2);
    }while (len2>30);
    
    int len3 = len1 * len2;
    int a[len1], b[len2], r[len3];
    
    
    inputArray(a, len1);
    inputArray(b, len2);
    
    len1 = deleteDuplicate(a, len1);
    len2 = deleteDuplicate(b, len2);
    
    printf("Primo Array\n");
    printArray(a, len1);
    printf("Secondo Array\n");
    printArray(b, len2);
    
    len3 = intersezione(a, b, r, len1, len2);
    printf("Array Risultante\n");
    printArray(r, len3);
}
