/*
  	GPIO_INPUT example For raspberry pi 3
  	WebSite : 
	www.ittraining.com.tw 
	https://www.arduino.cc/en/tutorial/melody 
 	Written by Chun-Hsiang Chao
	Date:20191001
*/
#include <bcm2835.h>
#include <stdio.h>
#include "it_shield.h"

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;



void beep(int tone, int duration){
	for (long i = 0; i < duration * 1000L; i += tone * 2) {
		bcm2835_gpio_write(BUZZER, HIGH);
		bcm2835_delayMicroseconds(tone);
		bcm2835_gpio_write(BUZZER, LOW);
		bcm2835_delayMicroseconds(tone);
	}
}
 
void firstSection(){
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
	bcm2835_delay(500); 
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
	bcm2835_delay(500); 
}
 
void secondSection(){
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
	bcm2835_delay(325); 
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
	bcm2835_delay(350); 
}



int main(int argc, char **argv){
    // If you call this, it will not actually access the GPIO

    int value;
    if (!bcm2835_init())
	return 1;

    // Set the pin to be an output
	bcm2835_gpio_fsel(BUZZER, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(COM, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(COM, HIGH);
	firstSection();
	secondSection();
	
    while (1)
    { 
		
	}
    bcm2835_close();
    return 0;
}

