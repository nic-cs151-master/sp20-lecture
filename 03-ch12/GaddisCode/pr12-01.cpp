/**
 * @file pr12-01.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates that string literals are
 *        pointers to char
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    // Define variables that are pointers to char
    const char *p = nullptr, *q = nullptr;
    // TODO: Try removing const, what happens when you compile?

    // Assign string literals to the pointers to char
    p = "Hello ";
    q = "Bailey";

    // TODO: Try modify first character of p H=>J
    cout << p[0];

    // Print the pointers as C-strings!
    cout << p << q << endl;

 
    return 0;
}