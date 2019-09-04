#include <stdio.h>
#include <stdlib.h> //system()
#include <unistd.h> //sleep(), usleep()
#include <conio.h>  //Non-POSIX, getch(), kbhit()

#define ROW 24
#define COLUMN 80

char grid[ROW][COLUMN];

void show_grid()
{
    int row, col;

    system("cls");  // "cls" for Windows, "clear" for Linux
    for(row=0; row<ROW; row++)
        for(col=0; col<COLUMN; col++)
            putchar(grid[row][col]);
}

void show_grid2()
{
    int row, col;

    system("cls");  // "cls" for Windows, "clear" for Linux
    grid[ROW-1][COLUMN-1] = '\0';
    printf("%s", &(grid[0][0]));
}

void init_grid()
{
    int row, col;

    for(row=0; row<ROW; row++)
        for(col=0; col<COLUMN; col++)
            grid[row][col] = ' ';

    for(col=0; col<COLUMN; col++){
        grid[0][col] = '*';
        grid[ROW-1][col] = '*';
    }

    for(row=1; row<ROW-1; row++){
        grid[row][0] = grid[row][COLUMN-1] = '*';
    }
}

int main()
{
    int row, col;
    int dirHigh, dirLow;
    
    init_grid();

    grid[row=12][col=40] = '*';
    dirLow = 80;

    while(1)
    {
        show_grid2();
        
        usleep(100000); //control speed

        while(kbhit())
        {
            dirHigh = getch();
            if(dirHigh==224)
                dirLow = getch();
        }

        if(dirLow==72){         //up
            row--;
        }
        else if(dirLow==80){    //down
            row++;
        }
        else if(dirLow==75){    //left
            col--;
        }
        else if(dirLow==77){    //right
            col++;
        }
        
        grid[row][col] = '*';
   }

    return 0;
}
