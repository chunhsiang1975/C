/*
Traffic Light red yellow green
20190822
Written by Chun-Hsiang Chao
*/
#include <stdio.h>
#include <unistd.h>
int main(void){
	int red_delay_time=10;
	int green_delay_time=10;
	int yellow_delay_time=2;
	int i=0;
	int state=0;
	while(1){
		if((state==0)&&(i<red_delay_time)){
			printf("red %d\n",red_delay_time-i);
			i++;
			if(i==red_delay_time){ state++;i=0;}
			sleep(1);
		}
		else if((state==1)&&(i<green_delay_time)){
			printf("green %d\n",green_delay_time-i);
			i++;
			if(i==green_delay_time){ state++;i=0;}
			sleep(1);
		}
		else if((state==2)&&(i<yellow_delay_time)){
			printf("yellow %d\n",yellow_delay_time-i);
			i++;
			if(i==yellow_delay_time){ state=0;i=0;}
			sleep(1);
		}		
	}
}

