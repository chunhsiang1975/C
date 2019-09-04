/*
Print the binary number's third and fouth bit's number.
20190822
Written by Chun-Hsiang Chao
*/
#include <stdio.h>
int main(void){
	unsigned short number;
	number=0xaa;//170=0xaa=10101010
	//scanf("%hi",number);In normal %i take 32bits %hi take 16bits,%hhi take 8bits. 
	//& is used for mask. let some bit to be 0.
	//| is used for mask. let some bit to be 1.
	//0x18=00011000
	printf("%hx %hx\n",(number&0x18)>>3,(number&0x18)>>4);
	return 0;
}

