#include <iostream>
#include "opclass.h"
using namespace std;

int main() 
{
    OpClass a(5, 20);
    OpClass c(10, 3);
    OpClass b = 12;

    cout << "Enter a value of type OpClass: ";
    cin >> a;

    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "c: " << c << '\n';

    // Get the sum of a + b
    OpClass sum;
    sum = a + b;
    cout << "sum: " << sum << '\n';
    // sum = a.operator+(b);
    // Get the sum of b + c
    sum = b + c;
    cout << "sum: " << sum << '\n';

    sum = b + 2;
    sum = 2 + b;
    cout << "sum: " << sum << '\n';

    return 0;
}