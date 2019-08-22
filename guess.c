/*
Guess the number.
20190822
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	int i;
	srand(time(0));
	int n=rand();
	//printf("n=%d\n",n);
	do{
		printf("Guess the number\n");
		scanf("%d",&i);
		if(i>n){
			printf("Bigger than the number\n");
			continue;
		}
		else if(i<n){
			printf("Smaller than the number\n");
			continue;
		}
		else{
			printf("You guess the right!");
			break;
		}
	}while(1);
	return 0;	
}
