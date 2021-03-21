#include <iostream>
using namespace std;

class Base
{
public:
    int x;

    void setZ(int z)
    {
        this->z = z;
    }

    void print()
    {
        cout << x << ' ' << y << ' ' << z << endl;
    }

protected:
    int y;
private:
    int z;
};

class Child1 : public Base
{
public:
    Child1()
    {
        x = 1;
        y = 2;
        // z = 3; // z CANNOT be accessed directly
    }
};

class Child2 : protected Base
{
public:
    Child2()
    {
        x = 1;
        y = 2;
        // z = 3; // z CANNOT be accessed directly
    }
};

class Child3 : private Base
{
public:
    Child3()
    {
        x = 1;
        y = 2;
        // z = 3; // z CANNOT be accessed directly
    }
};

int main()
{
    Base b;
    b.x = 20;

    Child1 a;
    a.x = 30;

    // Child2 c;
    // c.x = 5;

    return 0;
}