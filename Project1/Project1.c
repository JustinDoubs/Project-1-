#include<stdio.h>
#include<unistd.h>
void rotationDecryption(char *inputText, int key);
void rotationEncryption(char *inputText, int key);
void SubstitiutionEncryption(char *inputText, char *subKey);
int main() {

    int choice = 0;
    
    while (choice != 7) {
    
        printf("Please enter;\n"
        "1 for 'Encryption of a message with a rotation cipher given the message text and rotation amount'\n"
        "2 for 'Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount'\n"
        "3 for 'Encryption of a message with a substitution cipher given message text and alphabet substitution'\n"
        "4 for 'Decryption of a message encrypted with a substitution cipher given cipher text and substitutions'\n"
        "5 for 'Decryption of a message encrypted with a rotation cipher given cipher text only'\n"
        "6 for 'Decryption of a message encrypted with a substitution cipher given cipher text only'\n"
        "7 to exit program\n");
        
        char inputText[1000];
        char cipherText[1000];
        char subKey[26];
        int key = 1;        
        char b = 1;
        
        scanf("%d",&choice);

        switch (choice) {
        case 1:
        
          // key* determines how far the message is translated
          // printf("enter text to be encrypted:\n"); // takes user input for
          // text to be encrypted fgets(inputText, 100, stdin); // stores user
          // user input in array 'inputText'  have used fgets in lieu of
          // anything bettter as i dont know how to stroe white space in an
          // array...

          printf("Enter text to be encrypted: NOTE to end entry press Tab\n");
          scanf("%[^\t]s", inputText);
          // fgets(inputText, 100, stdin);

          printf("enter key:\n"); // prints 'enter key:' then starts new line
          scanf(" %d", &key);

          rotationEncryption(inputText, key);
          
          sleep(5);
            break;
        case 2:
          // printf("enter text to be encrypted:\n"); // takes user input for
          // text to be encrypted fgets(inputText, 100, stdin); // stores user
          // user input in array 'inputText'  have used fgets in lieu of
          // anything bettter as i dont know how to stroe white space in an
          // array...

          // printf("enter key:\n"); //prints 'enter key:' then starts new line
          // scanf("%d", &key); // stores user input in integer 'key'
          printf(
              "Enter text to be decrypted: NOTE to end entry press Tab\n");
          scanf(" %[^\t]s", cipherText);

          printf("enter key:\n"); // prints 'enter key:' then starts new line
          scanf(" %d", &key);

          rotationDecryption(cipherText, key);
          sleep(5);
          // 2. Decryption of a message encrypted with a rotation cipher given
          // cipher text and rotation amount
          break;
        case '3':
          // 3. Encryption of a message with a substitution cipher given message
          // text and alphabet substitution
          break;
        case '4':
          // 4. Decryption of a message encrypted with a substitution cipher
          // given cipher text and substitutions
          break;
        case '5':
          // 5. Decryption of a message encrypted with a rotation cipher given
          // cipher text only
          break;
        case '6':
          // 6. Decryption of a message encrypted with a substitution cipher
          // given cipher text only
          break;
        default:
          printf("Thankyou for using my program!\n");
        }
    }
}

//ENcryption function

void rotationEncryption(char *inputText, int key) {
    
    char x; //temp store of individual characters
    int i = 0; // counter integer

    
            
        for (i = 0; inputText[i] != '\0'; ++i) { //for loop that runs unless item of array is null not sure when this would be used this as it was used by others and well it works.
          x = inputText[i]; //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop
            
            if(x >= 'a' && x <= 'z') { //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
                x = x - 32;
                //x = x + key; // reassigns value of x as previous value of x + key value ||||| will change to x = x - 32; to change all lower case letters to uppercase 

              //if(x > 'z') //if the ascii value of 'x' is greater than the ascii value of 'z' then next line will run 
              //  x = x - 'z' + 'a' - 1; //ascii value of x - 26 |||||||||||| should change this to mod 26 when i have re assigned alphabet chars to 0 to 26|||||||||||||
            } 
            if (x >= 'A' && x <= 'Z') {
            x = x + key;

            if (x > 'Z')
              x = x - 'Z' + 'A' - 1;
          }

          inputText[i] = x; // recompiles 'inputText[]' with individual chars
                            // from for loop which has encrypted them 

     }

    printf("Encrypted message:\n %s\n", inputText); //prints "Encrypted message: ************" then creates new line.
}


