#include <iostream>
#include "employee.h"
#include "programmer.h"

using std::cout;

int main()
{
    // Employee *x = new Programmer("John", 123232, false);
    Programmer x("John", 123232, false);

    cout << x.toString() << '\n';

    return 0;
}