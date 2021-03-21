#include <iostream>
using namespace std; 

class NumberArray
{
public:
    NumberArray(int size, double value);
    ~NumberArray();
    // Commented out to avoid problems with the 
    // default copy constructor
    void print() const;
    void setValue(double value);

private:
    double *aPtr;
    int arraySize;
};