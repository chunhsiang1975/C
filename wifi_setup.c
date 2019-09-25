/*
 *  Insert ssid and passwd to wifi config file
 *  Written by Chun-Hsiang Chao
 *  Date::20190925
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *out;
	char config_file[100]="/etc/wpa_supplicant/wpa_supplicant.conf";
	char *ssid;
	char *passwd;
	ssid=argv[1];
	passwd=argv[2];
	if((argv[1]!=NULL)&&(argv[2]!=NULL)){
		out=fopen(config_file,"a");
		fprintf(out,"network={\n");
		fprintf(out,"\tssid=\"%s\"\n",ssid);
		fprintf(out,"\tpsk=\"%s\"\n",passwd);
		fprintf(out,"}\n");
		fclose(out);	
	}
	else{
		printf("ssid or passwd error\n");
	}
	return 1;
}
