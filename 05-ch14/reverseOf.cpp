#include <iostream>
#include <string>
using namespace std;

string reverseOf(const string &s);

int main()
{
    cout << reverseOf("CS 151 Rocks!");
    return 0;
}

string reverseOf(const string &s)
{
    if (s == "")
    {
        return "";
    }
    else
    {
        return reverseOf(s.substr(1)) + s.substr(0, 1);
    }
}