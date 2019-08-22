/*
Print 9*9 form
*/
#include<stdio.h>
void func99(int x);
int main(){	
	int x;
	for(x=1;x<=9;x++){
		func99(x);
	}
	return 0;
}
void func99(int x){
	int y;
	for(y=1;y<=9;y++){
		printf("%d x %d = %d\n",x,y,x*y);		
	}
	printf("\n");
}
