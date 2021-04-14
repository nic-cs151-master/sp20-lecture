#include <iostream>
#include "hashset.h"

using std::cout;

int main()
{
    HashSet set;

    set.add(11);
    set.add(49);
    set.add(24);
    set.add(37);
    set.add(54);
    set.add(14);
    // set.add(86);
    // set.add(93);
    // set.add(123);
    // set.add(42);

    cout << set.toString();
}