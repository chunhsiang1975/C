/*
Tic ta toc and Gomoku
20190830
Source Version Address :  https://qiita.com/OliverNotepad/items/78151ee78cb0f33034ea
Fixed by Chun-Hsiang Chao
*/
#include<stdio.h>
#include<stdlib.h>
#define BOARD_SQUARE 20                 						//Board's size
#define win_size_in_parallel 5									//3:tic_ta_toc  5:gomoku 
void Board_Output(void);                                        //Generate Board size in monitor
void Game(void);                                                //Deal with input
void Board_Scan(int x, int y);                                  //Check Board
int Board_Scan_Sub( int x, int y, int move_x, int move_y );     //Check Board
void print_board(void);
void Finish(void);                                              //Game over
int board[BOARD_SQUARE][BOARD_SQUARE] ;    
int player_number = 1;
int main(void){
    int i;
    Board_Output();
    printf("GAME START!\n");
    for( i = 0; i < (BOARD_SQUARE * BOARD_SQUARE); i++ ){
        Game();
        Board_Output();
        if( player_number < 2 ) player_number++;
        else player_number = 1;
    }
    printf("GAME Draw!\n");
    return 0;
}

void print_board(void){
	int i,j;
	for(i=0;i<BOARD_SQUARE;i++){
		for(j=0;j<BOARD_SQUARE;j++)	{
			
			switch( board[j][i] ){
                case 0:     printf("  "); break;
                case 1:     printf(" O"); break;
                case 2:     printf(" X"); break;
            }
			printf("%d ",board[j][i]);	
		}
		printf("\n");
	}
}

//---------------------------------------
void Board_Output(void){
    int i, j;
    printf("  ");
    for( i = 0; i < BOARD_SQUARE; i++ ){
        printf("%2d",i);
    }
    puts("");//Change line
    for( i = 0; i < BOARD_SQUARE; i++ ){        
        printf("%2d",i);        
        for( j = 0; j < BOARD_SQUARE; j++ ){
            switch( board[j][i] ){
                case 0:     printf("  "); break;
                case 1:     printf(" O"); break;
                case 2:     printf(" X"); break;
            }
        }
        puts("");
    }
    puts("");
}

//---------------------------------------
void Game(void){
    int x, y;
    printf("%dP(",player_number);
    switch( player_number ){
        case 0:     printf("  "); break;
        case 1:     printf(" O"); break;
        case 2:     printf(" X"); break;
    }
    printf(")Turn you\n");
    while(1){
        while(1){
            printf("Please input(x y) "); scanf("%d %d",&x ,&y);
            if( x >= 0 && x < BOARD_SQUARE && y >= 0 && y < BOARD_SQUARE ) break;
            else printf("You can't put this.\n");
        }
        if( board[x][y] == 0 ){
            board[x][y] = player_number;
            break;
        } else printf("You can't put this.\n");
    }
    Board_Scan(x, y);
}
//---------------------------------------
void Board_Scan( int x, int y ){
    int n[4];                  //Number of 8directions in parallel 
    int move_x, move_y;
    int i;

    move_x = 1; move_y = 1;     //[\]direction
    n[0] = Board_Scan_Sub( x, y, move_x, move_y );

    move_x = 0; move_y = 1;     //[|]direction
    n[1] = Board_Scan_Sub( x, y, move_x, move_y );

    move_x = 1; move_y = 0;     //[-]direction
    n[2] = Board_Scan_Sub( x, y, move_x, move_y ); 

    move_x = 1; move_y = -1;    //[/]direction
    n[3] = Board_Scan_Sub( x, y, move_x, move_y );

    for( i = 0; i < 4; i++ ){
        if(n[i] == win_size_in_parallel) Finish();
    }
}

int Board_Scan_Sub( int x, int y, int move_x, int move_y ){
    int n = 1;                                 //calculate the number in parallel
    int i;

    for( i = 1; i < win_size_in_parallel; i++ ){
    	if(((x + (1*move_x * i))<BOARD_SQUARE)&&((y + (1*move_y * i))<BOARD_SQUARE)){
        	if( board[ x + (move_x * i) ][ y + (move_y * i) ] == player_number ) n += 1;
        	else break;
    	}
    }
    for( i = 1; i < win_size_in_parallel; i++ ){
    	if(((x + (-1*move_x * i))>-1)&&((y + (-1*move_y * i))>-1)){
        	if( board[ x + (-1*move_x * i) ][ y + (-1*move_y * i) ] == player_number ) n += 1;
        	else break;
    	}
    }

    return n;
}
//---------------------------------------
void Finish(void){
    Board_Output();
    printf("%dP(",player_number);
    switch( player_number ){
        case 0:     printf("  "); break;
        case 1:     printf(" O"); break;
        case 2:     printf(" X"); break;
    }
    printf("Win!\n");
    exit(0);
}
