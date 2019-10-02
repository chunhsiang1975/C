/*
 *	IT Training example.
 *	Date:20191002
 */
#include<stdio.h>
int main(int argc, char *argv[]){
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

	//system("echo 6 > /sys/class/gpio/export");
	pf=fopen("/sys/class/gpio/export","w");
	fprintf(pf,"6");
	fclose(pf);

	//system("echo out > /sys/class/gpio/gpio6/direction");
	pf=fopen("/sys/class/gpio/gpio6/direction","w");
	fprintf(pf,"out");
	fclose(pf);

	//system("echo 1 > /sys/class/gpio/gpio6/value");
	pf=fopen("/sys/class/gpio/gpio6/value","w");
	fprintf(pf,"1");
	fclose(pf);

	return 0;
}
