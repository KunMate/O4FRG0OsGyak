#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
	pid_t cpid;
	int ret;
	int fd;
	char buffer[32];
	char file[] = "o4frg0";
	ret = mkfifo(file, 0666);
	if(ret == -1)
	{
		perror("mkfifo()");
		exit(-1);
	}
	cpid = fork();
	if(cpid == -1)
	{
		perror("fork()");
		exit(-2);
	}
	if(cpid == 0)
	{
		printf("%d: gyerek\n", getpid());
		fd = open(file, O_WRONLY);
		if(fd == -1)
		{
			perror("open()");
			exit(-3);
		}
		strcpy(buffer, "Kun Mate o4frg0");
		write(fd, buffer, strlen(buffer));
		printf("%d: gyerek - iras utan\n", getpid());
		close(fd);
	}
	else
	{
		printf("%d: szulo\n", getpid());
		fd = open(file, O_RDONLY);
		if(fd == -1)
		{
			perror("open()");
			exit(-4);
		}
		printf("%d: szulo - olvasas elott\n", getpid());
		ret = read(fd, &buffer, sizeof(buffer));
		printf("read(): %d byteot olvasott, string: %s\n", ret, buffer);
		close(fd);
		unlink(file);
	}
	return 0;
}
