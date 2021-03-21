#include "numarray.h"


int main()
{
    NumArray x(5, 0);
    x.setValue(0, 34);
    x.setValue(3, 12);

    NumArray y = x; // override default copy constructor
    // y.arr = x.arr
    // y.arraySize = x.arraySize

    return 0;
}