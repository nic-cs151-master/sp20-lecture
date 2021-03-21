#ifndef TFACULTY_H
#define TFACULTY_H

#include <string>
#include "faculty.h"
using namespace std;

// function overloading
// function overriding

class TFaculty : public Faculty
{
public:
    TFaculty(const string &name, Discipline d, const string &title);

    void setTitle(const string &title);
    string getName() const; // function overriding

private:
    string mTitle;
};

#endif