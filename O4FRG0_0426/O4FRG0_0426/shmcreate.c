#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 123456L

int main(){
	int shmid;
	key_t key = KEY;
	int size=512;
	int shmflg;
	shmflg = 0;
	if((shmid=shmget(key, size, shmflg)) < 0)
	{
		printf("shm keszitese\n");
		shmflg = 00666 | IPC_CREAT;
		if((shmid=shmget(key, size, shmflg)) < 0)
		{
			perror("shmget sikertelen\n");
			exit(-1);
		}
	}
	else printf("shm létezik\n");
	printf("shmid: %d\n", shmid);
	return 0; 
}

