/**
 * @file student.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Student Class definition
 * @version 0.1
 * @date 2021-01-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"

Student::Student() // default constructor
{
    // initializing the member variables
    // setup default values
    mName = ""; // empty string
    mId = 0;
    mAge = 0;
}

Student::~Student() // destructor
{
    // nothing for now
}

// all member functions that doesn't modify any of the member variables 
// should be a constant function

// getters
string Student::getName() const
{
    return mName;
}

int Student::getId() const
{
    return mId;
}

int Student::getAge() const
{
    return mAge;
}

// setters
void Student::set(string name, int id, int age)
{
    setName(name);
    setId(id);
    setAge(age);
}

void Student::setName(string name)
{
    mName = name;
}

void Student::setId(int id)
{
    // 0 to 99999
    if (id < 0 && id > 99999)
    {
        cout << "Invalid value!\n";
        mId = 0;
        return;
    }
    mId = id;
}

void Student::setAge(int age)
{
    mAge = age;
}



/**
 * @brief 
 * 
 * @param arr 
 * @param size 
 */
void displayStudents(const Student arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i].getName() << ' ' 
             << arr[i].getId() << ' ' 
             << arr[i].getAge() << '\n';
    }
}