#include "linkedlist.h"

LinkedList::LinkedList()
{
    // setup/initialization
    mHead = nullptr; // empty list
    mSize = 0;
}

LinkedList::~LinkedList()
{
    while (mHead != nullptr)
    {
        Node *temp = mHead;
        mHead = mHead->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }
}

void LinkedList::add(double number)
{
    if (mHead == nullptr)
    {
        mHead = new Node(number);
    }
    else
    {
        Node *ptr = mHead;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = new Node(number);
    }

    ++mSize;
}

string LinkedList::toString() const
{
    if (mHead == nullptr)
    {
        return "";
    }

    ostringstream ostr;
    Node *ptr = mHead;
    while (ptr != nullptr)
    {
        ostr << ptr->value << ' ';
        ptr = ptr->next; // make ptr point to the next node
    }

    return ostr.str();
}

unsigned int LinkedList::size() const
{
    return mSize;
}

void LinkedList::remove(double number)
{
    if (mHead == nullptr)
    {
        return;
    }

    Node *curPtr = mHead;
    Node *prevPtr = mHead;
    while (curPtr != nullptr)
    {
        if (curPtr->value == number)
        {
            break;
        }
        prevPtr = curPtr;
        curPtr = curPtr->next;
    }

    // Item not found
    if (curPtr == nullptr)
    {
        return;
    }
    // If the node we are deleting is the first node
    else if (curPtr == prevPtr)
    {
        mHead = mHead->next;
        curPtr->next = nullptr; // isolated
        delete curPtr;
        curPtr = prevPtr = nullptr;
        --mSize;
    }
    else
    {
        prevPtr->next = curPtr->next;
        curPtr->next = nullptr; // isolated
        delete curPtr;
        curPtr = prevPtr = nullptr;
        --mSize;
    }
}

string LinkedList::toStringR() const
{
    ostringstream ostr(""); // initialize to empty string
    return toStringR(mHead, ostr);
}

string LinkedList::toStringR(Node *ptr, ostringstream &ostr) const
{
    if (ptr == nullptr)
    {
        return ostr.str();
    }
    
    ostr << ptr->value << ' ';
    return toStringR(ptr->next, ostr);
}
