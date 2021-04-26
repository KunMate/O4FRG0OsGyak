#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY 654321L

struct msgbuf1{
	long mtype;
	char mtext[512];
} sndbuf, *msgp;

int main(){
	int msgid;
	key_t key;
	int msgflg;
	int rtn, msgsz;
	key = KEY;
	msgflg = 00666 | IPC_CREAT;
	msgid = msgget(key, msgflg);
	if(msgid == -1)
	{
		perror("msgget error\n");
		exit(-1);
	}
	printf("\n msgid %d, %x :", msgid, msgid);
	msgp = &sndbuf;
	msgp ->mtype = 1;
	strcpy(msgp->mtext, "Elso uzenet");
	msgsz = strlen(msgp->mtext) + 1;
	rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
	printf("1. msgsnd return: %d\n", rtn);
	printf("kuldott uzenet: %s\n", msgp->mtext);

	strcpy(msgp->mtext,"Masodik uzenet");
	msgsz = strlen(msgp->mtext)+1;
	rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
	printf("2. msgsnd return: %d\n", rtn);
	printf("kuldott uzenet: %s\n", msgp->mtext);
	return 0; 
}
