#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
void rotationDecryption(char *inputText, int key);
void rotationEncryption(char *cipherText, int key);
void rotationBruteForceAttack(char *cipherText);
void newrotationBruteForceAttack(char *cipherText, int key);
void SubstitiutionEncryption(char *cipherText, char *subKey);
void arraycopy(char *array, char *arrayCopy);
int sizeOfArray(char *cipherText);


int main() {

    int choice = 1;
    
    while (choice < 7 && choice > 0) {
    
        printf("Please enter:\n"
        "1 for 'Encryption of a message with a rotation cipher given the message text and rotation amount'\n"
        "2 for 'Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount'\n"
        "3 for 'Encryption of a message with a substitution cipher given message text and alphabet substitution'\n"
        "4 for 'Decryption of a message encrypted with a substitution cipher given cipher text and substitutions'\n"
        "5 for 'Decryption of a message encrypted with a rotation cipher given cipher text only'\n"
        "6 for 'Decryption of a message encrypted with a substitution cipher given cipher text only'\n"
        "press any other number to exit program\n");
        
        char inputText[1000];
        char cipherText[1000];
        
        char subKey[26];
        int key = 1;
        char b = 1;
        int k = sizeOfArray(cipherText) - 1;
        char arrayCopy[k];

        
        scanf("%d",&choice);

        switch (choice) {
        case 1:
        
          // key* determines how far the message is translated
          // printf("enter text to be encrypted:\n"); // takes user input for
          // text to be encrypted fgets(inputText, 100, stdin); // stores user
          // user input in array 'inputText'  have used fgets in lieu of
          // anything bettter as i dont know how to stroe white space in an
          // array...

          printf("Enter text to be encrypted: NOTE to end entry press Tab followed by Enter\n");
          scanf("%[^\t]s", inputText);
          // fgets(inputText, 100, stdin);

          printf("enter key:\n"); // prints 'enter key:' then starts new line
          scanf(" %d", &key);

          rotationEncryption(inputText, key);

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
              "Enter text to be decrypted: NOTE to end entry press Tab followed by Enter\n");
          scanf(" %[^\t]s", cipherText);

          printf("enter key:\n"); // prints 'enter key:' then starts new line
          scanf(" %d", &key);

          rotationDecryption(cipherText, key);

          // 2. Decryption of a message encrypted with a rotation cipher given
          // cipher text and rotation amount
          break;
        case 3 :
            printf("Enter text to be encrypted: NOTE to end entry press Tab, followed by enter\n");
            scanf(" %[^\t]s", cipherText);

            printf("enter alphabet subsitution: NOTE Key must be 26 characters with no repetition,to end entry press Tab followed by enter\n"); // prints 'enter alphabet subsitution:' then starts new line
            scanf(" %[^\t]s", subKey);
            
            SubstitiutionEncryption(cipherText, subKey);
            

            // 3. Encryption of a message with a substitution cipher given message
            // text and alphabet substitution
            
            break;
        case 4 :
        
        
          break;
        case 5 :
        printf("Enter text to be decrypted: NOTE to end entry press Tab followed by Enter\n");
            scanf(" %[^\t]s", cipherText);
           
            for (int key = 1; key < 27; key++) {
                arraycopy(cipherText, arrayCopy);
                newrotationBruteForceAttack(arrayCopy, key);
            }
          // 5. Decryption of a message encrypted with a rotation cipher given
          // cipher text only
          break;
        case 6 :
          // 6. Decryption of a message encrypted with a substitution cipher
          // given cipher text only
          break;
        default :
          printf("Thankyou for using my program!\n");
        }
    }
}

//Encryption function takes a string and an integer key and for every character in the string if it is between a and z ascii values the value of that char is minused by 32 to give the capital of that letter then the key is added to the char if it is within the ascii value of A and Z. the characters are reassembled into a string and the string is printed.

void rotationEncryption(char *inputText, int key) {
    
    char x; //temp store of individual characters
    int i = 0; // counter integer

    
            
        for (i = 0; inputText[i] != '\0'; ++i) { //for loop that runs unless item of array is null not sure when this would be used this as it was used by others and well it works.
          x = inputText[i]; //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop
            
            if(x >= 'a' && x <= 'z') { //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
                x = x - 32;
                //x = x + key; // reassigns value of x as previous value of x + key value ||||| will change to x = x - 32; to change all lower case letters to uppercase 


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

                
              
            }
            if(x1 >= 'A' && x1 <= 'Z') { 
                x1 = x1 - key;

                if (x1 < 'A')
                    x1 = x1 +'Z' - 'A' + 1;
            }
            
        cipherText[i] = x1; //recompiles 'inputText[]' with individual chars from for loop which has encrypted them 
        
        }

    printf("Decrypted message: %s\n", cipherText); //prints "decrypted message: ************" then creates new line.
}

