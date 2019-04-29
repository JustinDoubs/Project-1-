#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
void rotationDecryption(char *inputText, int key);
void rotationEncryption(char *cipherText, int key);
void rotationBruteForceAttack(char *cipherText);
void substitutionDecryption(char *cipherText, char *subKey);
void substitutionEncryption(char *cipherText, char *subKey);
void arraycopy(char *array, char *arrayCopy);
int sizeOfArray(char *cipherText);
int foundInDictionary(char* word);
int found(char* word);


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


        char cipherText[100000];                  // creating string to store the users text in to be encrypted or decrypted
        char text[] = {"THE AND DO HELLO "};
        char text2[] = {"CLIck"};
        char subKey[26];                        // string to store users input of the Key for subsititution encryption and decryption.
        int key = 1;                            // initialization of the key used in rotation encryption and decryption.
        int k = sizeOfArray(cipherText);        // initialises k as the value of the size of the string cipher text ( inputed by the user)       // maybe should have + 1
        char arrayCopy[k+1];                    // string used for storing a duplicate of the cipherText string for manipulations in the rotation brute force attack which has the size of cipher text.


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

                printf("Enter text to be dDecrypted: NOTE to end entry press Tab followed by Enter\n");                // prints messsage asking for text input and specifies how it should be done.
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

                printf("Enter text to be decrypted: NOTE to end entry press Tab, followed by enter\n");               // prints message asking for text input to be encrypted and specifies how it should be done.
                scanf(" %[^\t]s", cipherText);                                                                        // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.

                printf("enter alphabet subsitution: NOTE Key must be 26 characters with no repetition,to end entry press Tab followed by enter\n"); // prints 'enter alphabet subsitution:' then starts new line
                scanf(" %[^\t]s", subKey);                                                                            // reads string of a new alphabet and stores it in subKey input needs to be 26 characters and with no repetition

                substitutionDecryption(cipherText, subKey);

                break;

            // case 5 is brute force decryption of rotation cipher given encrypted text.

            case 5 :
                printf("Enter text to be decrypted: NOTE to end entry press Tab followed by Enter, Note also if decryption is unsuccessful please shorten message\n");                // asks for encrypted text to be entered for decryption and how it is to be done
                scanf(" %[^\t]s", cipherText);                                                                        // scans text and stores it in cipherText array, text is stopped being read by exit specifier 'tab' then 'enter' keys.


                for (int key = 0; key < 26; key++) {                                                                  // for 26 iterations i is incremented
                    arraycopy(cipherText, arrayCopy);                                                                 // calls arraycopy with cipher text and arrayCopy (function copies cipher text to arrayCopy)
                    rotationDecryption(arrayCopy, key);                                                               // calls rotationDecryption function which takes arrayCopy and key see rotationDecryption defnition for more info

                    char firstWord[148];                                                                              // array firstWord has size 148
                    //char secondWord[148];
                    int i;                                                                                            // counter integer i is declared


                    
                    for (i = 0; arrayCopy[i] != 32; i++) {                                                            // for loop that increments i, ad run till arrayCopy at i is a space
                        firstWord[i] = arrayCopy[i];                                                                  // the value of firstWord at i becomes the value of arrayCopy at i 
                                        
                    }
                    //printf("1. %s \n",firstWord);                  
                    
                    firstWord[i] = '\0';                                                                              // firstWord at i is equal to a null character 
                    
                    if (found(firstWord) == 1 ) {                                                                     // if statement that runs next line if the found function returns 1
                        printf("Decrypted Message: %s\n", arrayCopy);                                                 // prints decrypted message
                    }

                }

                break;

            case 6 :
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



        for (i = 0; inputText[i] != '\0'; ++i) {                // for loop that runs unless item of array is null with incrementing i integer
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



    for (i = 0; cipherText[i] != '\0'; ++i) {                   // for loop runs unless item of array is null with incrementing i integer
        x1 = cipherText[i];                                     // stores each individual character of 'inputText[]' in char variable 'x' for one rendition of the loop

        if(x1 >= 'a' && x1 <= 'z') {                            //if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'a' and less than ascii value of 'z' then runs next line
            x1 = x1 - 32;                                       // value of x is replaced with x - 32 (all characters between a to z are replaced with their couplet in uppercase)
            }


        if(x1 >= 'A' && x1 <= 'Z') {                            // if the ascii value of a char from 'inputText' being stored in 'x' is greater than ascii value of 'A' and less than ascii value of 'Z' then runs next line
            x1 = x1 - key;                                      // that value of 'x1' is replaced with the value of 'x1' minus the value of the key (given to the function)

            if (x1 < 'A')                                       // if the value of 'x1' becomes less that the ascii value of 'A' then the next line is run
                x1 = x1 +'Z' - 'A' + 1;                         // replaces x1 with x1 + 26    (this line is implemented when a letter is rotated beyond the A to Z set, it puts the letter back at Z and lets it continue rotating from there.
            }

        cipherText[i] = x1;                                     // replaces cipherText[1] with the value of 'x1'
        }
}

// arraycopy function is a function that takes two arrays (cipherText and arrayCopy) and copies the first given array to the sencond
// by running through a for loop which replaces each character with the value of each character from the first array

void arraycopy(char *cipherText, char *arrayCopy) {

    for (int i = 0; cipherText[i] != '\0'; i++) {               // declares integer i & for loop runs unless item of array is null with incrementing i integer
        arrayCopy[i] = cipherText[i];                           // arrayCopy's character at position 'i' is replaced with cipherText's character at position 'i'
    }
}

// sizeOfArray function is a function that take 1 array and runs through a for loop with incremting 'i' that runs untill given array is null therefor assigning i the length of the array

