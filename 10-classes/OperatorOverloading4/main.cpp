#include <iostream>
#include "rectangle.h"
using namespace std;

int main() 
{
    Rectangle rec1(5.5, 8.0);
    Rectangle rec2(2.0, 1.0);
    Rectangle rec3;

    cout << rec1 << '\n';
    cout << rec2 << '\n';

    cin >> rec3;
    cout << rec3;

    if (rec1 > rec2)
    {
        cout << "rec1 is greater than rec2\n";
    }

    if (rec1 == rec2)
    {
        cout << "rec1 is equal to rec2\n";
    }
    else
    {
        cout << "rec 1 is not equal to rec2\n";
    }

    return 0;
}