/*
Print prime
*/
#include<stdio.h>
int isPrime(int number);
int main(void){	
	int i;
	int count=0;
	for(i=2;i<1000;i++){
		if(isPrime(i)){
			printf("%d is Prime\n",i);
			count++;
		}
	}
	printf("Total %d\n",count);
	return 0;
}
int isPrime(int number){
	int i;
	for(i=2;i<number;i++){
		if(number%i==0) return 0;
	}
	return 1;
}
