#include<stdio.h>

int main() {
// 1. Encryption of a message with a rotation cipher given the message text and rotation amount
    char inputText[100];
    int i = 0;
    char x;
    int key; 
    printf("enter text to be encrypted:\n");
    fgets(inputText, 100, stdin);
    //scanf("%s", inputText);
    
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
// 2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
// 3. Encryption of a message with a substitution cipher given message text and alphabet substitution
// 4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
// 5. Decryption of a message encrypted with a rotation cipher given cipher text only
// 6. Decryption of a message encrypted with a substitution cipher given cipher text only
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
//this would only work if the letters a to z were re assigned values of 0 - 25//
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
int encryption(int x) {
	return (message + key)(% 26);
}
int decryption(int c) {
	return (cipher - key)(% 26);
}
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
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

