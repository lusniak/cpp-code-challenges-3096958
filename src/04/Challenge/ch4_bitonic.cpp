// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
#define ASCENDING 1
#define DESCENDING 0
#define FLAT 2
#define INIT 3

bool is_bitonic(const std::vector<int> &v)
{
    bool retVal = false;
    int slopes = 0;
    int slope = INIT;

    for(int i = 1; i < v.size(); i++)
    {
        if(i == v.size() - 1)
        {
            if(v[0] == v[v.size()-1])
                break;
        }
        if(slope == INIT)
        {
            if(v[i] > v[i-1])
            {
                slopes++;
                slope = ASCENDING;
            }
            else if(v[i] < v[i-1])
            {
                slopes++;
                slope = DESCENDING;
            }
            else
            {
                slope = FLAT;
            }
        }
        else
        {
            if(slope == ASCENDING)
            {
                if(v[i] > v[i-1])
                {
                    //do nothing
                }
                else if(v[i] < v[i-1])
                {
                    slopes++;
                    slope = DESCENDING;
                }
                else //FLAT
                {
                    //do nothing
                }
            }
            else if(slope == DESCENDING)
            {
                if(v[i] > v[i-1])
                {
                    slopes++;
                    slope = ASCENDING;
                }
                else if(v[i] < v[i-1])
                {
                    //do nothing
                }
                else //FLAT
                {
                    //do nothing
                }
            }
        }
    }
    if(slopes <= 2)
    {
        retVal = true;
    }

    return retVal;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    //std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    //std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    //std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
     //std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
     //std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
     //std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
     //std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
     //std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
     //std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
     //std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
     std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
