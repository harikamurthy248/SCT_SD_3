#include <stdio.h>
#include <stdbool.h>
#define N 9

bool isValid(int grid[N][N],int row,int col,int num) 
{
    for(int x=0;x<N;x++) 
    {
        if(grid[row][x] == num) 
        {
            return false;
        }
    }
    
    for(int x=0;x<N;x++) 
    {
        if(grid[x][col]==num) 
        {
            return false;
        }
    }

    int startRow=row-row%3,startCol=col-col%3;
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            if(grid[i+startRow][j+startCol]==num) 
            {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyLocation(int grid[N][N],int *row,int *col) 
{
    for(*row=0;*row<N;(*row)++) 
    {
        for(*col=0;*col<N;(*col)++) 
        {
            if(grid[*row][*col]==0) 
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N]) 
{
    int row,col;

    if(!findEmptyLocation(grid,&row,&col)) 
    {
        return true;
    }

    for(int num=1;num<=9;num++) 
    {
        if(isValid(grid,row,col,num)) 
        {
            grid[row][col]=num;
            if(solveSudoku(grid)) 
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[N][N]) 
{
    for(int row=0;row<N;row++) 
    {
        for(int col=0;col<N;col++) 
        {
            printf("%2d ",grid[row][col]);
        }
        printf("\n");
    }
}

void inputGrid(int grid[N][N]) 
{
    printf("Enter the Sudoku puzzle (9x9 grid) row by row:\n");
    printf("(Use 0 for empty cells)\n");
    for(int row=0;row<N;row++) 
    {
        printf("Enter row %d (9 numbers separated by space): ",row+1);
        for(int col=0;col<N;col++) 
        {
            scanf("%d",&grid[row][col]);
        }
    }
}

int main() 
{
    int grid[N][N];
    inputGrid(grid);
    if(solveSudoku(grid)) 
    {
        printf("\nSolved Sudoku:\n");
        printGrid(grid);
    } 
    else 
    {
        printf("No solution exists\n");
    }
    return 0;
}