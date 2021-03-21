#include <iostream>
#include "opclass.h"
using namespace std;

int main() 
{
    OpClass a(5, 20); // a.x = 5, a.y = 20
    OpClass c(10, 3); // c.x = 10, c.y = 3
    OpClass b = 12;   // b.x = 12, b.y = 12
    OpClass sum;

    cout << "Enter a value: ";
    cin >> a;
    
    // Get the sum of b + c

    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "c: " << c << '\n';

    // Get the sum of a + b
    sum = a + b;
    cout << "sum: " << sum << '\n';

    sum = b + c;
    cout << "sum: " << sum << '\n';


    sum = b + 2;
    sum = 2 + b;
    cout << "sum: " << sum << '\n';

    return 0;
}