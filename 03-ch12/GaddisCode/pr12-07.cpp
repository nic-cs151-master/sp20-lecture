/**
 * @file pr12-07.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program uses the return value of strcmp to
 *        alphabetically sort two strings entered by the user.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
#include <cstring>
using std::cout;
using std::cin;

int main()
{
    // Two arrays to hold two strings
    const int NAME_LENGTH = 30;
    char name1[NAME_LENGTH], name2[NAME_LENGTH];

    // Read two strings
    cout << "Enter a name (last name first): ";
    cin.getline(name1, NAME_LENGTH);
    cout << "Enter another name: ";
    cin.getline(name2, NAME_LENGTH);

    // Print the two strings in alphabetical order
    cout << "Here are the names sorted alphabetically:\n";
    if (strcmp(name1, name2) < 0)
    {
        cout << name1 << endl << name2 << endl;
    }
    else if (strcmp(name1, name2) > 0)
    {
        cout << name2 << endl << name1 << endl;	
    }
    else
    {
        cout << "You entered the same name twice!\n";
    }
        
    return 0;
}