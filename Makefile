#	Written by Chun-Hsiang Chao
#	Date:20191001
CC=gcc
OPTIONS= -D_PI2_
INC= -I../../src ../../src/bcm2835.c $(OPTIONS)
LIB= 

all:blink buzzer gpio pir relay buzzer_play_music

%:%.c
	$(CC) $(INC) -o $@ $? $(LIB) 	
