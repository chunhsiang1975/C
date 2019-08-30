#include <stdio.h>
int main(){
    int a, b;
    int *p;
    //char 32 bits
    //*((volatile unsigned char *)0x300021) |= 0x10;//0x300021 is memory address, 0x300021's value = 0x300021's value | 0x10
    printf("\n %p : %d \n", &a, a); 
    *((int*)0x0022fe4c) = 100;  
    printf("\n %d \n", a); 
    printf("\n %d \n", *((int*)0x0028ff44) );
    /*
	 p = 0x0028ff44;
    *p = 200;
    printf("\n %d, %d \n", *p, a);
	*/
    return 0;
}
