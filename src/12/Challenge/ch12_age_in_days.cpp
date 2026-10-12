// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main()
{
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age = 0;
    int year_dif, month_dif, day_dif;
    bool firstYearLeap = false;

    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    std::time_t now = std::time(nullptr);
    std::tm* date = std::localtime(&now);

    int day_now = date->tm_mday;
    int month_now = date->tm_mon + 1;
    int year_now = date->tm_year + 1900;

    std::cout << day_now << "." << month_now << "." << year_now << std::endl;

    int days_in_year = 0;
    for(int year = birth_y + 1; year < year_now; year++)
    {
        if(year % 4 != 0)
        {
            //do nothing
        }
        else if(year % 100 != 0)
        {
            firstYearLeap = true;
        }
        else if(year % 400 != 0)
        {
            //do nothing
        }
        else
        {
            firstYearLeap = true;
        }
    }

    age = days_in_year;

    if(birth_y % 4 != 0)
    {
        days_in_year += 365;
    }
    else if(birth_y % 100 != 0)
    {
        days_in_year += 366;
    }
    else if(birth_y % 400 != 0)
    {
        days_in_year += 365;
    }
    else
    {
        days_in_year += 366;
    }

    for(int month = 1; month < birth_m; month++)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            age += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            age += 30;
            break;
        case 2:
            if(firstYearLeap)
            {
                age += 29;
                break;
            }
            else
            {
                age += 28;
                break;
            }
        default:
            break;
        }
    }



    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
