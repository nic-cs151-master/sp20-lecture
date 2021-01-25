#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::istringstream;
using std::endl;

int getInteger(const string& prompt, const string& reprompt);
double getDouble(const string& prompt, const string& reprompt);

int main()
{
    int x = getInteger("Enter number: ", "Invalid: ");
    cout << x << '\n';

    double y = getDouble("Enter number: ", "Invalid: ");
    cout << y << '\n';
    
    return 0;
}

int getInteger(const string& prompt, const string& reprompt) 
{
    string promptCopy = prompt;
    int value = 0;
    while (true) 
    {
        cout << prompt;

        string line;
        if (!getline(cin, line)) 
        {
            cerr << "getInteger: End of input reached while waiting for integer value.";
        }

        // TODO: trim for leading and trailing whitespaces

        istringstream stream(line);
        stream >> value;
        if (!stream.fail() && stream.eof()) 
        {
            break;
        }

        cerr << reprompt;
    }
    return value;
}

double getDouble(const string& prompt, const string& reprompt) 
{
    string promptCopy = prompt;
    double value = 0;
    while (true) 
    {
        cout << prompt;

        string line;
        if (!getline(cin, line)) 
        {
            cerr << "getDouble: End of input reached while waiting for integer value.";
        }
        
        // TODO: trim for leading and trailing whitespaces

        istringstream stream(line);
        stream >> value;
        if (!stream.fail() && stream.eof()) 
        {
            break;
        }

        cerr << reprompt;
    }
    return value;
}