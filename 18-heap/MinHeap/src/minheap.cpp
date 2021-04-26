#include "minheap.h"

MinHeap::MinHeap(int capacity)
{
    mCapacity = capacity;
    mSize = 0;
    mHeapArray = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] mHeapArray;
}

int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}

int MinHeap::left(int i)
{
    return (2 * i ) + 1;
}

int MinHeap::right(int i)
{
    return (2 * i ) + 2;
}

void MinHeap::insert(int key)
{
    // heap full?
    if (mSize == mCapacity)
    {
        throw std::runtime_error("insert(): heap is full");
    }

    // Insert the key at the end
    mHeapArray[mSize] = key;
    ++mSize;

    // fix the min heap property if it is violated
    int index = mSize - 1;
    while (index != 0 && mHeapArray[index] < mHeapArray[parent(index)])
    {
        std::swap(mHeapArray[index], mHeapArray[parent(index)]);
        index = parent(index);
    }
}

int MinHeap::getMin() const
{
    if (mSize == 0)
    {
        throw std::runtime_error("getMine(): heap is empty");
    }

    return mHeapArray[0];
}

int MinHeap::extractMin()
{
    if (mSize == 0)
    {
        throw std::runtime_error("getMine(): heap is empty");
    }

    // if there is only one time in heap
    if (mSize == 1)
    {
        --mSize;
        return mHeapArray[0];
    }

    // store the minimum value in temp variable
    int root = mHeapArray[0];

    // swap the root with last value in the array
    mHeapArray[0] = mHeapArray[mSize - 1];
    --mSize;

    heapify(0);
    return root;
}

void MinHeap::heapify(int i)
{
    int leftIndex = left(i);
    int rightIndex = right(i);

    // assume the i has the smallest value
    int smallestIndex = i;

    // compare with left index value
    if (leftIndex < mSize &&  mHeapArray[leftIndex] < mHeapArray[smallestIndex])
    {
        smallestIndex = leftIndex;
    }

    // compare the right index with the smallest index
    if (rightIndex < mSize && mHeapArray[rightIndex] < mHeapArray[smallestIndex])
    {
        smallestIndex = rightIndex;
    }

    // only swap if ith index is no longer the smallest
    if (smallestIndex != i)
    {
        std::swap(mHeapArray[i], mHeapArray[smallestIndex]);
        heapify(smallestIndex);
    }
}

std::string MinHeap::toString() const
{
    std::ostringstream ostr;
    for (int i = 0; i < mSize; ++i)
    {
        ostr << mHeapArray[i] << ' ';
    }
    return ostr.str();
}

