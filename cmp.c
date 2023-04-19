#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int regular_cmp(char* argv[]);
// A function to compare between 2 files
int cmp(char* argv[], FILE *file1, FILE *file2,int argc);
int v_cmp(char* argv[],int argc);
int i_cmp(char* argv[],int argc);
int cmp2(FILE *file1,FILE *file2);
int check_input(char *argv[],int argc);


int main(int argc, char *argv[]){

    //Check if we get a illegal input 
    if(argc < 3|| argc>5){

        printf("Usage:./cmp<file1><file2>\n");
        printf("Usage:./cmp<file1><file2> -v\n");
        printf("Usage:./cmp<file1><file2> -i\n");
        printf("Usage:./cmp<file1><file2> -i -v\n");
        printf("Usage:./cmp<file1><file2> -v -i\n");
        return 1;
    }

    if(check_input(argv,argc)){
    if(argc==3){
            int res = regular_cmp(argv);
            printf("%d\n",res);
    }
     if(argc==4){

        if(strcmp(argv[3],"-v")==0){
            int res = v_cmp(argv,argc);
            printf("%d\n",res);
        }

         if(strcmp(argv[3],"-i")==0){
        int res = i_cmp(argv,argc);
        printf("%d\n",res);
         }
     }
   
    if(argc==5){

    if(strcmp(argv[3],"-i")==0 || strcmp(argv[4],"-i")==0){
            printf("hiii biii");
            int res = i_cmp(argv,argc);
            printf("%d\n",res);
        }

        }
    }

    else{
        printf("Error , you used name flags that not exits!' try again please by this below options:- \n");
        printf("2Usage:./cmp<file1><file2>\n");
        printf("Usage:./cmp<file1><file2> -v\n");
        printf("Usage:./cmp<file1><file2> -i\n");
        printf("Usage:./cmp<file1><file2> -i -v\n");
        printf("Usage:./cmp<file1><file2> -v -i\n");

    }
    return 0;
}


int regular_cmp(char* argv[]){

    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

 // opening two files in order to compare between them , in mode r = read.
    FILE * file1 = fopen(argv[1],"r");
    FILE * file2 = fopen(argv[2],"r");


    // One of files or more does not success to opne.
    if(file1 == NULL || file2 == NULL){
        printf("heloooo\n");
        perror("Open files\n");
        return 0;
    }

   
    // Send the files as parameters to function cmp ,to compare...

    // if the files are equals then print "equal".
    if(!cmp2(file1, file2)){
        
      return 0;

    }else{
        return 1;
    }

    // if the function will return 0 - the files are equals, and we will print it to the terminal.
 
    fclose(file1);
    fclose(file2);


}

int v_cmp(char* argv[],int argc){



 // opening two files in order to compare between them , in mode r = read.
    FILE * file1 = fopen(argv[1],"r+");
    FILE * file2 = fopen(argv[2],"r+");


    // One of files or more does not success to opne.
    if(file1 == NULL || file2 == NULL){

        perror("Open files\n");
        return 0;
    }

   
    // Send the files as parameters to function cmp ,to compare...

    // if the files are equals then print "equal".
    if(!cmp(argv,file1, file2,argc)){
        printf("equal\n");
      return 0;

    }else{
        printf("distinct\n");
        return 1;
    }

    // if the function will return 0 - the files are equals, and we will print it to the terminal.
 
    fclose(file1);
    fclose(file2);


}

int i_cmp(char* argv[],int argc){



 // opening two files in order to compare between them , in mode r = read.
    FILE * file1 = fopen(argv[1],"r+");
    FILE * file2 = fopen(argv[2],"r+");


    // One of files or more does not success to opne.
    if(file1 == NULL || file2 == NULL){

        perror("Open files\n");
        return 0;
    }

   
    // Send the files as parameters to function cmp ,to compare...

    // if the files are equals then print "equal".
    if(!cmp(argv,file1, file2,argc)){

        printf("equal\n");

      return 0;

    }else{

        printf("distinct\n");

        return 1;

    }

    // if the function will return 0 - the files are equals, and we will print it to the terminal.
 
    fclose(file1);
    fclose(file2);


}

int cmp2(FILE *file1,FILE *file2){



    char ch1, ch2;
    int EOF1, EOF2;
    int flag =1;

    // while both of the files are not empty and not get to the final of the files!

    while (EOF1 != EOF && EOF2 != EOF&&flag){
        EOF1 = fscanf(file1 ,"%c", &ch1);
        EOF2 = fscanf(file2 ,"%c", &ch2);
        if (ch1 != ch2){
            flag = 0; // No reason to continue if get the fist chars are diff.
            return 1; // the files are diff.
        }
    }

    if (EOF1 != EOF || EOF2 != EOF){ // In this case, the files are equal to a index , then one of them get the end, another not, that means are diff.
        return 1;
    }

    return 0;

}

int cmp(char* argv[], FILE *file1, FILE *file2, int argc){

    char ch1, ch2;
    int EOF1, EOF2;
    int flag =1;

    // while both of the files are not empty and not get to the final of the files!

    if((argc==4) && strcmp(argv[3],"-v")==0){

    while (EOF1 != EOF && EOF2 != EOF&&flag){
        EOF1 = fscanf(file1 ,"%c", &ch1);
        EOF2 = fscanf(file2 ,"%c", &ch2);
        if (ch1 != ch2){
            flag = 0; // No reason to continue if get the fist chars are diff.
            return 1; // the files are diff.
        }
    }

    if (EOF1 != EOF || EOF2 != EOF){ // In this case, the files are equal to a index , then one of them get the end, another not, that means are diff.
        return 1;
    }

    }


    else{

     while (EOF1 != EOF && EOF2 != EOF&&flag){

        EOF1 = fscanf(file1 ,"%c", &ch1);
        EOF2 = fscanf(file2 ,"%c", &ch2);
        
        if(abs(ch1-ch2) != 32){

            if (ch1 != ch2){
                flag = 0; // No reason to continue if get the fist chars are diff.
                return 1; // the files are diff.
            }

        }

    }

    if (EOF1 != EOF || EOF2 != EOF){ // In this case, the files are equal to a index , then one of them get the end, another not, that means are diff.
        return 1;
      }


             }

    return 0; // equal files.
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
