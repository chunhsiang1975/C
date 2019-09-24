/*
	Practices on IT Training.
	Written by Chun-Hsiang Chao
	Date:20190925
*/
#include<stdio.h>
void set_value(unsigned int *addr,int shift, int value){
	unsigned int tmp=*addr;
	int mask;
	mask = value << shift;
	tmp=(tmp&~mask);
	tmp=tmp|mask;
	printf("mask %x\n",mask);
	printf("~mask %x\n",~mask);
	printf("%x\n",tmp);
}
int main(void){
	unsigned int a=0x12345678;
	set_value(&a,12,0xFF);
	return 1;
}
