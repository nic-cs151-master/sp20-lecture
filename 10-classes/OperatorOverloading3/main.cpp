#include <iostream>
#include "opclass.h"
using namespace std;

int main() 
{
    OpClass a(5);
    OpClass b = 12; // type of b is OpClass, type of 12 is an integer literal int=>OpClas
    OpClass sum;

    cout << "a: " << a.getX() << '\n';
    cout << "b: " << b.getX() << '\n';

    sum = a + b; // sum = operator+(a, b);
    cout << "sum: " << sum.getX() << '\n';

    sum = b + 2; // sum = operator+(b, 2);
    cout << "sum: " << sum.getX() << '\n';

    sum = 2 + b; // sum = operator+(2, b);
    cout << "sum: " << sum.getX() << '\n';
    
    return 0;
}