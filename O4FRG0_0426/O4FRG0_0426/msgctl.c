#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#define KEY 654321L

int main(){
	int msgid, msgflg, rtn;
	key_t key;
	key = KEY;
	msgflg = 00666 | IPC_CREAT;
	msgid = msgget(key, msgflg);
	rtn = msgctl(msgid, IPC_RMID, NULL);
	printf("Return: %d\n", rtn);
	return 0;
}

