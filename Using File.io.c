/**#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}

 files are accessed using streams. stout and stin are streams.
variable type is a 'FILE *' 


FILE *input 

before using a file must open it 
with fopen()                        needs file domain and whether it is read/write/both  

FILE *fopen(const char *name, const char *mode)

*mode can be    
                'r' reading a file
                'r+'reading and writing 
                'w' writing 
                'w+'reading and writing (file is trunated)
                'a' appending 
________________________________
FILE *input;
input = fopen("data.txt", "r");
________________________________

fopen() can have errors such as not enough space file doesnt exist therefor check return value of fopen()
_________________________________________________
FILE *input;
input = fopen("data.txt", "r");
if(input == NULL) {
    perror("fopen()");
    return 1;
}
_____________________________________________________

