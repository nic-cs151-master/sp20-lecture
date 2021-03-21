#include <iostream>
#include "aclass.h"
#include "otherclass.h"
using namespace std;

int main() 
{
    AClass test1;
    OtherClass test2;

    test2.fSet(test1, 12);
    cout << test1.getX() << '\n';
}