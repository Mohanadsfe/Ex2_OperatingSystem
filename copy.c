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
int f_copy(char* argv[]);
int v_copy(char* argv[]);
int check_input(char *argv[],int argc);



int main(int argc, char *argv[]){

    //Check if we get a illegal input 
    if(argc <3 || argc>5){
        printf("Usage:./copy<file1><file2>\n");
        printf("Usage:./copy<file1><file2> -v\n");
        printf("Usage:./copy<file1><file2> -f\n");
        printf("Usage:./copy<file1><file2> -f -v\n");
        printf("Usage:./copy<file1><file2> -v -f\n");

        return 1;
    }

    int res = -1;

if(check_input(argv,argc)){
    // if we get 3 values, Without "-v , -f " at the end.
    if(argc == 3) {

             res =   regular_copy(argv);
                printf("%d \n",res);
                return res;
            }


    // if we get 4 index in the input , with "-v or -f"
     if(argc==4) {
        
       
        if(strcmp(argv[3] ,"-v")==0){

            int res = v_copy(argv);
            if(res==0){
            printf("success\n");
            printf("%d",res);
            }else{
            printf("failure\n");
            }

        }
            
        if(strcmp(argv[3] ,"-f")==0){ // if we get a regular file but the input was with -v


            res =  f_copy(argv);
                printf("%d",res);

                        }

        


            }
    
    if(argc==5){


        if(strcmp(argv[3] ,"-f")==0 || strcmp(argv[4] ,"-f")==0){

            res = f_copy(argv);
            printf("%d",res);
            printf("\n\n");

        }


    }
        

             }

                else{
                    printf("Error , you used name flags that not exits!' try again please by this below options:- \n");
                    printf("Usage:./cmp<file1><file2>\n");
                    printf("Usage:./cmp<file1><file2> -v\n");
                    printf("Usage:./cmp<file1><file2> -f\n");
                    printf("Usage:./copy<file1><file2> -f -v\n");
                    printf("Usage:./copy<file1><file2> -v -f\n");

                }

            printf("\n");

    return 0;

}


int regular_copy(char *argv[]){

    int filed1 = open(argv[1], O_RDWR); // open the file from the input (file1)

       

        int filed2 = open(argv[2], O_CREAT | O_RDWR | O_EXCL); //Create the new file (file2)

           

             if(filed1 == -1 || filed2==-1){
            perror("can't open file1");
        }
            printf("\n");

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
        printf("\n target file exits\n");
            perror("can't open file");
            exit(-1);
            
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



int f_copy(char* argv[]){


        int filed1 = open(argv[1], O_RDWR); // open the file from the input (file1)


        int filed2 = open(argv[2],O_CREAT | O_RDWR | O_APPEND);


             if(filed1 == -1 || filed2==-1){
            perror("can't open file1");
        }

        

        if (filed1 > 0) {

                       FD_SIZE = read(filed1, buffer, sizeof(buffer));

                       int number_written = write(filed2, buffer, FD_SIZE);

                       if(number_written!=FD_SIZE){

                            printf("failure\n");

                       }else{
                          printf("success\n"); 
                        return 0;
                       }

                            }
            printf("\n");

                  close(filed1);

                 close(filed2);

return 1;
}


int check_input(char *argv[],int argc){

    if(argc==3){
        return 1;
    }

    if(argc==4){
        if(strcmp(argv[3],"-v")!=0 || strcmp(argv[3],"-f")!=0)
        return 1;
        
    }

    if(argc==5){
        if((strcmp(argv[3],"-v")!=0 && strcmp(argv[4],"-f")!=0)||(strcmp(argv[3],"-f")!=0 && strcmp(argv[4],"-v")!=0))
        return 1;
    }

    return 0;

}

// int check_input(char *argv[],int argc){


//     if(argc==4){
//         if(strcmp(argv[3],"-v")!=0 && strcmp(argv[3],"-f")!=0)
//         return 0;
        
//     }

//     if(argc==5){
//         if((strcmp(argv[3],"-v")!=0 || strcmp(argv[4],"-f")!=0)&&(strcmp(argv[3],"-f")!=0 || strcmp(argv[4],"-v")!=0))
//         return 0;
//     }

//     return 1;

// }





