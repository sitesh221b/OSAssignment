# OSAssignment

## Efforts by
* Name: Sitesh Roy
* ID: 11709052
* Email Address: siteshroy786@gmail.com
* GitHub Link: www.github.com/sitesh221b/OSAssignment


## Question 1

The given question:
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the user. For example, if 8 is passed as a parameter on the command line, the child process will output:
```
8 4 2 1
```
Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.


## Question 2

Design a file-copying program named filecopy using ordinary pipes. This program will be passed two parameters: the name of the file to be copied and the name of the copied file. The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The child process will read this file from the pipe and write it to the destination file. For example, if we invoke the program as follows:
```
filecopy input.txt copy.txt
```
The file input.txt will be written to the pipe. The child process will read the contents of this file and write it to the destination file copy.txt.

