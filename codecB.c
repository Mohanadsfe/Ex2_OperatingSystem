#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

int encode(char *src, char *dst, int len){
    for(int i = 0; i < len; i++){
        
             dst[i] = (src[i] + 3)%255;

    }
        dst[len]= '\0';

    return 1;
}

int decode(char *src, char *dst, int len){
    
    for(int i = 0; i < len; i++){



        dst[i] = (char)(src[i] - 3)%255;

    }
    dst[len]= '\0';

    return 1;
}
