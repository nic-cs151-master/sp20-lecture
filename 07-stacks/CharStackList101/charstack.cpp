#include "charstack.h"

CharStack::CharStack()
{
    mTop = nullptr;
    mSize = 0;
}

CharStack::~CharStack()
{    
    // Two approaches
    // 1: traverse like linked list
    // while (mTop != nullptr)
    // {
    //     Node *temp = mTop;
    //     mTop = mTop->next;
    //     temp->next = nullptr;
    //     delete temp;
    //     temp = nullptr;
    // }

    // 2: ???
    while (!isEmpty())
    {
        pop();
    }
}


void CharStack::push(char x)
{
    mTop = new Node(x, mTop);
    ++mSize;
}

void CharStack::pop()
{
    if (isEmpty())
    {
        cerr << "Stack is empty!";
        return;
    }

    Node *temp = mTop;
    mTop = mTop->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
    --mSize;
}

char& CharStack::top()
{
    if (isEmpty())
    {
        cerr << "Stack is empty!";
        exit(-1);
    }

    return mTop->data;
}

bool CharStack::isEmpty() const
{
    return mTop == nullptr;
}