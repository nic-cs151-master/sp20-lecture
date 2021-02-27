#ifndef CHAR_STACK
#define CHAR_STACK

#include <iostream>
#include <cstdlib>
using namespace std;

class CharStack
{
public:
    // CharStack();
    CharStack(int stackSize=10);  
    ~CharStack();

    void push(char x);
    void pop();
    char& top();
    bool isEmpty() const;
    bool isFull() const;

private:
    char *mStackArray;  // for the array
    int mCapacity, mTop;
};

#endif