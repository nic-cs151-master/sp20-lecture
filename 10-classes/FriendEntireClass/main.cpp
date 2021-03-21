#include <iostream>
#include "aclass.h"
#include "frclass.h"
using namespace std;

int main() 
{
    AClass test1;
    FrClass test2;

    test2.fSet(test1, 12);
    cout << test1.getX() << '\n';
    cout << test2.fGet(test1) << '\n';
}