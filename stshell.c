#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 1024 // The maximum length command

int should_run = 1;  // flag to determine when to exit program
int should_wait = 1; // flag to determine if process should run in the background



void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n Ignored :))))\n");

  if (signo == SIGUSR1)
    printf("received SIGUSR1\n doing user stuff\n");
}

// // Redirects stdout to a file. (Not append, if duplicate the operation will remove the data and then will save new data in the file).
void redirectOut(char *fileName)
{
         int out = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0600);

    dup2(out, 1); // this function will help us, to change the place of the print, from stdout=1 to out ,
                //that's mean in the table of file descriptors the file will be in the place of stdoud=1.
    close(out);
}

// Redirects stdout to a file. append to a file.(to end of the exits file).
void redirectOut2(char *fileName)
{
        int out = open(fileName,  O_WRONLY | O_APPEND);

    dup2(out, 1); 
    close(out);
}

void redirectIn(char *fileName)
{
    int in = open(fileName, O_RDONLY);
    dup2(in, 0); 
    close(in);
}

void run(char *args[])
{
    
    pid_t pid;
    if (strcmp(args[0], "exit") != 0) // check if the commad is exit, then stop the programmer.
        {
            
            pid = fork();
            if (pid < 0) { 
                fprintf(stderr, "Fork Failed");
            }
            else if ( pid == 0) { /* child process , each one will get a work to do...*/ 
                execvp(args[0], args);
            }
            else { /* parent process */
                if (should_wait) {
                    
                    waitpid(pid, NULL, 0);
                } else {
                    should_wait = 0;
                }
            }
            redirectIn("/dev/tty"); // for pipe...
            redirectOut("/dev/tty");

        }
    else {
        
        should_run = 0;
    }
}

void createPipe(char *args[])
{

    int fd[2];
    pipe(fd);

    dup2(fd[1], 1);

    close(fd[1]);


    run(args);

    dup2(fd[0], 0);

    close(fd[0]);

}


int main(void)
{
    char *args[MAX_LINE]; // command line arguments
    
    while (should_run) {
        printf("M&S_Students_Shell$ ");
        fflush(stdout);

        if (signal(SIGINT, sig_handler) == SIG_ERR)
				printf("\ncan't catch SIGINT\n");

        char input[MAX_LINE];
        fgets(input, MAX_LINE, stdin);
        int counter=0;
        int i = 0;
       while (input[i]!='\0')
       {
           counter++; 
           i++;
       }
       
        
        input[counter-1]='\0';
        
        char delim[] = " ";

        char *arg = strtok(input, delim);
      
        
         i = 0;
        while (arg) {

            if (*arg == '>' && *(arg+1) == '>') { // check if there >> in the command line
                
                redirectOut2(strtok(NULL, " "));
            }
            if (*arg == '>') { // check if there > in the command line
                redirectOut(strtok(NULL, " "));
            }
             else if (*arg == '|') { // check if there | in the command line
                args[i] = NULL;
                createPipe(args);
                i = 0;
            } else {
                args[i] = arg;
                i++;
            }
            arg = strtok(NULL, " ");
        }
        args[i] = NULL;
        
        run(args);
    }
    return 0;
}