void rotationBruteForceAttack(char *cipherText) {
    
    char x1; //temp store of individual characters
    int i = 0; // counter integer
    int key = 0;
    
    for (key = 0; key < 27; ++key) {
        for (i = 0; cipherText[i] != '\0'; ++i) {                                                                                       //for loop that runs unless item of array is null not sure when this would be used this as it was used by others and well it works.
            x1 = cipherText[i];                                                         //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop

            if(x1 >= 'a' && x1 <= 'z') { //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
                x1 = x1 - 32; // reassigns value of x as previous value of x + key value ||||| will change to x = x - 32; to change all lower case letters to uppercase 



            }
            if(x1 >= 'A' && x1 <= 'Z') { 
                x1 = x1 - key;

                if (x1 < 'A')
                    x1 = x1 +'Z' - 'A' + 1;
            }
            
            cipherText[i] = x1; //recompiles 'inputText[]' with individual chars from for loop which has encrypted them 
        
        }
        //if (cipherText[1] == 'T')
        printf("Decrypted message: %s\n", cipherText);
    }

}



void arraycopy(char *cipherText, char *arrayCopy) {
    
    for (int i = 0; cipherText[i] != '\0'; ++i) {
        arrayCopy[i] = cipherText[i];
    }
}

int sizeOfArray(char *cipherText) {
    int i;
    for (i = 0; cipherText[i] != '\0'; ++i) {}
    return i;
}

void newrotationBruteForceAttack(char *cipherText, int key) {
    
    char x1;
    int i = 0;//temp store of individual characters
    
    
    
        for (i = 0; cipherText[i] != '\0'; ++i) {                                                                                      
            x1 = cipherText[i];

            if (x1 >= 'a' && x1 <= 'z') {
                x1 = x1 - 32;
                
                
            }

            if (x1 >= 'A' && x1 <= 'Z') {
                x1 = x1 - key;

                if (x1 < 'A') {
                  x1 = x1 + 'Z' - 'A' + 1;
                }
            cipherText[i] = x1;
            }
        }
        //if ((cipherText[i] == 'T' && cipherText[i + 1] == 'H' && cipherText[i + 2] == 'E') || (cipherText[i] == 'I' && cipherText[i + 1] == 'T') || (cipherText[i] == 'H' && cipherText[i + 1] == 'E' && cipherText[i + 2] == 'L' && cipherText[i+3] == 'L' && cipherText[i+4] == 'O')){
            printf("Decrypted message: %s\n", cipherText);
        //}
}

void SubstitiutionEncryption(char *cipherText, char *subKey) {
    
    char x1, x2, x3, x4;
    char alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    // sub jey is is equl to something... ......
    int i;
   
    if (strlen(alphabet) != strlen(subKey)) {
        printf("Please correct key");
        printf("%lu, %lu", strlen(alphabet), strlen(subKey));
        }
        

    else for (i = 0; cipherText[i] != '\0'; ++i) {                                                                                      
            x1 = cipherText[i];
            
            //the cipherText[1] = h
            //    cipherText[2] = e
            //    cipherText[3] = l
        const char* ptr = strchr(alphabet, tolower(cipherText[i]));
	    int oldCharIndex = ptr - alphabet;
        printf("%d  ,  %s\n",oldCharIndex, ptr);
       /* if (ptr && oldCharIndex >= 0) {
            if (cipherText[i] = isupper(cipherText[i])) {
            toupper(subKey[oldCharIndex])
            }
            
            else subKey[oldCharIndex];
        }*/
    cipherText[i] = x1;   
    }

                        
            
            /*
            if (x1 >= 'a' && x1 <= 'z') {
                x1 = x1 - 32;   
            }
            
            
                                                                                    // therefore all values from copher text will be beteween 65 and 90 or we dont want to change them.
            if (x1 >= 'A' && x1 <= 'Z') {

            }
            */

    
    
printf("encrypted message: %s\n", cipherText);
}

