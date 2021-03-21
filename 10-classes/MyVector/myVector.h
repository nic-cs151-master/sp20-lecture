#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cstdlib>
// #include <string>
#include "../MyString/myString.h"
using namespace std;

class Vector
{
public: 
    // Default constructor to initialize 
    // an initial capacity of 1 element and 
    // allocating storage using dynamic allocation 
    Vector();
  
    // Adds an element to the end
    void push_back(String data);

    // Updates element at any index that
    // works like the [] operator
    void set(int index, String data);

    // function to extract element at any index 
    String& at(int index);
    String& operator[](int index);

    // Removes the last element
    void pop_back();

    // Returns the number of elements
    int size() const;

    // Returns the number of elements that 
    // can be held in currently allocated storage
    int capacity() const;

private:
    // string pointer that points 
    // to a dynamically allocated array
    // that holds the elements of the vector
    String* m_elements;

    // tracks the number of elements 
    // currently present in the vector 
    int m_size; 

    // capacity is the total storage 
    // capacity of the vector 
    int m_capacity; 
}; 

#endif