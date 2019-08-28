/*
Find max and min number from rand number.
20190828
Writed by Chun-Hsiang Chao
*/
#include<stdio.h>
#include<time.h>
#define array_number 10
int main(void){
	int a[array_number];
    int i;
    int max,min;
    srand(time(0));
    for(i=0; i<array_number; i++)
        a[i] = rand();
    for(i=0; i<array_number; i++) printf("%d ", a[i]);		
	printf("\n");
	max=a[0];
	min=a[array_number-1];
	i=1;
	while(1){
		if(a[i]<min) min=a[i];
		(a[i]>max)?max=a[i]:i++;
		
		if(i==array_number) break;
	}
	printf("max=%d min=%d\n",max,min);
	return 0;
}

