#include "myString.h"

String::String()
{
    m_string = new char[1];
    m_string[0] = '\0';
    m_size = 0;
}

String::String(const char* s)
{
    m_size = strlen(s);
    m_string = new char[m_size + 1];
    strcpy(m_string, s);
}

String::String(const String& str)
{
    m_size = str.m_size;
    m_string = new char[m_size + 1];
    strcpy(m_string, str.m_string);
}

String& String::str(const char* s)
{
    if (m_size > 0)
    {
        delete [] m_string;
    }
    m_size = strlen(s);
    m_string = new char[m_size + 1];
    strcpy(m_string, s);
    return *this;
}

String& String::operator=(const char* s)
{
    if (m_size > 0)
    {
        delete [] m_string;
    }
    m_size = strlen(s);
    m_string = new char[m_size + 1];
    strcpy(m_string, s);
    return *this;
}

String& String::str(const String& str)
{
    if (m_size > 0)
    {
        delete [] m_string;
    }
    m_size = str.m_size;
    m_string = new char[m_size + 1];
    strcpy(m_string, str.m_string);
    return *this;
}

String& String::operator=(const String& str)
{
    if (m_size > 0)
    {
        delete [] m_string;
    }
    m_size = str.m_size;
    m_string = new char[m_size + 1];
    strcpy(m_string, str.m_string);
    return *this;
}

int String::find(const char* s)
{
    int indexFound = -1;
    int searchIndex = 0;
    int lengthStr = strlen(s);
    bool isFound = false;

    int i = 0;
    while (i < m_size)
    {
        if (s[searchIndex] == m_string[i])
        {
            isFound = true;
            indexFound = i;
            int finalIndex = lengthStr + i;
            ++searchIndex;
            int j = i + 1;
            while (j < finalIndex)
            {
                if (s[searchIndex] != m_string[j])
                {
                    isFound = false;
                    break;
                }
                ++j;
                ++searchIndex;
            }

            if (isFound)
            {
                break;
            }

            searchIndex = 0;
            indexFound = -1;
            i = j;
        }
        else
        {
            ++i;
        }
    }
    return indexFound;
}

int String::find(const String& str)
{
    return find(str.m_string);
}

String String::substr(int pos, int len)
{
    if (len == -1)
    {
        // entire length of the string starting at pos
        len = m_size;
    }
    else
    {
        len += pos;
    }

    char* str = new char[(len - pos) - 1];
    int i = 0;
    while (pos < len)
    {
        str[i] = m_string[pos];
        ++pos;
        ++i;
    }
    str[i] = '\0';
    String s(str);
    delete [] str;
    return s;
}

char& String::operator[](int index)
{
    return m_string[index];
}

char& String::at(int index)
{
    return m_string[index];
}

const char* String::c_str() const
{
    return m_string;
}

int String::size() const
{
    return m_size;
}

int String::length() const
{
    return m_size;
}

void String::clear()
{
    if (m_string != nullptr)
    {
        delete [] m_string;
    }
    m_string = new char[1];
    m_string[0] = '\0';
    m_size = 0;
}

String::~String()
{
    delete [] m_string;
}

ostream& operator<<(ostream &os, const String &str)
{
    os << str.m_string;
    return os;
}

istream& operator>>(istream &is, String &str)
{
    char array[500];
    is >> array;
    String str2 = array;
    str = str2;

    return is;
}