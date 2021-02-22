#include "sortedlinkedlist.h"

void SortedLinkedList::add(double number)
{
    if (mHead == nullptr || mHead->value > number)
    {
        mHead = new Node(number, mHead);
    }
    else
    {
        // empty
        Node *curPtr = mHead;
        Node *prevPtr = mHead;

        while (curPtr != nullptr)
        {
            if (curPtr->value > number)
            {
                break;
            }
            prevPtr = curPtr;
            curPtr = curPtr->next;
        }

        // adding node at the end
        if (curPtr == nullptr)
        {
            prevPtr->next = new Node(number);
        }
        else // exist after first node
        {
            prevPtr->next = new Node(number, curPtr);
        }
    }
    ++mSize;
}