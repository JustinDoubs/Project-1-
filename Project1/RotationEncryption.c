#include<stdio.h>
/*()
void rotationEncryption(char *inputText, int key);

int main()
{
    char inputText[100];//  array with ample range for any text input
    int key; // key* determines how far the message is translated 
    printf("enter text to be encrypted:\n"); // takes user input for text to be encrypted
    fgets(inputText, 100, stdin); // stores user user input in array 'inputText'  have used fgets in lieu of anything bettter as i dont know how to stroe white space in an array... 
    //scanf("%s", inputText); // tried to store input in array but it stops at white space
    
    printf("enter key:\n"); //prints 'enter key:' then starts new line 
    scanf("%d", &key); // stores user input in integer 'key'
    
    rotationEncryption(inputText, key);
    
    
}
*/

void rotationEncryption(char *inputText, int key) {
    
    char x; //temp store of individual characters
    int i = 0; // counter integer

    
    
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
}
