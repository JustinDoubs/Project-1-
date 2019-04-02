/**
 * need message 
 * message is in ascii
 * change to 0 and 26 
 * 
 * 
 * decrypt it 
 * 
 * 
 */

#include<stdio.h>

int main() {
    char inputText[100];
    int i = 0;
    char x;
    int key; 
    printf("enter text to be encrypted:\n");
    scanf("%s", inputText);
    
    printf("enter key:\n");
    scanf("%d", &key);

    for (i = 0; inputText[i] != '\0'; ++i) {
      x = inputText[i];
      
      if(x >= 'a' && x <= 'z') {
          x = x + key;
          
          if(x > 'z')
            x = x - 'z' + 'a' - 1;
            
      }else if(x >= 'A' && x <= 'Z') {
          x = x + key;
          
          if (x > 'Z')
            x = x -'Z' + 'A' - 1;
      }
     inputText[i] = x;  
    
    }
    printf("Encrypted message: %s\n", inputText);
    
    return 0;
}

/**
    
    
	switch(a) : 
		case 'a' : 
			//lets make this encryption option
			//call encryption function encyption(x)
			return;
		case 'b' : 
			//this can be decryption
			//call decryption function decryption(c)
			return;
}

int encryption(int x) {
	return (message + key)(% 26);
}
int decryption(int c) {
	return (cipher - key)(% 26);
}
*/



/** 
 *  to do- 
 * -----------------------------------------
 * create a key which assigns all letters to numbers from 0 to 25
 * 
 * take string of words 
 * do math on each letter and rewrite message in decrypted form 
 * 
 * 
 * 
 * 
 * 
 * 
 */








//gcc Project1.csubsititution cipher is array stuff stuff stuff. 

