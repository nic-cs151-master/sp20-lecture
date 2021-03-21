#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String();
    String(const char* s);
    String(const String& str); // copy constructor
    ~String();                 // destructor

    String& str(const char* s);
    String& str(const String& str);

    String& operator=(const char* s);
    String& operator=(const String& str);

    // Searches the string for the first occurrence of the sequence 
    // specified by its arguments. Returns the starting index where
    // the string is found. If not found, return -1.
    int find(const char* s);
    int find(const String& str);

    // The substring is the portion of the object that starts at 
    // character position pos and spans len characters 
    // (or until the end of the String, whichever comes first).
    // len = -1 indicates all characters until the end of the String
    String substr(int pos=0, int len=-1);

    // Returns a pointer to an array that contains a null-terminated 
    // sequence of characters (i.e., a C-string) representing the 
    // current value of the string object.
    const char* c_str() const;

    // Get character in String
    char& at(int index);

    char& operator[](int index);

    // Return the length of String
    int size() const;

    // Return the length of String
    int length() const;

    // Erases the contents of the string, 
    // which becomes an empty string (with a length of 0 characters).
    void clear();

    // String& append(const char* s);
    // String& append(const String& str);
    // String& append(const char* s, int n);
    // String& append(const String& str, int subpos, int sublen);

    friend ostream& operator<<(ostream &os, const String &str);
    friend istream& operator>>(istream &is, String &str);

private:
    char* m_string;
    int m_size;

};

ostream& operator<<(ostream &os, const String &str);
istream& operator>>(istream &is, String &str);

#endif