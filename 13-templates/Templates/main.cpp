#include <iostream>
#include "person.h"
// #include "overloading.h"
#include "swap.h"
#include "joiner.h"

using std::cout;

int main() 
{
    int num1 = 20, num2 = 30;
    cout << num1 << " --- " << num2 << '\n';
    swap(num1, num2);
    cout << num1 << " --- " << num2 << " swapped\n";

    float num3 = 20.4f, num4 = 31.4f;
    cout << num3 << " --- " << num4 << '\n';
    swap(num3, num4);
    cout << num3 << " --- " << num4 << " swapped\n";

    // How about swapping characters?
    char val1 = 'a', val2 = 'b';
    cout << val1 << " --- " << val2 << '\n';
    swap(val1, val2);
    cout << val1 << " --- " << val2 << " swapped\n";

    // How about other primitive data types?
    // How about classes and structs you create?
    Person p1("John", 20), p2("Henry", 21);
    cout << p1 << " --- " << p1 << '\n';
    swap(p1, p2);
    cout << p1 << " --- " << p1 << " swapped\n";

    // With or without pointer member variables,
    // does having a copy constructor and overloading
    // the assignment operator matter for swapping operation?

    Joiner<int> j1;
    Joiner<string> j2;

    cout << j1.combine(45, 23) << '\n';
    cout << j2.combine("Hello ", "world") << '\n';

    return 0;
}