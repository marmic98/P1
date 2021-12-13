#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(char* str){
    int lenStr = strlen(str);
    for (int i = 0; i < lenStr; i++){
            str[i] = tolower(str[i]);
    }
}

int isMaius(char c){
    return c >= 'A' && c <= 'Z';
}

int isMinus(char c){
    return c >= 'a' && c <= 'z';
}

void delete(char* a,int pos){
    int len = strlen(a);
	for(pos;pos<len;pos++){
		a[pos]=a[pos+1];
	}
	a[len-1] = '\0';
}

void onlyLetters(char* str){
    int i = 0;
    while(i < strlen(str)){
        if(isMaius(str[i]) || isMinus(str[i]))
            i++;
        delete(str, i);
    }
}

int deleteDuplicate(char* a){
	for (int j = 0; j < strlen(a); j++){
		int i=j+1;
		while(i < strlen(a)){
			if (a[j]==a[i]){
				delete(a,i);
			}
			else i++;
		}
	}
}

int posContains (char* str, char daCercare){
	int i = 0;
	int len = strlen(str);
	while(i < len && str[i] != daCercare){
		i++;
	}
	return i;
}

void sortStrPos(char* str, int pos){
	
	for(int i = pos; i < strlen(str) - 1; i++){
		for(int j = pos; j < strlen(str) - 1; j++){
			if (str[j] > str[j + 1]){
				char tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp; 
			}
		}
	}
	printf("%s\n", str);
}

void newAlphabet (char* alfabeto, char* str){
	int len = strlen(str);
	int lenAlphabet = strlen(alfabeto);
	
	for (int i = 0; i < len; i++){
		int pos = posContains(alfabeto, str[i]);
		if(pos != lenAlphabet){
			char tmp = alfabeto[pos];
			alfabeto[pos] = alfabeto[i];
			alfabeto[i] = tmp;  
		}	
	}
	sortStrPos(alfabeto, len);
	//simtcdrlbjkhenopqrafuvwxyz
	//simtcdrl
}

int main(void){
	char str[] = {"Sei mitico Duracell"};
    char alfabeto[] = {"abcdefghijklmnopqrstuvwxyz"};
	onlyLetters(str);
	lower(str);
	deleteDuplicate(str);
	newAlphabet(alfabeto, str);
	printf("%s\n%s\n", str, alfabeto);
}