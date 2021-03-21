#include "myVector.h"

// Default constructor to initialize 
// an initial capacity of 1 element and 
// allocating storage using dynamic allocation 
Vector::Vector()
{
    // Assign a dynamic array with a size of 1 to m_elements
    m_elements = new String[1];
    // Vector will have initial capacity of 1
    m_capacity = 1;
    // Initial value of m_size is 0
    m_size = 0;
}

// Adds an element to the end
void Vector::push_back(String data)
{
    // If the number of elements (m_size) is equal to 
    // the capacity, this means we don’t have enough 
    // space to accommodate more elements, thus before 
    // we can add, you need to increase the capacity of 
    // the vector (m_elements)
    if (m_size == m_capacity)
    {
        // Simply double the capacity
        m_capacity *= 2; // m_capacity = m_capacity * 2;

        // Create a temporary pointer variable pointing 
        // to a dynamically allocated array with double 
        // the current capacity
        String* temp = new String[m_capacity];

        // Copy the existing elements in the vector 
        // into the newly created temporary array
        for (int i = 0; i < m_size; ++i)
        {
            temp[i] = m_elements[i];
        }

        // Free the memory of the previous or old array
        delete [] m_elements;

        // Assign the temporary array as the new vector
        m_elements = temp;

    }

    // Add data at the end of the vector
    m_elements[m_size] = data;
    ++m_size;

}

// Updates element at any index that
// works like the [] operator
void Vector::set(int index, String data)
{
    // Only update the vector if index passed is within the current size of the vector
    // If the index passed is invalid, prompt the user with an error and exit the program
    if (index < 0 || index >= m_size)
    {
        cout << "index=" << index << " out of bounds, exiting\n";
        exit(0);
    }
    // Otherwise, assign the data to the correct index in the vector
    m_elements[index] = data;
}

// function to extract element at any index 
String& Vector::at(int index)
{
    if (index < 0 || index >= m_size)
    {
        cout << "index=" << index << " out of bounds, exiting\n";
        exit(0);
    }
    return m_elements[index];
}

String& operator[](int index)
{
    return at(index);
}

// Removes the last element
void Vector::pop_back()
{
    --m_size;
}

// Returns the number of elements
int Vector::size() const
{
    return m_size;
}

// Returns the number of elements that 
// can be held in currently allocated storage
int Vector::capacity() const
{
    return m_capacity;
}