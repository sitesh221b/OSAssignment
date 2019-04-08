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
		check:
		printf("Enter a positive number: ");
  		scanf("%d", &num);
		if(num < 0){
			printf("Incorrect Value Entered!");
			goto check;
		}
		else{
			while(num){
				printf("%d ",num);
				num /= 2;
			}	
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
