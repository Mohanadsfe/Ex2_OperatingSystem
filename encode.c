#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "ctype.h"

int main(int argc, char *argv[]){

    // if the input is illegal
    if(argc < 3){
        printf("Usage: encode <codec> <message>\n");
        exit(1);
    }

    void *handle; //pointer to the function, we don't know the type yet
    double (*encode)(char*, char*, int);

    //opening the dynamic libraries
    if (strcmp(argv[1], "codecA") == 0) { // codec1 case
        handle = dlopen("./codecA.so", RTLD_LAZY);
    }
    else if (strcmp(argv[1], "codecB") == 0) { // codec2 case
        handle = dlopen("./codecB.so", RTLD_LAZY);
    }
    else { // error case, none of the above
        printf("Error: unknown library: %s\n", argv[1]);
        exit(1);
    }


    if (!handle) {
        /* fail to load the library */
        printf("Error: %s\n", dlerror());
        exit(1);
    }
    *(void**)(&encode) = dlsym(handle, "encode");
    //if the function wasn't found
    if (!encode) {
        /* no such symbol */
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        exit(1);
    }
    int len = (int)strlen(argv[2]);
    printf("%d\n",len);
    printf("%s\n", argv[2]); // printing the answer


    char *dst = (char*) malloc(sizeof(char) * len); // pointer to the string
   
    encode(argv[2], dst, len); 
        dst[len]='\0';

    printf("%s\n", dst); // printing the answer
    free(dst);

    dlclose(handle);
    return 0;
}