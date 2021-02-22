#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    double value;
    Node *next;
    Node(double val=0.0, Node *p=nullptr)
    {
        value = val;
        next = p;
    }
};

class LinkedList
{
public:
    LinkedList();                  // default constructor
    ~LinkedList();                 // destructor
    void addFront(double number);
    void add(double number);       // default add action end
    void remove(double number);
    string toString() const;
    string toStringR() const;      // recursive
    unsigned int size() const;
    unsigned int sizeR() const;    // recursive

protected:
    // member variables
    Node *mHead;                   // list head pointer
    // ListNode *mTail;
    unsigned int mSize;            // size of the list

private:
    // helper functions
    string toStringR(Node *ptr, ostringstream &ostr) const;
};


#endif