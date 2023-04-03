#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

int encode(char *src, char *dst, int len){
    for(int i = 0; i < len; i++){
        // Checking if the current char is alphabet char and is in lower case - if it is we will make it upper case
        if(isalpha(src[i]) && islower(src[i])){
            dst[i] = toupper(src[i]);
        }
        // Checking if the current char is alphabet char and is in upper case - if it is we will make it lower case
        else if(isalpha(src[i]) && isupper(src[i])){
            dst[i] = tolower(src[i]);
        }
        // not an alphabet char, so we will just copy it.
        else{
            dst[i] = src[i];
        }
    }
    return 1;
}

int decode(char *src, char *dst, int len){
    for(int i = 0; i < len; i++){
        // Checking if the current char is alphabet char and is in lower case - if it is we will make it upper case
        if(isalpha(src[i]) && islower(src[i])){
            dst[i] = toupper(src[i]);
        }
        // Checking if the current char is alphabet char and is in upper case - if it is we will make it lower case
        else if(isalpha(src[i]) && isupper(src[i])){
            dst[i] = tolower(src[i]);
        }
        // not an alphabet char, so we will just copy it.
        else{
            dst[i] = src[i];
        }
    }
    return 1;
}

