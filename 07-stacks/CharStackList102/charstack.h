#ifndef CHAR_STACK
#define CHAR_STACK

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char d='\0', Node *n=nullptr)
    {
        data = d;
        next = n;
    }
};

class CharStack
{
public:
    CharStack();
    ~CharStack();

    void push(char x);
    void pop();
    char& top();
    bool isEmpty() const;

private:
    Node *mTop;  // for the array
    int mSize;
};

#endif