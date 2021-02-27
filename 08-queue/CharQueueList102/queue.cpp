#include "queue.h"

void Queue::enqueue(char x)
{
    // queue is empty
    if (isEmpty())
    {
        mFront = mRear = new Node(x);
    }
    // otherwise
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

    Node *temp = mFront;
    mFront = mFront->next;
    temp->next = nullptr; // fully isolate
    delete temp;
    temp = nullptr;
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

Queue::Queue()
{
    mFront = nullptr;
    mRear = nullptr;
    mSize = 0;
}
  
Queue::~Queue()
{

}
