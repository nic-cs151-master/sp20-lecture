#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{
    cout << "This program was called with " << argc << " arguments\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << '\n';
}
