#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdexcept> // std::out_of_range
#include <string>
#include <sstream>
#include <utility> // std::swap()

// Design choices: binary heap static or can increase in size???

class MinHeap
{
public:
    MinHeap(int capacity=10);

    int getMin() const;   // returns the minimum key (key at root)
    int extractMin();     // extract the root which is the minimum element
    void insert(int key); // inserts a new key

    std::string toString() const;

private:
    int *mHeapArray; // pointer to array of elements in heap
    int mCapacity;   // maximum possible size of min heap
    int mSize;       // current number of elements in min heap

    void heapify(int i); // to heapify a subtree with the root at given index

    int parent(int i);  // returns index of the parent of node at index i
    int left(int i);    // returns index of the left child of node at index i
    int right(int i);   // returns index of the right child of node at index i
};

#endif