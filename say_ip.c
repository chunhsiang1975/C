/*
 *	Say ip
 *	Written by Chun-Hsiang Chao
 *	Date:20191002
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void say_char(char c){
	FILE *in,*out;
	char filename[100];
	if(c=='.'){
		sprintf(filename,"/home/pi/Music/voice/dot.pcm",c);
	}
	else{
		sprintf(filename,"/home/pi/Music/voice/%c.pcm",c);
	}
	in=fopen(filename,"rb");
	out=fopen("/dev/dsp","wb");
	while(fscanf(in,"%c",&c)!=EOF){
		fprintf(out,"%c",c);
	}
	fclose(in);
	sleep(1);
	fclose(out);
}


int main(int argc, char *argv[ ]){
	FILE *read_fp;
	char buffer[1000];
	int chars_read;
	char pattern[]="inet";
	char *point;
	char ip[20];
	int i=5;
	int j=0;
	read_fp = popen("ifconfig wlan0", "r");
	if (read_fp != NULL) {
        chars_read = fread(buffer, sizeof(char), sizeof(buffer)-1, read_fp);
        if (chars_read > 0) {
            buffer[chars_read] = '\0';
            //printf("Output was:-\n%s\n", buffer);
	    point=strstr(buffer,pattern);
	    if(point!=NULL){
		    //printf("%s\n",point);
			while(1){
				if(point[i]!=' '){
					ip[j]=point[i];
					i++;
					j++;
				}
				else{
					ip[j]='\0';
				      	break;
				}
			}
		}
        }
        pclose(read_fp);

	for(i=0;i<strlen(ip);i++){
		say_char(ip[i]);	
	}	

	printf("%s\n",ip);
    }
    exit(0);
}

