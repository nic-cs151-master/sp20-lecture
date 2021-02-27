#include "queue.h"

Queue::Queue()
{
    // Node *mFront;  // for the array
    // Node *mRear;
    // int mSize;
    mFront = mRear = nullptr;
    mSize = 0;
}
  
Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

void Queue::enqueue(char x)
{
    // queue is empty
    if (mRear == nullptr)
    {
        mFront = mRear = new Node(x);
    }
    // not empty
    else
    {
        mRear->next = new Node(x);
        mRear = mRear->next;
    }
    ++mSize;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!");
    }

    Node *ptr = mFront;
    mFront = mFront->next;
    ptr->next = nullptr; // fully isolate
    delete ptr;
    ptr = nullptr;
    --mSize;

    if (mSize == 0)
    {
        mRear = nullptr;
    }
}

char& Queue::front()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!");
    }

    return mFront->data;
}

char& Queue::back()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!");
    }

    return mRear->data;
}

bool Queue::isEmpty() const
{
    return mSize == 0;
}