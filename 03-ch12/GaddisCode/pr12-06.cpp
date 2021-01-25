/**
 * @file pr12-06.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program uses strcmp to compare the string entered
 *        by the user with the valid part numbers.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
#include <cstring>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::showpoint;
using std::fixed;
using std::setprecision;

int main()
{
    // Price of items
    const double A_PRICE = 49.0, B_PRICE = 69.95;
                        
    // Character array for part number			 
    const int PART_LENGTH = 8;
    char partNum[PART_LENGTH];   

    // Instruct the user to enter a part number
    cout << "The computer part numbers are:\n";
    cout << "\tBlu-ray Disk Drive, part number S147-29A\n";
    cout << "\tWireless Router, part number S147-29B\n";
    cout << "Enter the part number of the item you\n";
    cout << "wish to purchase: ";

    // Read a part number of at most 8 characters
    cin >> setw(9);	
    cin >> partNum;

    // Determine what user entered using strcmp
    // and print its price
    cout << showpoint << fixed << setprecision(2);
    if (strcmp(partNum, "S147-29A") == 0)
    {
        cout << "The price is $" << A_PRICE << endl;
    }
    else if (strcmp(partNum, "S147-29B") == 0)
    {
        cout << "The price is $" << B_PRICE << endl;
    }
    else
    {
        cout << partNum << " is not a valid part number.\n";
    }
        
    return 0;
}