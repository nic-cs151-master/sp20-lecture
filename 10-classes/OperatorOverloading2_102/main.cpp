#include <iostream>
#include "opclass.h"
using namespace std;

int main() 
{
    OpClass a(5, 20, 4); // a.x=50, a.y=20, a.z=4
    OpClass b(10, 3, 12); // b.x = 10, b.y = 3, b.z = 12

    OpClass c = a;  // triggers the copy constructor
    // c.x = a.x
    // c.y = a.y
    // c.z = a.z

    cout << "a.z: " << a.getZ() << '\n';
    cout << "c.z: " << c.getZ() << '\n';

    OpClass d, e;
    d = b; // overloaded assignment operator
    cout << "b.z: " << b.getZ() << '\n';
    cout << "d.z: " << d.getZ() << '\n';
    // cout << "e.z: " << e.getZ() << '\n';


    return 0;
}