//decryption

void rotationDecryption(char *cipherText, int key) {
    
    
    char x1; //temp store of individual characters
    int i = 0; // counter integer

    
    
        for (i = 0; cipherText[i] != '\0'; ++i) {                                                                                       //for loop that runs unless item of array is null not sure when this would be used this as it was used by others and well it works.
            x1 = cipherText[i];                                                         //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop

            if(x1 >= 'a' && x1 <= 'z') { //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
                x1 = x1 - 32; // reassigns value of x as previous value of x + key value ||||| will change to x = x - 32; to change all lower case letters to uppercase 

              //if(x1 > 'z') //if the ascii value of 'x' is greater than the ascii value of 'z' then next line will run 
                //x1 = x1 - 'z' + 'a' - 1; //ascii value of x - 26 |||||||||||| should change this to mod 26 when i have re assigned alphabet chars to 0 to 26|||||||||||||
            }
            if(x1 >= 'A' && x1 <= 'Z') { 
                x1 = x1 - key;

                if (x1 > 'Z')
                    x1 = x1 -'Z' + 'A' - 1;
            }
            
        cipherText[i] = x1; //recompiles 'inputText[]' with individual chars from for loop which has encrypted them 
        
        }

    printf("Decrypted message: %s\n", cipherText); //prints "decrypted message: ************" then creates new line.
}

//void SubstitiutionEncryption(char *inputText, char *subKey) {
    
    //for ( int i = 0; )

/*_________________________________________________________________________________________________________________________________________________________   
    
    
    
    
    
// 1. Encryption of a message with a rotation cipher given the message text and rotation amount
//rotationEncryption(inputText, key) {    
    char inputText[100];//  array with ample range for any text input
    int i = 0; // counter integer
    char x; //temp store of individual characters
    int key; // key* determines how far the message is translated 
    printf("enter text to be encrypted:\n"); // takes user input for text to be encrypted
    fgets(inputText, 100, stdin); // stores user user input in array 'inputText'  have used fgets in lieu of anything bettter as i dont know how to stroe white space in an array... 
    //scanf("%s", inputText); // tried to store input in array but it stops at white space
    
    printf("enter key:\n"); //prints 'enter key:' then starts new line 
    scanf("%d", &key); // stores user input in integer 'key'
    
    
        for (i = 0; inputText[i] != '\0'; ++i) { //for loop that runs unless item of array is null not sure when this would be used this as it was used by others and well it works.
          x = inputText[i]; //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop
          if(x >= 'a' && x <= 'z') { //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
              x = x + key; // reassigns value of x as previous value of x + key value ||||| will change to x = x - 32; to change all lower case letters to uppercase 
              if(x > 'z') //if the ascii value of 'x' is greater than the ascii value of 'z' then next line will run 
                x = x - 'z' + 'a' - 1; //ascii value of x - 26 |||||||||||| should change this to mod 26 when i have re assigned alphabet chars to 0 to 26|||||||||||||
          }else if(x >= 'A' && x <= 'Z') { 
              x = x + key;
              if (x > 'Z')
                x = x -'Z' + 'A' - 1;
          }
         inputText[i] = x; //recompiles 'inputText[]' with individual chars from for loop which has encrypted them 
     }
    printf("Encrypted message: %s\n", inputText); //prints "Encrypted message: ************" then creates new line.
    
    return 0; //exits main
// 2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
// 3. Encryption of a message with a substitution cipher given message text and alphabet substitution
// 4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
// 5. Decryption of a message encrypted with a rotation cipher given cipher text only
// 6. Decryption of a message encrypted with a substitution cipher given cipher text only
}
_____________________________________________________________________________________________________________
*/

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
 * hich assigns all letters to numbers from 0 to 25
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