/*
Print number to 8bits binary number.
20190822
Writed by Chun-Hsiang Chao
*/
#include <stdio.h>
#include <math.h>
char* printf_binary(int number);
int main(void){
	int i;
	int number=85;//00000111
	//85=0x55=01010101
	//00011000 = 0x 18
	char *binary;
	binary=printf_binary(number);
	for(i=0;i<8;i++) printf("%c ",binary[i]);
	printf("\n");
	//printf("%c %c\n",binary[3],binary[4]);
	return 0;
}
char* printf_binary(int number){
		char binary[8];
		char *result;
		int i=0;
		//printf("%d\n",number);
		while(1){
			if(number%2==0){
			 binary[7-i]=48;
			}
			else binary[7-i]=49;
			number=(int)(number/2);
			i++;
			if(i==8) break;
		}
		result=binary;
		return result;
}
