#include <iostream>
#include <stack>
#include <queue>
#include <unistd.h>
using namespace std;

const int MAZE_ROW_SIZE = 6;
const int MAZE_COL_SIZE = 6;

struct Point
{
    int row;
    int col;
    char type;

    Point(int row1=-1, int col1=-1)
    {
        row = row1;
        col = col1;
    }
};

void displayMaze(char maze[][MAZE_COL_SIZE]);
bool findPath(char maze[][MAZE_COL_SIZE], int row, int col);
bool findPathIt(char maze[][MAZE_COL_SIZE], int startRow, int startCol);
void addToStack(stack<Point> &moves, char maze[][MAZE_COL_SIZE], int row, int col);
bool isValid(char maze[][MAZE_COL_SIZE], int row, int col);

int main()
{   
    char maze1[][MAZE_COL_SIZE] = {{'.', '#', '#', '#', '#', '#'},
                                   {'.', '.', '.', '.', '.', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'.', '.', '.', '#', '.', 'G'},
                                   {'#', '#', '.', '.', '.', '#'}};
    
    char maze2[][MAZE_COL_SIZE] = {{'.', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    char maze3[][MAZE_COL_SIZE] = {{'.', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '#', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    findPathIt(maze1, 1, 1);
    findPathIt(maze2, 1, 3);

    return 0;
}

void displayMaze(char maze[][MAZE_COL_SIZE])
{
    system("clear");
    for (int row = 0; row < MAZE_ROW_SIZE; ++row)
    {
        for (int col = 0; col < MAZE_COL_SIZE; ++col)
        {
            cout << maze[row][col];
        }
        cout << '\n';
    }
    usleep(500000);
}

bool isValid(char maze[][MAZE_COL_SIZE], int row, int col)
{
    // Is it within the maze?
    if (row >= 0 && row < MAZE_ROW_SIZE && col >= 0 && col < MAZE_COL_SIZE)
    {
        // Possible path
        return (maze[row][col] == '.' || maze[row][col] == 'G');
    }

    return false;
}

void addToStack(stack<Point> &moves, char maze[][MAZE_COL_SIZE], int row, int col)
{
    moves.push(Point(row, col));

    if (isValid(maze, row-1, col))
        moves.push(Point(row-1, col));

    if (isValid(maze, row+1, col))
        moves.push(Point(row+1, col));

    if (isValid(maze, row, col+1))
        moves.push(Point(row, col+1));

    if (isValid(maze, row, col-1))
        moves.push(Point(row, col-1));
}

bool findPathIt(char maze[][MAZE_COL_SIZE], int startRow, int startCol)
{
    stack<Point> moves;

    int row = startRow;
    int col = startCol;

    maze[row][col] = '+';
    displayMaze(maze);
    addToStack(moves, maze, row, col);

    while (!moves.empty())
    {
        Point pos = moves.top();
        moves.pop();

        row = pos.row;
        col = pos.col;

        // found goal
        if (maze[row][col] == 'G')
        {
            return true;
        }
        // backtrack
        else if (maze[row][col] == '+')
        {
            maze[row][col] = '.';
            displayMaze(maze);
        }
        // it's a possible path
        else
        {
            maze[row][col] = '+';
            displayMaze(maze);
            addToStack(moves, maze, row, col);
        }
    }

    return false;
}

bool findPath(char maze[][MAZE_COL_SIZE], int row, int col)
{
    // goal found
    if (maze[row][col] == 'G')
        return true;
    
    // choose x,y as part of solution path
    maze[row][col] = '+';
    displayMaze(maze);

    if (isValid(maze, row, col-1) && findPath(maze, row, col-1))
        return true; // West
    if (isValid(maze, row, col+1) && findPath(maze, row, col+1))
        return true; // East
    if (isValid(maze, row+1, col) && findPath(maze, row+1, col))
        return true; // North
    if (isValid(maze, row-1, col) && findPath(maze, row-1, col))
        return true; // South

    // unchoose x, y it's not part of solution
    maze[row][col] = '.';
    displayMaze(maze);

    return false;
}