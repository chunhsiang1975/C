/*
 *	IT Training example.
 *	Date:20191002
*/
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	int value;
	FILE *pf;
	//echo 23 > /sys/class/gpio/export
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"23");
	fclose(pf);
	//echo in > /sys/class/gpio/gpio23/direction
	pf=fopen("/sys/class/gpio/gpio23/direction","w");
	fprintf(pf,"in");
	fclose(pf);

	while(1){
		usleep(10000);//1000000 equal 1 second
		pf=fopen("/sys/class/gpio/gpio23/value","r");
		fscanf(pf,"%d",&value);
		fclose(pf);
		if(value==0) printf("%d\n",value);
	}
	return 0;
}
