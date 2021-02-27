#include "queue.h"

void Queue::enqueue(char x)
{
    if (isFull())
    {
        throw std::range_error("Queue is full!\n");
    }

    // mRear = -1
    mRear = (mRear + 1) % mCapacity;
    mQueue[mRear] = x;
    ++mSize;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!\n");
    }

    // mFront = -1
    mFront = (mFront + 1) % mCapacity;
    --mSize;
}

char& Queue::front()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!\n");
    }

    return mQueue[(mFront + 1) % mCapacity];
}

char& Queue::back()
{
    if (isEmpty())
    {
        throw std::range_error("Queue is empty!\n");
    }

    return mQueue[mRear];
}

bool Queue::isEmpty() const
{
    return mSize == 0;
}

bool Queue::isFull() const
{
    return mCapacity == mSize;
}

Queue::Queue(int queueSize)
{
    mQueue = new char[queueSize];
    mCapacity = queueSize;
    mSize = 0;
    mFront = -1;
    mRear = -1;
}
  
Queue::~Queue()
{
    delete [] mQueue;
}
