#include <iostream>

#include "myVector.h"
using namespace std;

void printVector(Vector& vec);

int main()
{
    Vector v;

    for (int i = 0; i < 5; ++i)
        v.push_back("Hello");

    cout << "Vector size : " << v.size() << '\n';
    cout << "Vector capacity : " << v.capacity() << '\n';
    printVector(v);
    return 0;
}

void printVector(Vector& vec)
{
    cout << "Vector elements : ";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}