int sizeOfArray(char *cipherText) {
    int i = 0;                                                  // initialisation of counter integer 'i'
    for (i = 0; cipherText[i] != '\0'; i++) {}                  // for loop runs unless item of array is null with incrementing i integer
    return i;                                                   // returns value of 'i' which is the length of the array
}

// substitutionDecryption function takes 2 arrays one being the text to be decrypted the other being a 26 character long string with no repetition of characters.
// the text from cipherText is decrypted by using a for loop and running through each letter in cipherText, making every character uppercase and then running through each character in the subKey with a for loop checking if
// the character at cipherText[i] is equal to any of the characters in subKey and if it is the incrementer 'k' is saved and that is used in the next if statement. which is if the character from cipherText is between A and Z
// then its value is replaced with the position of the identical character in subKey previously given by 'k' plus 65 to give it in a character from A to Z. then the decrypted message is printed.

void substitutionDecryption(char *cipherText, char *subKey) {

    int x1 = 0;                                                     // initialisation and declaration of 'x1'
    int i = 0;                                                      // initialisation and declaration of 'i' as a counter variable for cipherText
    int k = 0;                                                      // initialisation and declaration of 'k' as a counter variable for subKey

    for (i = 0; cipherText[i] != '\0'; i++) {                       // for loop that runs while cipherText does not equal null, incrementing 'i'
        x1 = cipherText[i];                                         // 'x1' is set equal to cipherText at 'i'


        if (x1 >= 'a' && x1 <= 'z') {                               // setting each char from cipher text to capitals as in previous functions.
            x1 = x1 - 32;
        }

        for(k = 0; (subKey[k] != '\0'); k++) {                      // for loop that increments k and runs if subKey is not null
            if (subKey[k] == x1)                                    // if subkey at k is equal to the current value of 'x1'
                break;                                              // then the for loop is exited
        }

        if (x1 >= 'A' && x1 <= 'Z') {                               // if character from cipherText at 'i' (x1) is between A and Z then 'x1' becomes k + 65
            x1 = k + 65;
        }

    cipherText[i] = x1;                                             // cipherText[1] becomes the value of 'x1'

    }

printf("Decrypted message: %s\n", cipherText);                      // prints the decrypted message (cipherText)
}

// substitutionEncryption function takes two arrays an array that has text to be encrypted and an array of 26 characters with no repitition, the text is encrypted by using a for loop that increments 'i' and runs till 
// cipherText is null and running through each character in cipherText and setting 'x1' to equal the current value of cipherText at 'i' and converting it to upper case if it is a character between 'a' and 'z', and if
// it is between 'A' and 'Z' the 'x1' is replaced with the value of subKey at ('x1' - 65) the value of cipherText at 'i' is replaced with the value of 'x1' then outside of the for loop the encryped message is printed

void substitutionEncryption(char *cipherText, char *subKey) {

    int x1 = 0;                                                     // initialisation and declaration of 'x1' as a temporary integer to hold the ascii value of the character of cipherText being manipulated
    int i = 0;                                                      // initialisation and declaration of 'i'

    for (i = 0; cipherText[i] != '\0'; ++i) {                       // for loop incrementing 'i' and running till cipherText is equal to null
        x1 = cipherText[i];                                         // changing the value of x1 to the value of cipherText at 'i'

        if (x1 >= 'a' && x1 <= 'z') {                               // if the value of 'x1' is between the ascii values of 'a' and 'z' then next line runs
            x1 = x1 - 32;                                           // the value of 'x1' is replaced with the value of 'x1' - 32
        }

        if (x1 >= 'A' && x1 <= 'Z') {                               // if the value of 'x1' is between the ascii values of 'A' and 'Z' then next line runs
            x1 = subKey[x1 - 65];                                   // the value od 'x1' is replaced with the value of the character of subKey at (the value of 'x1' - 65)
        }
    cipherText[i] = x1;                                             // the value of cipherText at 'i' is equal to the value of 'x1'

    }
printf("Encrypted message:\n %s\n", cipherText);                    // prints the encrypted message (cipherText)
}

// found function opens a file that contains 20000 most used words and takes a word and chages that word to lowercase as all the words in the file are lower case 
// and compares that to each word in the file to see if it is actually a word if it is the functoin returns 1

int found(char* word) {                                             // takes array 
    FILE* everyWord;                                                // declares everyWord as a file
    everyWord = fopen("Words.txt", "r");                            // initalises everyWord as Words.txt and opens Words.txt for reading

    int i = 0;                                                      // initialisation and declaration of 'i'
    char temp[32];                                                  // declaration of array with size of 32 called temp for storing words from the file 
    int matchResult = 0;                                            // initialisation and declaration of match result
    if (everyWord != NULL) {                                        // if statement which only runs if the file exist or is not equal to null
        
        for (i = 0;word[i] != '\0'; i++) {                          // for loop that increments 'i' and runs through word till it is equal to null
            if (word[i] >= 'A' && word[i] <= 'Z') {                 // if word at 'i' is between A and Z then next line runs 
               word[i] = word[i] + 32;                              // word at i is equal to word at i + 32 (changes each letter to lowercase)
            }

        }
        
        //while (fscanf(everyWord, "%[\32]s", temp)) {
        while (fgets(temp, 32, everyWord)){                         // while loop that take each word from file and stores it in temp line by line
            //printf("hi %s",temp);
            if (strstr(temp, word) != NULL) {                       // if statement that runs next line if the array word is found in the array temp
                matchResult = 1;                                    // changes the value of match result to 1
                break;                                              // breaks out of while statement
            }
            
        }

        //printf("%s\n",word);
        return matchResult;                                         // returns matchResult
    }
    else 
    return 0;
}

