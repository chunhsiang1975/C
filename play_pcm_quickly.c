/*
	Play mp3 pcm music file quickly
	Author:Chun-Hsiang Chao
	Date:20191005
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int speed=2;
	int i=0;
	FILE *in,*out;
	in=fopen(argv[1],"rb");
	out=fopen("/dev/dsp","wb");
	char c;
	if(argv[2]!=NULL){
		speed=atoi(argv[2]);
	}
	i=speed;
	while(fscanf(in,"%c",&c)!=EOF){
		if(i<speed){
			i++;
			continue;
		}
		fprintf(out,"%c",c);
		i=0;
	}
	fclose(in);
	fclose(out);
	return 0;
}
