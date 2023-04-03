#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

int encode(char *src, char *dst, int len){
    for(int i = 0; i < len; i++){
        printf("%d\n", src[i]);
        // switch bits
        src[i] = ~src[i];
        printf("%d\n", src[i]);
        // adding 1
        src[i]+=1;
        printf("%d\n", src[i]);
        // convert back to char
        dst[i] = (char) src[i];
    }
    return 1;
}

int decode(char *src, char *dst, int len){


    for(int i = 0; i < len; i++){



        dst[i] = src[i] - 3;


    }
    return 1;
}
