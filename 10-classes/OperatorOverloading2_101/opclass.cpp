#include "opclass.h"


OpClass::OpClass(const OpClass &obj)
{
    cout << "Copy constructor called\n";
    this->x = obj.x;
    this->y = obj.y;
    this->z = new int;
    *(this->z) = *(obj.z);
}

OpClass& OpClass::operator=(const OpClass& r)
{
    cout << "Assignment overload called\n";
    if (this != &r)
    {
        this->x = r.x;
        this->y = r.y;
        this->z = new int;
        *(this->z) = *(r.z);
    }

    // return?
    return *this;
}

void OpClass::setXYZ(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    *(this->z) = z;
}

OpClass::OpClass()
{
    this->z = new int;
    this->setXYZ(0, 0, 0);
}

OpClass::~OpClass()
{
    delete z;
}

OpClass::OpClass(int x)
{
    this->z = new int;
    this->setXYZ(x, 0, 0);
    // this->x = x;
    // this->y = 0;
    // this->z = new int;
    // *(this->z) = 0;
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