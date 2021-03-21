#include <iostream>
using namespace std;

void function()
{
    int *p = new int;

    *p = 20;

    // delete p;
}

int main()
{
    function();

    return 0;
}