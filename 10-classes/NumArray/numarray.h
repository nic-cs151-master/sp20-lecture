#ifndef NUMARRAY_H
#define NUMARRAY_H

class NumberArray
{
public:
    NumberArray(int size=0, double initValue=0); // default constructor
    // TODO: Create Copy Constructor
    NumberArray(const NumberArray &obj);

    ~NumberArray() 
    { 
        if (arraySize > 0) 
            delete [] arr; 
    }

    void print() const;
    void setValue(int index, double value);

private:
    double *arr; // dynamic array
    int arraySize;
};

#endif