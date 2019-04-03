/**#include <stdio.h>
int stringLength(char *str);

int main() {
    char str[] = "hello world";
    printf("%d\n",stringLength(str));
    
}

int stringLength(char *str) {
    int length = 0;         //if 
    
    while(str[++length]);  //while looops condition is str[] at some index, will execute unless value is zero. 
    
--------------------------- commented out. 
    while(str[length]) {
      if (str[length] != 0) {               //can change str[length] to a char to moniter the value of str[length]
        length++;
      }
    }
-----------------
    return length;
}
**/