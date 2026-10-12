// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight)
{
    struct Position{
        int x;
        int y;
    };
    Position position;

    std::vector<Position> potentialMoves;
    std::vector<std::string> moves;

    switch(knight[0])
    {
        case 'a':
            position.x = 1;
            break;
        case 'b':
            position.x = 2;
            break;
        case 'c':
            position.x = 3;
            break;
        case 'd':
            position.x = 4;
            break;
        case 'e':
            position.x = 5;
            break;
        case 'f':
            position.x = 6;
            break;
        case 'g':
            position.x = 7;
            break;
        case 'h':
            position.x = 8;
            break;
        default:
            break;
    }
    position.y = knight[1] - '0';

    std::cout << position.x << " " << position.y;
    Position potential;

    //1
    potential.x = position.x + 2;
    potential.y = position.y + 1;
    potentialMoves.push_back(potential);
    //2
    potential.x = position.x + 2;
    potential.y = position.y - 1;
    potentialMoves.push_back(potential);
    //3
    potential.x = position.x - 2;
    potential.y = position.y + 1;
    potentialMoves.push_back(potential);
    //4
    potential.x = position.x - 2;
    potential.y = position.y - 1;
    potentialMoves.push_back(potential);
    //5
    potential.x = position.x + 1;
    potential.y = position.y + 2;
    potentialMoves.push_back(potential);
    //6
    potential.x = position.x - 1;
    potential.y = position.y + 2;
    potentialMoves.push_back(potential);
    //7
    potential.x = position.x + 1;
    potential.y = position.y - 2;
    potentialMoves.push_back(potential);
    //8
    potential.x = position.x - 1;
    potential.y = position.y - 2;
    potentialMoves.push_back(potential);

    for(auto& element : potentialMoves)
    {
        std::cout << element.x << " " << element.y << std::endl;
    }

    for (auto it = potentialMoves.begin(); it != potentialMoves.end(); )
    {
        if (it->x < 1 || it->x > 8 || it->y < 1 || it->y > 8)
        {
            it = potentialMoves.erase(it);
        }
        else
        {
            it++;
        }
    }

    std::cout << std::endl;
    for(auto& element : potentialMoves)
    {
        std::string move(2, ' ');
        switch(element.x)
        {
            case 1:
                move[0] = 'a';
                break;
            case 2:
                move[0] = 'b';
                break;
            case 3:
                move[0] = 'c';
                break;
            case 4:
                move[0] = 'd';
                break;
            case 5:
                move[0] = 'e';
                break;
            case 6:
                move[0] = 'f';
                break;
            case 7:
                move[0] = 'g';
                break;
            case 8:
                move[0] = 'h';
                break;
            default:
                break;
        }
        move[1] = '0' + element.y;
        moves.push_back(move);
        
        std::cout << element.x << " " << element.y << std::endl;
    }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}