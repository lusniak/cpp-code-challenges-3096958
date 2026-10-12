// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include <thread>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main()
{
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    do{
        std::string entered;
        std::uniform_int_distribution<int> dist0(400, 1000);
        int delay_ms = dist0(gen);
        std::uniform_int_distribution<int> dist1(0, 9);
        int word_index = dist1(gen);

        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        auto start = std::chrono::steady_clock::now();
        std::cout << "Type in: " << words[word_index] << std::endl;
        std::getline(std::cin, entered);
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::transform(entered.begin(), entered.end(), entered.begin(), [](unsigned char c){ return std::toupper(c); });
        if(entered == words[word_index] && elapsed.count() <= 2000)
        {
            std::cout << "You won!" << std::endl;
        }
        else if(entered != words[word_index] && elapsed.count() <= 2000)
        {
            std::cout << "Fast but incorrect!" << std::endl;
        }
        else if(entered == words[word_index] && elapsed.count() > 2000)
        {
            std::cout << "Correct but not fast enough!" << std::endl;
        }
        else
        {
            std::cout << "Lost badly!" << std::endl;
        }

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');

    return 0;
}
