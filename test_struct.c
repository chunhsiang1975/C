/*
Give the poker's card in random.
20190904
Written by Chun-Hsiang Chao
*/
#include<stdio.h>
struct book{
	char name[20];
	int price;
};

int main(void){
	struct book mcu={"Mcu programing",10};
	struct book *ptrst;
	ptrst=&mcu;
	ptrst->price=100;
	printf("Book of %s's price is %d.\n",ptrst->name,ptrst->price);
	mcu.price=200;
	printf("Book of %s's price is %d.\n",ptrst->name,ptrst->price);
	(*ptrst).price=300;
	printf("Book of %s's price is %d.\n",ptrst->name,ptrst->price);
	return 0;
}

