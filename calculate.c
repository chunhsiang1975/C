#include<stdio.h>
int main(){
	char op;
	int a,b,c;
	while(1){
		printf("Please input operator\n");
		scanf(" %c",&op);//There is a space in front of %c.
		if(op=='+'){
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a+b;
			printf("%d+%d=%d\n",a,b,c);
		}
		else if (op=='-'){
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a-b;
			printf("%d-%d=%d\n",a,b,c);
		}
		else if (op=='*'){
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a*b;
			printf("%d*%d=%d\n",a,b,c);
		}
		else if (op=='/'){
			printf("Please input two numbers\n");
			scanf("%i %i",&a,&b);
			c=a/b;
			printf("%d/%d=%d\n",a,b,c);
		}
		else if(op=='x'){
			break;
		}
	}
	return 0;
}
