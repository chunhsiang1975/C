/*
Input array's x,y,w,h. Then print a rectange in the position x,y.
*/
#include <stdio.h>
int main(void){
	int x,y;
	int w,h,i,j;
	x=7;
	y=7;
	w=10;
	h=6;
	printf("Please input x y w h\n");
	scanf("%d %d %d %d",&x,&y,&w,&h);
	for(i=0;i<y-1;i++){
		for(j=0;j<x;j++){
			printf(" ");
		}
		printf("\n");
	}
	for(j=0;j<w+x-1;j++){
			if(j<x-1) printf(" ");
			else printf("*");
	}
	printf("\n");
	for(i=0;i<h-2;i++){
		for(j=0;j<w+x;j++){
			if(j<x-1) printf(" ");
			else{
				if(j==x-1||j==w+x-2) printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}
		for(j=0;j<w+x-1;j++){
			if(j<x-1) printf(" ");
			else printf("*");
	}
	printf("\n");
}
