// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

struct Neighbor{
    int row;
    int col;
};

Neighbor neighbor[8];

int howManyNeighbors(char game[][M], int row, int col)
{
    int retVal = 0;

    //up
    int rowtocheck = row - 1;
    int coltocheck = col;
    if(rowtocheck == 1)
    {
        rowtocheck = 10;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //up left
    rowtocheck = row - 1;
    coltocheck = col - 1;
    if(rowtocheck == 1)
    {
        rowtocheck = 10;
    }
    if(coltocheck == 1)
    {
        coltocheck = 10;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //up right
    rowtocheck = row - 1;
    coltocheck = col + 1;
    if(rowtocheck == 1)
    {
        rowtocheck = 10;
    }
    if(coltocheck == 10)
    {
        coltocheck = 1;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //left
    rowtocheck = row;
    coltocheck = col - 1;
    if(coltocheck == 1)
    {
        coltocheck = 10;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //right
    rowtocheck = row;
    coltocheck = col + 1;
    if(coltocheck == 10)
    {
        coltocheck = 1;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //down left
    rowtocheck = row + 1;
    coltocheck = col - 1;
    if(rowtocheck == 10)
    {
        rowtocheck = 1;
    }
    if(coltocheck == 1)
    {
        coltocheck = 10;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //down
    rowtocheck = row + 1;
    coltocheck = col;
    if(rowtocheck == 10)
    {
        rowtocheck = 1;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }
    //down right
    rowtocheck = row + 1;
    coltocheck = col + 1;
    if(rowtocheck == 10)
    {
        rowtocheck = 1;
    }
    if(coltocheck == 10)
    {
        coltocheck = 1;
    }
    if(game[rowtocheck][coltocheck] == 'X')
    {
        retVal++;
    }

    return retVal;
}


// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main()
{    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game)
        {
            for (auto &ch : str)
            {
                std::cout << " " << ch;
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        for(int row = 1; row <= N; row++)
        {
            for(int col = 1; col <= M; col++)
            {
                if(game[row][col] == 'X') //live cell
                {
                    int neighbors = howManyNeighbors(game, row, col);
                    if(neighbors < 2)
                    {
                        //death
                        game[row][col] = '-';
                    }
                    else if(neighbors <= 3)
                    {
                        //lives, do nothing
                    }
                    else if(neighbors > 3)
                    {
                        //death
                        game[row][col] = '-';
                    }
                }
                else //dead cell
                {
                    int neighbors = howManyNeighbors(game, row, col);
                    if(neighbors == 3)
                    {
                        //born
                        game[row][col] = 'X';
                    }
                }
            }
        }

        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
