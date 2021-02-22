#include "linkedlist.h"

LinkedList::LinkedList()
{
    // setting up / initialization
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
    // list is empty
    if (mHead == nullptr)
    {
        mHead = new Node(number);
    }
    // not empty
    else
    {
        // traverse to get to the last node
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
    // list is empty
    if (mHead == nullptr)
    {
        return "";
    }
    // not empty
    ostringstream out;
    Node *ptr = mHead;
    while (ptr != nullptr)
    {
        out << ptr->value << ' ';
        ptr = ptr->next;
    }
    return out.str();
}

unsigned int LinkedList::size() const
{
    return mSize;
}

void LinkedList::remove(double number)
{
    // list is empty
    if (mHead == nullptr)
    {
        return;
    }
    
    // empty
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

    // doesn't exist 
    if (curPtr == nullptr)
    {
        return;
    }
    // does exist at first node
    else if (curPtr == prevPtr)
    {
        mHead = mHead->next;
        curPtr->next = nullptr;
        delete curPtr;
        curPtr = prevPtr = nullptr;
        --mSize;
    }
    else // exist after first node
    {
        prevPtr->next = curPtr->next;
        curPtr->next = nullptr;
        delete curPtr;
        curPtr = prevPtr = nullptr;
        --mSize;
    }
}

string LinkedList::toStringR() const
{
    ostringstream ostr("");
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