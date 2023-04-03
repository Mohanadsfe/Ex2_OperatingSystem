#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define SIZE_BUFFER 1024 
 int FD_SIZE=-1;
 char buffer[SIZE_BUFFER];

int regular_copy(char *argv[]);
void f_copy(char* argv[]);
int v_copy(char* argv[]);



int main(int argc, char *argv[]){

    //Check if we get a illegal input 
    if(argc != 3 && argc != 4){
        printf("Usage:./copy<file1><file2>\n");
        printf("Usage:./copy<file1><file2> -v\n");
        printf("Usage:./copy<file1><file2> -i\n");

        return 1;
    }

    int res = -1;


    // if we get 3 values, Without "-v , -f " at the end.
    if(argc == 3) {

             res =   regular_copy(argv);
                printf("%d \n",res);
                return res;
            }


    // if we get 4 index in the input , with "-v or -f"
    else if(argc==4) {
        
       
        if(strcmp(argv[3] ,"-v")==0){

            v_copy(argv);

        }
            
        if(strcmp(argv[3] ,"-f")==0){ // if we get a regular file but the input was with -v


             f_copy(argv);
                
                        
                        }


            }


    return 0;

}


int regular_copy(char *argv[]){

    int filed1 = open(argv[1], O_RDWR); // open the file from the input (file1)

       

        int filed2 = open(argv[2], O_CREAT | O_RDWR | O_EXCL); //Create the new file (file2)

           

             if(filed1 == -1 || filed2==-1){
            perror("can't open file1");
        }

            //if we successes open the file
            if (filed1 > 0) {
                        FD_SIZE = read(filed1, buffer, sizeof(buffer));
                        write(filed2, buffer, FD_SIZE);
                        close(filed1);
                        }
                        close(filed2);
                        return 0; // success copy

}


int v_copy(char* argv[]){


    int filed1 = open(argv[1], O_RDWR); // open the file from the input (file1)

        

    int filed2 = open(argv[2], O_CREAT | O_RDWR | O_EXCL); //Create the new file (file2)

            
            
       if(filed1 == -1 || filed2==-1){
            perror("can't open file1");
                                           }


            //if we successes open the file
            if (filed1 > 0) {
                        FD_SIZE = read(filed1, buffer, sizeof(buffer));
                        write(filed2, buffer, FD_SIZE);
                        close(filed1);
                        }
                        close(filed2);
                        return 0; // success copy
    

}



void f_copy(char* argv[]){


        int filed1 = open(argv[1], O_RDWR); // open the file from the input (file1)


        int filed2 = open(argv[2],O_CREAT | O_RDWR | O_APPEND);


             if(filed1 == -1 || filed2==-1){
            perror("can't open file1");
        }

        

        if (filed1 > 0) {

                       FD_SIZE = read(filed1, buffer, sizeof(buffer));
                       printf("%d", FD_SIZE);

                       int number_written = write(filed2, buffer, FD_SIZE);

                       if(number_written!=FD_SIZE){

                            printf("failure");

                       }else{
                            printf("%d",number_written);
                          printf("success"); 

                       }

                            }

                  close(filed1);

                 close(filed2);


}
