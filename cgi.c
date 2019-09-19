/*
Use CGI to control raspberry pi3 led in web
20190920
Written by Chun-Hsiang Chao
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv){
	char *query_string;
	FILE *file;
	int value=1;
	system("echo 22 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio22/direction");
	system("echo 1 > /sys/class/gpio/gpio22/value");
	system("echo 6 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio6/direction");
//	system("echo 0 > /sys/class/gpio/gpio6/value");

	query_string=getenv("QUERY_STRING");
	if(query_string && strstr(query_string,"led=1"))
	system("echo 1 > /sys/class/gpio/gpio6/value");
	else if(query_string && strstr(query_string,"led=0"))
	system("echo 0 > /sys/class/gpio/gpio6/value");

	file=fopen("/sys/class/gpio/gpio6/value","r");
	fscanf(file,"%d",&value);
	fclose(file);

	printf("Content-type: text/html\n");
	printf("\n");
	printf("<html><body><center>\n");
	printf("LED=%s<p>\n",value?"On":"Off");
	printf("<form action='/cgi-bin/led.cgi' method='get'>\n \
	<input type='hidden' name='led' value='1'>\n \
	<input type='submit' value='On'>\n \
	</form>\n");
	printf("<form action='/cgi-bin/led.cgi' method='get'>\n \
	<input type='hidden' name='led' value='0'>\n \
	<input type='submit' value='Off'>\n \
	</form>\n");
	printf("</center></body></html>\n");
	return 0;
}

