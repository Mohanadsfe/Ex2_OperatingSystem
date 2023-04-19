#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

int encode(char *src, char *dst, int len){
        printf("hello world\n"); // printing the answer

    printf("%s\n", src); // printing the answer

for (size_t i = 0; i < len; i++)
{


        if(isalpha(src[i])) {

        if( islower(src[i])){

            dst[i] = toupper(src[i]);
            
        }

         if(isupper(src[i])){

            dst[i] = tolower(src[i]);
            

          } 


        }
        else{
                       

            dst[i] = (char) src[i];
             

            
        }

    }
    dst[len]='\0';


    return 1;
}

int decode(char *src, char *dst, int len){


    for(int i = 0; i < len; i++){
                

        if(isalpha(src[i]) && islower(src[i])){
            dst[i] = toupper(src[i]);
        }
        else if(isalpha(src[i]) && isupper(src[i])){
            dst[i] = tolower(src[i]);
        }
        else{
            dst[i] = src[i];
        }
    }

    dst[len]='\0';

    return 1;
}

