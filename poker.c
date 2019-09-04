/*
Give the poker's card in random.
20190904
Written by Chun-Hsiang Chao
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct one_card_{
	int suit;
	int num;
}one_card;
int card_number;
char SUIT[4] = {'S', 'H', 'D', 'C'};
int card[4][13];
void init_card(void);
void print_card(void);
void init_card(void){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			card[i][j]=j;
		}
	}
}
void print_card(void){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			printf("%d ",card[i][j]);
		}
		printf("\n");
	}
}
one_card deal(void){
	one_card one;
	int s,r;
	while(1){
    	s = rand()%4;
    	r = rand()%13;
		if(card[s][r]!=-1){
			one.suit=s;
			one.num=r;
			card[s][r]=-1;
			card_number++;
			return one;
		}
	}
}
int main(void){
    int i; 
    int suit, rank;
   	one_card one; 
    srand(time(0));
	init_card();
	//print_card();
	card_number=0;
    for(i=0; i<54; i++){
        one=deal();
        printf("%d %c %d\n",card_number, SUIT[one.suit], one.num+1);
        if(card_number==52){
        	printf("Card is empty.\n");	
        	break;
    	}
    }        
	//print_card();
    return 0;
}

