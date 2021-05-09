#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semFajl;

int main(){
	sem_init(&semFajl, 1, 0);
	int a;
	sem_getvalue(&semFajl, &a);
	printf("szemafor ertek: %d\n", a);
	FILE* f = fopen("file.txt", "w");
	printf("fajl irasa\n");
	fprintf(f, "Kun Mate\nO4FRG0");
	sleep(5);
	printf("Fajl iras sikeres\n");
	fclose(f);
	sem_post(&semFajl);
	sem_getvalue(&semFajl, &a);
	printf("szemafor ertek: %d\n", a);
	//sem_destroy(&semFajl);
	return 0;
}
