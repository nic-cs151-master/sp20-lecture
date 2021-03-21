#include "rectangle.h"

Rectangle::Rectangle()
{
    length = 0.0;
    width = 0.0;
}

Rectangle::Rectangle(float length, float width)
{
    this->length = length;
    this->width = width;
}

float Rectangle::getLength() const
{
    return length;
}

float Rectangle::getWidth() const
{
    return width;
}

float Rectangle::getArea() const
{
    return length * width;
}

// Friends of Rectangle
bool operator<(Rectangle left, Rectangle right)
{
    return (left.getArea() < right.getArea());
}

bool operator>(Rectangle left, Rectangle right)
{
    return (left.getArea() > right.getArea());
}

bool operator==(Rectangle left, Rectangle right)
{
    return (left.getArea() == right.getArea());
}

ostream& operator<<(ostream& os, const Rectangle& data)
{
    os << data.length << ' ' << data.width;
    return os;
}

istream& operator>>(istream& is, Rectangle& data)
{
    cout << "Enter length: ";
    is >> data.length;
    cout << "Enter width: ";
    is >> data.width;
    return is;
}
