#include <iostream>
using namespace std;

class CCClass
{
public:
    CCClass()           //default
    CCClass(int a, int b);
    CCClass(int a);     //convert
    CCClass(string s);  //convert

private:
    int x;
};

CCClass::CCClass()
{
    x = 0;
}

CCClass::CCClass(int a, int b)
{
    x = a + b;
}

CCClass::CCClass(int a)
{
    x = a;
}

CCClass::CCClass(string s)
{
    istringstream istr(s);
    istr >> x;
}




int main()
{
    CCClass a;
    CCClass b(5, 6);
    CCClass c = "24"; // CCClass c("24")
    CCClass d = 24;  // CCClass d(24)

    return 0;
}