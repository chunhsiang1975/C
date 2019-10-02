/*
 *	Use fifo function to copy file
 *	Written by Chun-Hsiang Chao
 *	Date:20191002
 */ 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char *argv[]){
	char *input_file;
	char *output_file;
	input_file=argv[1];
	output_file=argv[2];
	//printf("%s %s\n",input_file,output_file);
	FILE *fin,*fout;
	char c;
	int state=0;
	if(strcmp(output_file,"tmp")==0) state=1;
	else state=0;
	if(state==1){
		fin=fopen(input_file,"r");
		if(mkfifo("/tmp/fifo",066)!=0) perror("mkfifo()");
		if( (fout=fopen("/tmp/fifo", "w")) == NULL ){
	        	perror("fopen()");
	        	exit(0);
		}
		while(fscanf(fin,"%c",&c)!=EOF){
			fprintf(fout,"%c",c);
		}
		fclose(fin);
		fclose(fout);
	}
	else{
		fout=fopen(output_file,"w");
		if(mkfifo("/tmp/fifo",066)!=0) perror("mkfifo()");
	
		if( (fin=fopen("/tmp/fifo", "r")) == NULL ){
	        	perror("fopen()");
	        	exit(0);
		}
		while(fscanf(fin,"%c",&c)!=EOF){
			fprintf(fout,"%c",c);
		}
		fclose(fin);
		fclose(fout);
	}
    exit(0);
}

