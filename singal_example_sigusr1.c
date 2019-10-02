/*	IT Training example
 *	Written by Chun-Hsiang Chao
 *	Date:20191002
 */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int dbg=0;
void ouch(int sig){
	if(dbg==0) dbg=1;
	else dbg=0;
}
int main(int argc, char *argv[]){
    signal(SIGUSR1, ouch);
    while(1){
	    if(dbg==1){
        	printf("Hello World!\n");
        	sleep(1);
	    }	
    }
	exit(0);
}

