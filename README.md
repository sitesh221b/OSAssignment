# OSAssignment

## Efforts by
* Name: Sitesh Roy
* ID: 11709052
* Email Address: siteshroy786@gmail.com
* GitHub Link: www.github.com/sitesh221b/OSAssignment


## Description

The given question:
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the user. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.

So, the above problem states that we have to write a program in C language using fork() system call and child process.
Given example of I/O:
Input: 8
Ouput: 8, 4, 2, 1

According to the question we have to print sequence of numbers depending upon the input.
And also check for valid input and in this case i.e. the entered number should be positive.
If the child process has to execute this then we will use wait() function to make the parent process wait untill the child process is executed

```
#include<stdio.h>
#include<unistd.h>
#include<std/types.h>

int main(){
	pid_t n = fork();
  	int num;
   	if(n < 0)
		printf("Error Creating Child Process!\n");
  	else if(n == 0){
		printf("This is Child Process, ID: %d, Parent's ID: %d\n", getpid(),getppid());
		printf("Enter the number: ");
  		scanf("%d", &num);
		printf("%d ",num);
		while(num/2){
			printf("%d ",num/2);
			num /= 2;
		}
		printf("Sequence Completed!\n");
	}
	else{
		wait(NULL);
		printf("This is Parent Process, ID: %d, Parent's ID: %d\n", getpid(), getppid());
	}
  }
  return 0;
}
```
