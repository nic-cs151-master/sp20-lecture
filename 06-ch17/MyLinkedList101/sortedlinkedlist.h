/**
 * @file sortedlinkedlist.h
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Definiton file for the SortedLinkedList class
 * @version 0.1
 * @date 2021-02-19
 * 
 */
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "linkedlist.h"

// taste of inheritance
class SortedLinkedList : public LinkedList
{
public:
    void add(double number);
};

#endif