#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
void rotationDecryption(char *inputText, int key);
void rotationEncryption(char *cipherText, int key);
void rotationBruteForceAttack(char *cipherText);
void newrotationBruteForceAttack(char *cipherText, int key);
void substitutionDecryption(char *cipherText, char *subKey);
void substitutionEncryption(char *cipherText, char *subKey);
void arraycopy(char *array, char *arrayCopy);
int sizeOfArray(char *cipherText);


int main() {

    int choice = 1; //choice is set to 1 so that while statement is valid
    
    while (choice < 7 && choice > 0) { // while statement will run until a number greater than 7 and less that 0 is entered.
    
        printf("Please enter:\n"
                "1 for 'Encryption of a message with a rotation cipher given the message text and rotation amount'\n"
                "2 for 'Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount'\n"
                "3 for 'Encryption of a message with a substitution cipher given message text and alphabet substitution'\n"
                "4 for 'Decryption of a message encrypted with a substitution cipher given cipher text and substitutions'\n"
                "5 for 'Decryption of a message encrypted with a rotation cipher given cipher text only'\n"
                "6 for 'Decryption of a message encrypted with a substitution cipher given cipher text only'\n"
                "press any other number to exit program\n");
        
        
        char cipherText[1000];                  // creating string to store the users text in to be encrypted or decrypted        
        char subKey[26];                        // string to store users input of the Key for subsititution encryption and decryption.
        int key = 1;                            // initialization of the key used in rotation encryption and decryption.
        int k = sizeOfArray(cipherText);        // initialises k as the value of the size of the string cipher text ( inputed by the user)       // maybe should have + 1
        char arrayCopy[k];                      // string used for storing a duplicate of the cipherText string for manipulations in the rotation brute force attack which has the size of cipher text.

        
        scanf("%d",&choice);                    // takes input from user, overwriting the value of choice and therefore selecting the option from the menu.

        switch (choice) {                       // switch case statement for each of the menu options selected by scanf function above. 
            
            // case 1 is encryption of text using rotation cipher, text and key are inputed by user.
            
            case 1:                                                                                                                       

                printf("Enter text to be encrypted: NOTE to end entry press Tab followed by Enter\n");                // prints messsage asking for text input and specifies how it should be done.
                scanf("%[^\t]s", cipherText);                                                                         // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.
                
                printf("enter key:\n");                                                                               // prints 'enter key:' then starts new line               
                scanf(" %d", &key);                                                                                   // reads integer from user and stores it in the key variable.
                
                rotationEncryption(cipherText, key);                                                                  // calls rotationEncrytion() function, which takes cipher text wich is a string and key which is an integer between 0 and 26.
                                                                                                                      // definition of function below.
                break;                                                                                                // exits the switch case, printing the menu and asking for choice again.

            // case 2 is decryption of text using rotation cipher, encryptedtext and key are inputed by user.

            case 2:
             
                printf("Enter text to be encrypted: NOTE to end entry press Tab followed by Enter\n");                // prints messsage asking for text input and specifies how it should be done.
                scanf("%[^\t]s", cipherText);                                                                         // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.
                                
                printf("enter key:\n");                                                                               // prints 'enter key:' then starts new line               
                scanf(" %d", &key);                                                                                   // reads integer from user and stores it in the key variable.
                    
                rotationDecryption(cipherText, key);                                                                  // calls rotationDecryption function which takes cipher text which is a string and key which is an integer
                
                printf("Decrypted message: %s\n", cipherText);                                                        //prints "decrypted message: ************" then creates new line.
                
                break;
 
            // Case 3 is encryption of text using substitution cipher, text and key are inputed by user.
 
            case 3 :
                printf("Enter text to be encrypted: NOTE to end entry press Tab, followed by enter\n");               // prints message asking for text input to be encrypted and specifies how it should be done.
                scanf(" %[^\t]s", cipherText);                                                                        // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.
    
                printf("enter alphabet subsitution: NOTE Key must be 26 characters with no repetition,to end entry press Tab followed by enter\n"); // prints 'enter alphabet subsitution:' then starts new line
                scanf(" %[^\t]s", subKey);                                                                            // reads string of a new alphabet and stores it in subKey input needs to be 26 characters and with no repetition
                
                substitutionEncryption(cipherText, subKey);                                                          // call SubstitutionEncryption function which takes cipherText and subKey (both strings)
                
                break;
                
            // case 4 is decryption of text using substitution cipher, encrypted text and key are given 
                
            case 4 :
                
                printf("Enter text to be encrypted: NOTE to end entry press Tab, followed by enter\n");               // prints message asking for text input to be encrypted and specifies how it should be done.
                scanf(" %[^\t]s", cipherText);                                                                        // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.
    
                printf("enter alphabet subsitution: NOTE Key must be 26 characters with no repetition,to end entry press Tab followed by enter\n"); // prints 'enter alphabet subsitution:' then starts new line
                scanf(" %[^\t]s", subKey);                                                                            // reads string of a new alphabet and stores it in subKey input needs to be 26 characters and with no repetition
                
                substitutionDecryption(cipherText, subKey); 
            
                break;
                
            // case 5 is brute force decryption of rotation cipher given encrypted text. 
                
            case 5 :
                printf("Enter text to be decrypted: NOTE to end entry press Tab followed by Enter\n");                // asks for encrypted text to be entered for decryption and how it is to be done
                scanf(" %[^\t]s", cipherText);                                                                        // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.
               
                for (int key = 0; key < 26; key++) {                                                                  // for 26 iterations i is incremented 
                    arraycopy(cipherText, arrayCopy);                                                                 // calls arraycopy with cipher text and arrayCopy (function copies cipher text to arrayCopy)
                    rotationDecryption(arrayCopy, key);                                                               // calls newrotationBruteForceAttack function whic takes arrayCopy and key 
                    
                    printf("Decrypted Message:%s\n", arrayCopy);
                }
             
              break;
            case 6 :
              // 6. Decryption of a message encrypted with a substitution cipher
              // given cipher text only
              break;
              
            // if 1,2,3,4,5 or 6 are not selected then defult is selected.
            
            default : 
              printf("Thankyou for using my program!\n");                                                             // prints 'Thankyou for using my program!' new line 
        }
    }
}

