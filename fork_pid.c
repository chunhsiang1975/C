/*
	Written by Chun-Hsiang Chao
	Date:20191002
*/


#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
	int n=atoi(argv[1]);
	n=(int)sqrt(n);
	int i;
    	pid_t pid;
    	pid_t ppid;
	char message[100];
	for(i=0;i<n;i++){
		pid=fork();
		switch(pid){
		    case -1:
		        perror("fork failed");
		        exit(1);
		    case 0:
		        sprintf(message, "This is the child %d %d", getpid(),getppid());
		        break;
		    default:
		        sprintf(message, "This is the parent %d %d", getpid(),getppid());
		        break;
	    }
	}
	printf("process %s\n",message);
	return 0;
}
