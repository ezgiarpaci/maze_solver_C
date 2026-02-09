#include <stdio.h>
#include <stdbool.h>

#define MAX 10 


bool solveMaze(int maze[MAX][MAX], int x, int y, int rows, int cols);
void printMaze(int maze[MAX][MAX], int rows, int cols);
void printSolution(int maze[MAX][MAX], int rows, int cols);

int main() {
    int maze[MAX][MAX];
    int rows, cols;
    int i, j;

   

    scanf("%d %d", &rows, &cols);
    printf("Enter the dimensions of the maze (rows and columns): %d %d\n", rows, cols);

    
    if (rows > MAX || cols > MAX) {
        printf("Error: Max dimensions are %dx%d\n", MAX, MAX);
        return 1;
    }

    
    printf("Enter the maze (row by row, with 0 for open and 1 for wall):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    
    printf("\nInput Maze:\n");
    printMaze(maze, rows, cols);

   
    if (solveMaze(maze, 0, 0, rows, cols)) {
        printf("\nSolution Path:\n");
        printSolution(maze, rows, cols);
    } else {
        printf("\nNo path exists.\n");
    }

    return 0;
}


bool solveMaze(int maze[MAX][MAX], int x, int y, int rows, int cols) {
   
    if (x == rows - 1 && y == cols - 1 && maze[x][y] == 0) {
        maze[x][y] = 2; 
        return true;
    }

  
    if (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0) {
        
        
        maze[x][y] = 2;

     
        
   
        if (solveMaze(maze, x + 1, y, rows, cols))
            return true;

   
        if (solveMaze(maze, x, y + 1, rows, cols))
            return true;
        
     
        if (solveMaze(maze, x - 1, y, rows, cols))
            return true;

      
        if (solveMaze(maze, x, y - 1, rows, cols))
            return true;

        
        maze[x][y] = 0;
        return false;
    }

    return false;
}


void printMaze(int maze[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}


void printSolution(int maze[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 2) {
                printf("* "); 
            } else {
                printf("%d ", maze[i][j]); 
            }
        }
        printf("\n");
    }
}