// rotationEncryption function takes a string and an integer key and for every character in the string if it is between a and z ascii values the value of that char is minused by 32 
// to give the capital of that letter then the key is added to the char if it is within the ascii value of A and Z. the characters are reassembled into a string and the string 
// is printed.

void rotationEncryption(char *inputText, int key) {             // function does not return any value
    
    char x;                                                     // temporary store of individual characters
    int i = 0;                                                  // counter integer

    
            
        for (i = 0; inputText[i] != '\0'; ++i) {                // for loop that runs unless item of array is null
            x = inputText[i];                                   //stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop
            
            if(x >= 'a' && x <= 'z') {                          // if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
                x = x - 32;                                     // value of x is replaced with value of x - 31 (replaces all letters with their uppercase couplet)
            } 
            
            if (x >= 'A' && x <= 'Z') {                         // if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'A' and less than ascii value of 'Z' then runs next line
            x = x + key;                                        // value of x is replaced with value of x plus key value, (the character is rotated by the amount the key specifies)

                if (x > 'Z')                                    // when the key rotates a letter past Z it starts back at A and contines so that special char's are not mixed in.
                    x = x - 'Z' + 'A' - 1;
          }
          

          inputText[i] = x;                                     // recompiles 'inputText[]' with individual chars from for loop which has encrypted them 

     }

    printf("Encrypted message:\n %s\n", inputText);             //prints "Encrypted message: ************" then creates new line.
}


// rotationDecryption function takes a string (cipherText) and integer (key) and for every character in the string if it is between a and z ascii values the value of that char
// is minused by 32 to give the capital of that letter then the key is minused from the char if it is within the ascii value of A and Z. The characters are reassembled into a
// string and the string is printed.

void rotationDecryption(char *cipherText, int key) {
    
    
    char x1;                                                    // temporary store of individual characters
    int i = 0;                                                  // counter integer

    
    
    for (i = 0; cipherText[i] != '\0'; ++i) {                   // for loop runs unless item of array is null 
        x1 = cipherText[i];                                     // stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop

        if(x1 >= 'a' && x1 <= 'z') {                            //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
            x1 = x1 - 32;                                       // value of x is replaced with x - 32 (all characters between a to z are replaced with their couplet in uppercase)  
            }
            
//---------------------------------------------------------------------------------------------------------------------------------
            
        if(x1 >= 'A' && x1 <= 'Z') { 
            x1 = x1 - key;

            if (x1 < 'A')
                x1 = x1 +'Z' - 'A' + 1;
            }
            
        cipherText[i] = x1; //recompiles 'inputText[]' with individual chars from for loop which has encrypted them 55%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% cJARRGOONNNNN
        }
//printf("Decrypted message: %s\n", cipherText); //prints "decrypted message: ************" then creates new line.
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
    /*
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
            
            }
        cipherText[i] = x1;
        }
        */
       
       rotationDecryption(cipherText, key);
       
        //if ((cipherText[i] == 'H' && cipherText[i + 1] == 'E' && cipherText[i + 2] == 'L')) {
           // printf("Decrypted message: %s\n", cipherText);

          // || (cipherText[i] == 'I' && cipherText[i + 1] == 'T') ||
          // (cipherText[i] == 'H' && cipherText[i + 1] == 'E' && cipherText[i +
          // 2] == 'L' && cipherText[i+3] == 'L' && cipherText[i+4] == 'O')
        //}
}

void substitutionDecryption(char *cipherText, char *subKey) {
    
    int x1;
    int i;
    int k;
    //printf("%s\n%s", cipherText, subKey);
    for (i = 0; cipherText[i] != '\0'; i++) {
        x1 = cipherText[i];
        
        
        if (x1 >= 'a' && x1 <= 'z') {
            x1 = x1 - 32;
        }   
        
        for(k = 0; (subKey[k] != '\0'); k++) {
            if (subKey[k] == x1)
                break;
        }

        if (x1 >= 'A' && x1 <= 'Z') {
            x1 = k + 65;
        }
        
    cipherText[i] = x1;
       
    }

printf("encrypted message: %s\n", cipherText);
}

void substitutionEncryption(char *cipherText, char *subKey) {
    
    int x1;
    int i; 
    
    for (i = 0; cipherText[i] != '\0'; ++i) {
        x1 = cipherText[i];
        
        if (x1 >= 'a' && x1 <= 'z') {
            x1 = x1 - 32;
        }   

        if (x1 >= 'A' && x1 <= 'Z') {
            x1 = subKey[x1 - 65];
        }
    cipherText[i] = x1;
       
    }
printf("Encrypted message:\n %s\n", cipherText);
}

