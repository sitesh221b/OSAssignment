#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){   //To give the filename for input and output while compiling
    int pipefd[2];
    int fd;
    pid_t p;
    char parentBuff[100], childBuff[100];
    int readLength;
    
    pipe(pipefd);
    
    p = fork();
    
    char *sourceFileName = argv[1];
    char *destinationFileName = argv[2];
    
    if(p < 0){
        printf("\nError creating the child process!");
    }
    else if(p > 0){
    
        printf("This is Parent Process - Reading from source file and writing to one end of pipe\n");
        
        close(pipefd[0]);   //Closing reading end
        fd = open(sourceFileName, O_RDONLY, 0777);
        readLength = read(fd, parentBuff, 100);
        write(pipefd[1], parentBuff, readLength);
        close(pipefd[1]);
    }
    else if(p == 0){
    
        printf("This is Child Process - Reading from pipe and writing to destination file\n");
        
        //Reading the source file
        close(pipefd[1]);   //Closing the writing end
        readLength = read(pipefd[0], childBuff, 100);
        close(pipefd[0]);
        
        //Writing in destination file
        fd = open(destinationFileName, O_CREAT | O_WRONLY, 0777);
        write(fd, childBuff, readLength);
    }
    return 0;
}
