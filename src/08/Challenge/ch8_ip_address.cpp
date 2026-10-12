// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip)
{
    std::string fourChars[4];

    int i = 0;
    for(auto& element : ip)
    {
        if(element != '.')
            fourChars[i] += element;
        else
        {
            i++;
        }  
    }
    if(i != 3)
    {
        return false;
    }

    int num[4] = {-1,-1,-1,-1};

    for(int i = 0; i < 4; i++)
    {
        for(auto& element : fourChars[i])
        {
            if(!isdigit(element))
            {
                return false;
            }
        }
        num[i] = stoi(fourChars[i]);
        if(num[i] < 0 || num[i] > 255)
        {
            return false;
        }
    }
    return true;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
