/*
Function Pointer Example.
20190904
Written by Chun-Hsiang Chao
*/
#include<stdio.h>
#include<time.h>
long int measure_execution_time(void){
	time_t t1,t2;
	int i;
	t1=time(NULL);
	while(1){
		i++;
		if(i==1000000000) break;
	}
	printf("Function Pointer\n");
	t2=time(NULL);
	return	t2-t1;
}
int main(void){
	long int(*fn_t)(void);
	fn_t=&measure_execution_time;
	long int time;
	time=(fn_t)();
	printf("%ld\n",time);
	return 1;
}


