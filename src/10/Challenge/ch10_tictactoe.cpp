// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

char game_state(char game[][3]);

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark)
{
    std::string str;
    int row, col;

    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1] != ' ');

    game[row-1][col-1] = mark;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

//#define TWO_PLAYERS
void make_move(char game[][3], char mark)
{ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else

    char opponent_mark = (mark == 'X' ? 'O' : 'X');

    //Winning move
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(game[row][col] != ' ')
            {
                //check next
            }
            else
            {
                game[row][col] = mark;
                char ret = game_state(game);
                if(ret == mark)
                {
                    //winning move, leave it
                    return;
                }
                else
                {
                    //not winning, restore
                    game[row][col] = ' ';
                }
            }
        }
    }

    //Blocking move
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(game[row][col] != ' ')
            {
                //check next
            }
            else
            {
                game[row][col] = opponent_mark;
                char ret = game_state(game);
                game[row][col] = ' ';
                if(ret == opponent_mark)
                {
                    //opponent winning move, block him there
                    game[row][col] = mark;
                    return;
                }
                else
                {
                    //not opponent winning move, check further
                }
            }
        }
    }

    //Center free
    if(game[1][1] == ' ')
    {
        game[1][1] = mark;
        return;
    }

    //Corner free
    {
        if(game[0][0] == ' ')
        {
            game[0][0] = mark;
            return;
        }
        else if(game[0][2] == ' ')
        {
            game[0][2] = mark;
            return;
        }
        else if(game[2][0] == ' ')
        {
            game[2][0] = mark;
            return;
        }
        else if(game[2][2] == ' ')
        {
            game[2][2] = mark;
            return;
        }
    }

    //Whatever field free
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(game[row][col] == ' ')
            {
               game[row][col] = mark;
               return;
            }
        }
    }


    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3])
{
    if(game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X')
    {
        return 'X';
    }
    else if(game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X')
    {
        return 'X';
    }
    else if(game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X')
    {
        return 'X';
    }
    else if(game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X')
    {
        return 'X';
    }
    else if(game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X')
    {
        return 'X';
    }
    else if(game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X')
    {
        return 'X';
    }
    else if(game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X')
    {
        return 'X';
    }
    else if(game[2][0] == 'X' && game[1][1] == 'X' && game[0][2] == 'X')
    {
        return 'X';
    }

    else if(game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O')
    {
        return 'O';
    }
    else if(game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O')
    {
        return 'O';
    }
    else if(game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O')
    {
        return 'O';
    }
    else if(game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O')
    {
        return 'O';
    }
    else if(game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O')
    {
        return 'O';
    }
    else if(game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O')
    {
        return 'O';
    }
    else if(game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O')
    {
        return 'O';
    }
    else if(game[2][0] == 'O' && game[1][1] == 'O' && game[0][2] == 'O')
    {
        return 'O';
    }

    else if(game[0][1] != ' ' && game[1][1] != ' ' && game[2][1] != ' ' && game[1][0] != ' ' && game[1][1] != ' ' && game[1][2] != ' ' && game[2][0] != ' ' && game[2][1] != ' ' && game[2][2] != ' ')
    {
        return 't';
    }


    return 'a';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3])
{
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main()
{
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o')
    {
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game) == 'a')
    {
        std::cout << turn << "'s turn...\n";    
        if(turn == user_mark)
        {
            ask_for_move(game,user_mark);
        }
        else
        {
            make_move(game,ai_mark);
        }
        print_game(game);
        turn = (turn == 'X' ? 'O' : 'X');
    }

    if(game_state(game) == 't')
    {
        std::cout << "It's a tie.\n\n";
    }
    else
    {
        std::cout << game_state(game) << " is the winner.\n\n";
    }
    std::cout << std::flush;

    return 0;
}
