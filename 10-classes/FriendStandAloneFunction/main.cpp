#include <iostream>
#include "aclass.h"
using namespace std;

int main() 
{
    AClass test;

    // fSetOrig(test, 12);
    // cout << test.getX() << '\n';

    fSet(test, 12);
    cout << test.getX() << '\n';
}