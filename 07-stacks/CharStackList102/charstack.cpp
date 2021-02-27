#include "charstack.h"

CharStack::CharStack()
{
    mTop = nullptr; // empty list
    mSize = 0; // no elements
}

CharStack::~CharStack()
{
    // Two approaches
    // 1: traverse link linked list
    while (mTop != nullptr)
    {
        Node *temp = mTop;
        mTop = mTop->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    // 2: ???
    // while (!isEmpty())
    // {
    //     pop();
    // }
}


void CharStack::push(char x)
{
    mTop = new Node(x, mTop);
}

void CharStack::pop()
{
    if (isEmpty())
    {
        cerr << "Stack is empty!\n";
        return;
    }

    Node *temp = mTop;
    mTop = mTop->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
}

char& CharStack::top()
{
    if (isEmpty())
    {
        cerr << "Stack is empty!\n";
        exit(-1);
    }

    return mTop->data;
}

bool CharStack::isEmpty() const
{
    return mTop == nullptr; // mSize == 0
}


