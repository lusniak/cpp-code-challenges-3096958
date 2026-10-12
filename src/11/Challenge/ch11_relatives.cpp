// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Person{
    std::string name;
    std::string surname;
};

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main()
{
    std::vector<Person> people;
    Person person;
    std::fstream file ("names.csv", std::ios::in);
    std::string text;
    // Read the CSV file.
    if(file.is_open())
    {
        std::getline(file,text);
        // Write your code here
        std::string part;

        for (char c : text)
        {
            if (c == ' ')
            {
                person.name = part;
                part.clear();
            }
            else if(c == ',')
            {
                person.surname = part;
                part.clear();
                people.push_back(person);
            }
            else
            {
                part += c;
            }
        }


        // ostatni fragment
        person.surname = part;
        part.clear();
        people.push_back(person);
    
        file.close();
    }
    else
    {
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    for(auto& element : people)
    {
        for(auto& elem : people)
        {
            if(element.name != elem.name)
            {     
                if(element.surname == elem.surname)
                {
                    std::cout << element.name << " " << element.surname << " is relative to " << elem.name << " " << elem.surname << std::flush;
                    return 0;
                }
            }
        }
    }

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 