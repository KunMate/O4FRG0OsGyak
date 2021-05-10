#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semFajl;

int main(){
	sem_init(&semFajl, 1, 1);
	char data[20][20];
	int v = 0;
	char ch;
	int a;
	sem_getvalue(&semFajl, &a);
	while(a == 0){
	printf("sem val: %d\n", a);  
	printf("varakozas fajl irasra\n");
	sem_getvalue(&semFajl, &a);
	sleep(5);
}
	printf("sem val: %d\n", a);
	sem_wait(&semFajl);
	printf("Fajl olvasas\n");
	FILE* f = fopen("file.txt", "r");
	while((ch=fgetc(f)) != EOF)
	{
		fscanf(f, "%s", data[v]);
		v++;
	}
	sleep(1);
	sem_post(&semFajl);
	//sem_destroy(&semFajl);
	printf("fajl olvasas sikeres\n");
	fclose(f);
	return 0;
}
