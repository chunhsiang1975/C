/*
Use function and array to show Traffic Light red yellow green 
20190828
Writed by Chun-Hsiang Chao
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void light(char *color, int delay_time);
int main(void){
	int red_delay_time=10;
	int green_delay_time=10;
	int yellow_delay_time=2;
	int i=0;
	int state=0;
	char color[3][7]={"red","green","yellow"};
	while(1){
		light(color[0],red_delay_time);
		light(color[1],green_delay_time);
		light(color[2],yellow_delay_time);
	}
	return 0;
}
void light(char *color, int delay_time){
	char *light_name[3];
	char *temp;
#if 1
	temp=(char *)malloc(sizeof(char)*7);
	sprintf(temp,"red");
	light_name[0]=temp;
	temp=(char *)malloc(sizeof(char)*7);
	sprintf(temp,"green");
	light_name[1]=temp;
	temp=(char *)malloc(sizeof(char)*7);
	sprintf(temp,"yellow");
	light_name[2]=temp;	
#else
	char red_string[7]="red"; 
	char green_string[7]="green";
	char yellow_string[7]="yellow";
	light_name[0]=red_string;
	light_name[1]=green_string;
	light_name[2]=yellow_string;
#endif
	int i,j;
	for(i=0;i<3;i++){
		if(strcmp(color,light_name[i])==0){
			while(1){
				printf("%s %d\n",light_name[i],delay_time);
				delay_time--;
				sleep(1);
				if(delay_time==0) break;
			}
		}
	}
}

