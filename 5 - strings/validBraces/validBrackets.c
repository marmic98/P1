#include <stdio.h>
#include <string.h>

int validParentheses(const char *str_in) {

  int countO = 0, countC = 0, lenStr = strlen(str_in), flag = 0; 
  for (int i = 0; i < lenStr; i++){
    if (str_in[i] == '('){
      countO++;
      flag = 0;
    }
    else if (str_in[i] == ')'){
        countC++;
        flag = 1;
    }
  }
  return countO == countC && flag == 1;
}

int main(void){
    char strIn[] = {"(())"};
    validParentheses(strIn) ? printf("Valid\n") : printf("Not valid\n");
}