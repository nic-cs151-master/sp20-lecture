#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream> // ostream, istream
using namespace std;

class Rectangle
{
public:
    Rectangle();                           // default constructor
    Rectangle(float length, float width);  // programmer-defined constructor

    float getLength() const;
    float getWidth() const;
    float getArea() const;

    friend bool operator<(Rectangle left, Rectangle right);
    friend bool operator>(Rectangle left, Rectangle right);
    friend bool operator==(Rectangle left, Rectangle right);

    friend ostream& operator<<(ostream& os, const Rectangle& data);
    friend istream& operator>>(istream& is, Rectangle& data);

private:
    float length;
    float width;
};

#endif