#include "numarray.h"

NumberArray::NumberArray(int size, double initValue)
{
    arr = new double[size];
    arraySize = size;

    for (int i = 0; i < size; ++i)
    {
        arr[i] = initValue;
    }
}

NumberArray::NumberArray(const NumberArray &obj)
{
    // this = obj
    this->arraySize = obj.arraySize;

    this->arr = new double[this->arraySize];
    for (int i = 0; i < this->arraySize; ++i)
    {
        this->arr[i] = obj.arr[i];
    }
}

void NumberArray::print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}


void NumberArray::setValue(int index, double value)
{
    if (index < 0 || index >= arraySize)
    {
        return;
    }

    arrr[index] = value;
}