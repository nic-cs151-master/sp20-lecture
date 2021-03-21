// test.cpp
// Description: Implement my own version of the string that uses
//  dynamic memory allocation and C-string
// Name(s):
// Date:
#include <iostream>

#include "myString.h"
using namespace std;

void printChar(const char &ch);

int main()
{
    String extra;
    cout << "Enter a string: ";
    cin >> extra;
    cout << "Word: " << extra;

    String s0("Hi");
    cout << s0 << '\n';

    String s1 = "Hello";
    cout << s1 << '\n';

    String s2(s1);
    cout << s2 << '\n';

    String s3 = s1;
    cout << s3 << '\n';

    s1.str("I am starting to get smarter");
    cout << s1 << '\n';

    s1 = "I am really getting smarter!";

    String s4;
    s4.str(s1);
    cout << s4 << '\n';

    String s5 = "I am still craving for more knowledge!";
    String s6;
    s6 = s5;
   
    s5[3] = 'm';
    s5[5] = 'S';
    s5[11] = 'C';
    s5[19] = 'F';
    s5[23] = 'M';
    s5[28] = 'K';
    cout << "character at index 19: " << s5[19] << '\n';

    cout << s5.c_str() << '\n';


    return 0;
}

void printChar(const char &ch)
{
    cout << ch;
}