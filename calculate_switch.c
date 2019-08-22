/*
Basic + - * / 's calculator used by switch.
*/
#include<stdio.h>
int main(){
	char op;
	int a,b,c;
	while(1){
		printf("Please input operator\n");
		scanf(" %c",&op);//There is a space in front of %c.
		switch(op){
			case '+':
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a+b;
			printf("%d+%d=%d\n",a,b,c);
			break;
			case '-':
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a-b;
			printf("%d-%d=%d\n",a,b,c);
			break;
			case '*':
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a*b;
			printf("%d*%d=%d\n",a,b,c);	
			break;
			case '/':
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a/b;
			printf("%d/%d=%d\n",a,b,c);	
			break;
			case 'x':
				break;
		}
	}
	return 0;
}
