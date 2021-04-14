/**
 * @file main.cpp
 * @author Gabe de la Cruz
 * @brief 
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <string>
#include <new>
// #include "IntRange.h"
// #include "IntRange2.h"
#include "IntRange3.h"
using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::bad_alloc;

float divide(float numerator, float denominator);
float divide2(float numerator, float denominator);

int main() 
{
    // float num1 = 0.0f, num2 = 0.0f;

    // cout << "Enter numerator: ";
    // cin >> num1;
    // cout << "Enter denominator: ";
    // cin >> num2;

    // try
    // {
    //     float quotient = divide2(num1, num2);
    //     cout << "Quotient is " << quotient << '\n';
    // }
    // catch (string ex)
    // {
    //     cerr << ex << '\n'; // stdout, stderr
    // }

    cout << "End of the program\n";

    try
    {
        int *x = new int;
        cout << "Enter a number: ";
        cin >> *x;
    }
    catch (bad_alloc)
    {
        cerr << "NOt enough RAM memory\n";
    }

    
    

    // try
    // {
    //     cout << "Enter a number between 5 to 20: ";
    //     cin >> number;
    //     cout << "The number is " << number << '\n';
    // }
    // catch (IntRange::OutOfRange)
    // {
    //     cerr << "The value inputted is out of range\n";
    // }

    // try
    // {
    //     cout << "Enter a number between 5 to 20: ";
    //     cin >> number;
    //     cout << "The number is " << number << '\n';
    // }
    // catch (IntRange2::TooLow)
    // {
    //     cerr << "The value inputted is below the range\n";
    // }
    // catch (IntRange2::TooHigh)
    // {
    //     cerr << "The value inputted is above the range\n";
    // }
    
    // IntRange3 number(5, 20);
    // try
    // {
    //     cout << "Enter a number between 5 to 20: ";
    //     cin >> number;
    //     cout << "The number is " << number << '\n';
    // }
    // catch (IntRange3::OutOfRange &ex)
    // {
    //     cerr << "The value " << ex.what() << " is invalid!\n";
    // }

    return 0;
}


float divide(float numerator, float denominator)
{
    if (denominator == 0)
    {
        cout << "ERROR: Cannot divide by zero.\n";
        return 0;
    }
    else
    {
        return numerator / denominator;
    }
}

float divide2(float numerator, float denominator)
{
    if (denominator == 0)
    {
        throw string("ERROR: Cannot divide by zero.\n");
    }

    return numerator / denominator;
}