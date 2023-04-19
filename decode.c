#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "ctype.h"

int main(int argc, char *argv[]){

    // if the input is illegal
    if(argc < 3){
        printf("Usage: decode <codec> <message>\n");
        exit(1);
    }


    void *handle; //pointer to a function from one library.
    double (*decode)(char*, char*, int);

    //try openning the dynamic libraries
    if (strcmp(argv[1], "codecA") == 0) { 
        handle = dlopen("./codecA.so", RTLD_LAZY);
    }
    else if (strcmp(argv[1], "codecB") == 0) { 
        handle = dlopen("./codecB.so", RTLD_LAZY);
    }
    else { 
        printf("Error: unknown library with name : %s\n", argv[1]);
        exit(1);
    }


    if (!handle) {
       
        printf("Error: fail to load the library %s\n", dlerror());
        exit(1);
    }


    *(void**)(&decode) = dlsym(handle, "decode");
    if (!decode) {
        fprintf(stderr, "Error: the function wasn't found %s\n", dlerror());
        dlclose(handle);
        exit(1);
    }

    int len = strlen(argv[2]);
    printf("%d\n",len);
    char *dst = (char*) malloc(sizeof(char) * (len+1)); 

    decode(argv[2], dst, len); 
    printf("%s\n", dst); 
    free(dst);


    dlclose(handle);
    return 0;
}