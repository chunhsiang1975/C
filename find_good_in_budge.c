/*
Find the good's price which's price is the most near budge.
20190828
Writed by Chun-Hsiang Chao
*/
#include<stdio.h>
#include<time.h>
#define array_number 20
#define budge 20000
int main(void){
	int price[array_number];
    int i;
    int match;
    srand(time(0));
    for(i=0; i<array_number; i++) price[i] = rand();
    for(i=0; i<array_number; i++) printf("%d ", price[i]);
	printf("\n");	
    match=price[0];
    i=1;
	while(1){
		if(match>budge){
			match=price[i];
			i++;
			continue;
		}
		if((budge-price[i]>0)&&(price[i]>match)){match=price[i];}
		else i++;
		if(i==array_number)break;		
	}
	printf("The good's price=%d\n",match);
	return 0;
}

