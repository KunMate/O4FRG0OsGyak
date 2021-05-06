#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 123456L

int main(){
	int shmid;
	key_t key = KEY;
	int size = 512;
	int shmflg;
	int rtn;
	int cmd;
	struct shmid_ds shmid_ds, *buf;
	buf = &shmid_ds;
	shmflg = 0;
	if((shmid=shmget(key, size, shmflg)) < 0) 
	{
		perror("shmget error\n");
		exit(-1);
	}
	do{
	printf("Adja meg a parancs szamot: \n0 IPC_STAT \n1 IPC_RMID\n");
	scanf("%d", &cmd);
	}while(cmd<0 && cmd > 1);
	switch(cmd){
	case 0: 
		rtn = shmctl(shmid, IPC_STAT, buf);
		printf("szegmens meret: %d\n", buf->shm_segsz);
		printf("utolso shmop processz id: %d\n", buf->shm_lpid);
		break;
	case 1:
		rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("szegmens torolve\n");
	}
	return 0;
}
