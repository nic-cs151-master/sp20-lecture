/**
 * @file sortedlinkedlist.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Implementation file for the SortedLinkedList class
 * @version 0.1
 * @date 2021-02-19
 * 
 */
#include "sortedlinkedlist.h"

void SortedLinkedList::add(double number)
{
    if (mHead == nullptr || mHead->value > number)
    {
        mHead = new Node(number, mHead);
    }
    else
    {
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

        // Add item at the end
        if (curPtr == nullptr)
        {
            prevPtr->next = new Node(number);
        }
        else
        {
            prevPtr->next = new Node(number, prevPtr->next);
        }
    }
    ++mSize;
}