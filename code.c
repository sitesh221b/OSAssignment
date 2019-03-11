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