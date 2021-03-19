
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	char input[20];
	printf("Command: ");
	scanf("%s", input);
	int status = system(input);
	if(WIFEXITED(status))
		printf("Output: %d\n", WEXITSTATUS(status));
	else
		printf("Error\n");
	return 0;
}
