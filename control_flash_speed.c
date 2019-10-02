/*
 *	IT Training example.
 *	Written by Chun-Hsiang Chao
 *	Date:20191002
*/
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	int sleep_speed=100000;
	int increase_decrease_unit=5000;
	int value23;
	int value24;
	FILE *pf;
	//system("echo 22 > /sys/class/gpio/export");
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"22");
	fclose(pf);
	//system("echo out > /sys/class/gpio/gpio22/direction");
	pf=fopen("/sys/class/gpio/gpio22/direction","w");
	fprintf(pf,"out");
	fclose(pf);
	//system("echo 1 > /sys/class/gpio/gpio22/value");
	pf=fopen("/sys/class/gpio/gpio22/value","w");
	fprintf(pf,"1");
	fclose(pf);

	//echo 23 > /sys/class/gpio/export
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"23");
	fclose(pf);
	//echo in > /sys/class/gpio/gpio23/direction
	pf=fopen("/sys/class/gpio/gpio23/direction","w");
	fprintf(pf,"in");
	fclose(pf);

	//echo 24 > /sys/class/gpio/export
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"24");
	fclose(pf);
	//echo in > /sys/class/gpio/gpio23/direction
	pf=fopen("/sys/class/gpio/gpio24/direction","w");
	fprintf(pf,"in");
	fclose(pf);

	//system("echo 6 > /sys/class/gpio/export");
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"6");
	fclose(pf);

	//system("echo out > /sys/class/gpio/gpio6/direction");
	pf=fopen("/sys/class/gpio/gpio6/direction","w");
	fprintf(pf,"out");
	fclose(pf);

	while(1){
		pf=fopen("/sys/class/gpio/gpio23/value","r");
		fscanf(pf,"%d",&value23);
		fclose(pf);
		pf=fopen("/sys/class/gpio/gpio24/value","r");
		fscanf(pf,"%d",&value24);
		fclose(pf);
			//system("echo 1 > /sys/class/gpio/gpio6/value");
			pf=fopen("/sys/class/gpio/gpio6/value","w");
			fprintf(pf,"1");
			fclose(pf);
		usleep(sleep_speed);//1000000 equal 1 second
			//system("echo 1 > /sys/class/gpio/gpio6/value");
			pf=fopen("/sys/class/gpio/gpio6/value","w");
			fprintf(pf,"0");
			fclose(pf);
		usleep(sleep_speed);//1000000 equal 1 second
		if(value23==0){
		       	//printf("%d\n",value23);
			sleep_speed=sleep_speed+increase_decrease_unit;
		       	printf("%d\n",sleep_speed);
		}
		if(value24==0){
		       	//printf("%d\n",value24);
			sleep_speed=sleep_speed-increase_decrease_unit;
		       	printf("%d\n",sleep_speed);
		}
	}
	return 0;
}
