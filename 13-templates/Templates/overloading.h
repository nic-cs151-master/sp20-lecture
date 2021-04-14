#ifndef OVERLOADING_H
#define OVERLOADING_H

#include "person.h"
#include <string>
using std::string;

void swap(int &x, int &y);
void swap(long &x, long &y);
// how about unsigned

void swap(float &x, float &y);
void swap(double &x, double &y);

void swap(string &x, string &y);

void swap(Person &x, Person &y);

#endif