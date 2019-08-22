/*
Sum of divide 1~100's number by 5 which's remainder is 0.
*/
#include<stdio.h>
int main(){	
	int i,sum=0;
	i=1;
	while(1){
		if(i%5==0){
			sum=sum+i;	
		}
		i++;
		if(i==101) break; 	
	}
	printf("sum=%d\n",sum);
	return 0;
}
