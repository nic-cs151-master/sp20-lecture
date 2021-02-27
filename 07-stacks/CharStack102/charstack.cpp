#include "charstack.h"

// CharStack::CharStack()
// {
//     // initialize
//     mStackArray = new char[10];
//     mCapacity = 10;
//     mTop = 0;
// }

CharStack::CharStack(int stackSize)
{
    // initialize
    mStackArray = new char[stackSize];
    mCapacity = stackSize;
    mTop = 0;
}

CharStack::~CharStack()
{
    delete [] mStackArray;
}


void CharStack::push(char x)
{
    if (isFull())
    {
        cerr << "Stack is full!\n";
        return;
    }

    mStackArray[mTop++] = x;
    // mTop++;
}

void CharStack::pop()
{
    if (isEmpty())
    {
        cerr << "Stack is empty! No bueno!\n";
        return;
    }

    --mTop;
}

char& CharStack::top()
{
    if (isEmpty())
    {
        cerr << "Stack is empty! No bueno!\n";
        exit(-1);
    }

    return mStackArray[mTop - 1];
}

bool CharStack::isEmpty() const
{
    return mTop == 0;
}

bool CharStack::isFull() const
{
    return mTop == mCapacity;
}
