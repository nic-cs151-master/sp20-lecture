#include "tfaculty.h"

TFaculty::TFaculty(const string &name, Discipline d, const string &title) 
    : Faculty(name, d), mTitle(title)
{
    cout << "TFaculty constructor called\n";
}

void TFaculty::setTitle(const string &title)
{
    mTitle = title;
}

string TFaculty::getName() const
{
    return mTitle + " " + mName;
}