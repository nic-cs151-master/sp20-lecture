/**
 * @file pr12-14.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program prints out command-line arguments
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using std::cout;

// int main(int argc, char **argv)
int main(int argc, char *argv[])
{
    // get the number of arguments
    cout << argc << '\n';

    // print out each command-line argument
    for (int i = 0; i < argc; ++i)
    {
        cout << argv[i];
    }

    cout << argv[0] << '\n'; // name of the program
    cout << argv[1] << '\n'; // first argument
    cout << argv[2] << '\n'; // second argument

    return 0;
}

