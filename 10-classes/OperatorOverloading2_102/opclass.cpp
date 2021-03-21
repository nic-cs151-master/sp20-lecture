#include "opclass.h"

OpClass::OpClass()
{
    this->x = 0;
    this->y = 0;
    this->z = new int;
    *z = 0;
}

OpClass::~OpClass()
{
    delete z;
}

OpClass::OpClass(int x)
{
    this->x = x;
    this->y = 0;
    this->z = new int;
    *(this->z) = 0;
}

OpClass::OpClass(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = new int;
    *(this->z) = z;
}

int OpClass::getX() const
{
    return x;
}

int OpClass::getY() const
{
    return y;
}

int OpClass::getZ() const
{
    return *z;
}

OpClass::OpClass(const OpClass &obj)
{
    cout << "Copy constructer called\n";
    this->x = obj.x;
    this->y = obj.y;
    this->z = new int;
    *(this->z) = *(obj.z);
}

OpClass& OpClass::operator=(const OpClass &obj)
{
    cout << "Overloaded assignment operator called\n";
    if (this != &obj)
    {
        this->x = obj.x;
        this->y = obj.y;
        *(this->z) = *(obj.z);
    }
    return *this;
}