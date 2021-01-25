/**
 * @file pr12-09.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates the use of the stoXXX()
 *        numeric conversion functions.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;


int main()
{   
    string str;   // String to convert
    size_t pos;   // Hold position of stopping character

    // Convert string to double
    str = "-342.57is a number";
    cout << "The string is " << str << endl;   
    double d = stod(str, &pos);
    cout << "The converted double is " << d << endl;
    cout << "The stopping character is " << str[pos] 
        << " at position " << pos << endl;

    // Convert string to int (default to decimal)
    str = "-342.57is a number";
    cout << "\nThe string is " << str << endl; 
    int i = stoi(str, &pos);
    cout << "The converted integer is " << i << endl;
    cout << "The stopping character is " << str[pos] 
        << " at position " << pos << endl;

    // Convert string to int (base is binary)
    str = "01110binary number";
    cout << "\nThe string is " << str << endl;   
    i = stoi(str, &pos, 2);
    cout << "The converted binary integer is " << i << endl;
    cout << "The stopping character is " << str[pos] 
        << " at position " << pos << endl;

     return 0;
}