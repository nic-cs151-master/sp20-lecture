#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Queue
{
public:
    void enqueue(char x);
    void dequeue();
    char& front();
    char& back();
    bool isEmpty() const;
    bool isFull() const;
    Queue(int queueSize=5);  
    ~Queue();

private:
    char *mQueue;  // for the array
    int mCapacity, mFront, mRear, mSize;
};

#endif