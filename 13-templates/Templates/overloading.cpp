#include "overloading.h"


void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap(long& x, long& y)
{
    long temp = x;
    x = y;
    y = temp;
}
// how about unsigned

void swap(float& x, float& y)
{
    float temp = x;
    x = y;
    y = temp;
}

void swap(double& x, double& y)
{
    double temp = x;
    x = y;
    y = temp;
}

void swap(string& x, string& y)
{
    string temp = x;
    x = y;
    y = temp;
}

void swap(Person& x, Person& y)
{
    Person temp = x;
    x = y;
    y = temp;
}